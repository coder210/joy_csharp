#ifdef ENABLED_CSHARP_SCRIPT
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/appdomain.h>
#include <mono/metadata/class.h>
#include <mono/metadata/object.h>
#include <mono/metadata/threads.h>
#include "joy_csharp.h"
#include "csclib.h"
#include "csclib_generated.h"
#include <joy/joy.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

// 动态数组，存储已加载的程序集
typedef struct assembly_list {
        MonoAssembly** items;
        int count;
        int capacity;
} assembly_list_t, * assembly_list_p;

struct csx {
        MonoDomain* domain;
        MonoThread* thread;           // 主线程 attach 句柄（其它线程见 csx_thread_attach）
        assembly_list_t assemblies;   // 所有已加载的程序集
        void* userdata;
};

/* 缓存下来的静态方法句柄（帧回调等高频路径用） */
struct csx_method {
        MonoMethod* method;
};

// 初始化程序集列表
static void assembly_list_init(assembly_list_p list) 
{
        list->items = NULL;
        list->count = 0;
        list->capacity = 0;
}

// 向列表添加程序集
static void assembly_list_add(assembly_list_p list, MonoAssembly* asm)
{
        if (list->count >= list->capacity) {
                int new_cap = list->capacity == 0 ? 4 : list->capacity * 2;
                list->items = (MonoAssembly**)realloc(list->items, new_cap * sizeof(MonoAssembly*));
                list->capacity = new_cap;
        }
        list->items[list->count++] = asm;
}

// 释放列表内存（不释放程序集本身，程序集由 domain 管理）
static void assembly_list_free(assembly_list_p list)
{
        free(list->items);
        list->items = NULL;
        list->count = list->capacity = 0;
}

/* 判断目录是否存在（Mono 目录探测用，避免依赖平台 API） */
static bool csx_dir_exists(const char* path)
{
        struct stat st;
        if (!path || !path[0]) return false;
        if (stat(path, &st) != 0) return false;
        return (st.st_mode & S_IFDIR) != 0;
}

/* 定位 Mono 安装目录。
 *
 * exe 旁边只带 mono-2.0-sgen.dll 时，Mono 无法反推 mscorlib 的位置，
 * 会出现 "The assembly mscorlib.dll was not found"。这里按
 *   环境变量 MONO_LIB_DIR / MONO_ETC_DIR > 常见安装路径
 * 调 mono_set_dirs 显式指定。找不到就保持 Mono 自己的默认行为。 */
static void csx_setup_mono_dirs(void)
{
        static char lib_buf[512];
        static char etc_buf[512];

        const char* lib = getenv("MONO_LIB_DIR");
        const char* etc = getenv("MONO_ETC_DIR");

        if (!csx_dir_exists(lib)) {
                static const char* candidates[] = {
                        "C:/Program Files/Mono/lib",
                        "C:/Program Files (x86)/Mono/lib",
                        "/usr/lib/mono",
                        "/usr/local/lib/mono",
                };
                lib = NULL;
                for (int i = 0; i < (int)(sizeof(candidates) / sizeof(candidates[0])); ++i) {
                        if (csx_dir_exists(candidates[i])) {
                                snprintf(lib_buf, sizeof(lib_buf), "%s", candidates[i]);
                                lib = lib_buf;
                                break;
                        }
                }
        }

        if (!csx_dir_exists(etc) && lib) {
                /* <install>/lib → <install>/etc */
                snprintf(etc_buf, sizeof(etc_buf), "%s", lib);
                char* slash = strrchr(etc_buf, '/');
                if (slash) {
                        snprintf(slash, sizeof(etc_buf) - (size_t)(slash - etc_buf), "/etc");
                        if (csx_dir_exists(etc_buf)) etc = etc_buf;
                }
        }

        if (lib) {
                mono_set_dirs(lib, csx_dir_exists(etc) ? etc : lib);
        }
}

csx_p csx_create(void) {
        csx_p csx = (csx_p)malloc(sizeof(csx_t));
        assert(csx);
        csx_setup_mono_dirs();
        csx->domain = mono_jit_init("joy");
        if (!csx->domain) {
                log_error("Failed to initialize Mono domain");
                free(csx);
                return NULL;
        }
        /* Mono 要求调用 managed 代码的线程先 attach 到 domain；
         * 主线程在这里 attach，其它工作线程用 csx_thread_attach()。 */
        csx->thread = mono_thread_attach(csx->domain);
        /* 注册 C# → C 的 internal call（utils 手写 + 其余自动生成） */
        csopen_utils();
        csopen_generated();
        /* 手写的 C# 友好层：绘制热点 / 输入状态 / 宿主服务 */
        csopen_draw();
        csopen_input();
        csopen_host();
        assembly_list_init(&csx->assemblies);
        csx->userdata = NULL;
        return csx;
}

bool csx_load_assembly(csx_p csx, const char* filename)
{
        size_t data_size;
        char* assembly_data = utils_read_file(filename, &data_size);
        if (!assembly_data) {
                log_error("Failed to read assembly file: %s", filename);
                return false;
        }

        MonoImageOpenStatus status;
        // 第三个参数 1 表示 Mono 会复制数据，之后我们可以安全释放
        MonoImage* image = mono_image_open_from_data(assembly_data, data_size, 1, &status);
        if (status != MONO_IMAGE_OK || !image) {
                log_error("Failed to open image from data: %s", filename);
                free(assembly_data);
                return false;
        }

        // 从映像加载程序集，并指定简单名称（可选）
        MonoAssembly* assembly = mono_assembly_load_from_full(image, "joy_asm", &status, 0);
        free(assembly_data);  // 数据已被复制，可以释放

        if (!assembly) {
                log_error("Failed to load assembly from image: %s", filename);
                mono_image_close(image);
                return false;
        }

        // 保存程序集到列表
        assembly_list_add(&csx->assemblies, assembly);
        log_info("Loaded assembly: %s", filename);
        return true;
}

MonoClass* 
csx_find_class(csx_p csx, const char* namespace_name, const char* class_name)
{
        MonoClass* klass;
        for (int i = 0; i < csx->assemblies.count; i++) {
                MonoAssembly* asm = csx->assemblies.items[i];
                MonoImage* image = mono_assembly_get_image(asm);
                klass = mono_class_from_name(image, namespace_name, class_name);
                if (klass) {
                        return klass;
                }
        }
        log_error("Class %s.%s not found in any loaded assembly", namespace_name, class_name);
        return NULL;
}

MonoObject* 
csx_invoke_static_method(csx_p csx, const char* namespace_name, 
        const char* class_name, const char* method_name, void** args)
{
        /* 允许任意线程调用：先确保当前线程已 attach（已 attach 时幂等） */
        mono_thread_attach(csx->domain);
        MonoClass* klass = csx_find_class(csx, namespace_name, class_name);
        if (!klass) return NULL;
        /* -1 表示忽略参数数量（简单查找） */
        MonoMethod* method = mono_class_get_method_from_name(klass, method_name, -1);
        if (!method) {
                log_error("Method %s not found in class %s.%s", method_name, namespace_name, class_name);
                return NULL;
        }

        MonoObject* exception = NULL;
        MonoObject* result = mono_runtime_invoke(method, NULL, args, &exception);
        if (exception) {
                MonoString* exc_str = mono_object_to_string(exception, NULL);
                if (exc_str) {
                        char* exc_cstr = mono_string_to_utf8(exc_str);
                        log_error("Exception: %s", exc_cstr);
                        mono_free(exc_cstr);   /* mono_string_to_utf8 的返回值须手动释放 */
                } else {
                        log_error("Exception (unprintable)");
                }
                return NULL;
        }
        return result;
}

csx_method_p csx_find_method(csx_p csx, const char* namespace_name, const char* class_name,
                             const char* method_name, int param_count)
{
        if (!csx) return NULL;
        MonoClass* klass = csx_find_class(csx, namespace_name, class_name);
        if (!klass) return NULL;
        MonoMethod* method = mono_class_get_method_from_name(klass, method_name, param_count);
        if (!method) {
                log_error("Method %s not found in class %s.%s", method_name, namespace_name, class_name);
                return NULL;
        }
        csx_method_p cached = (csx_method_p)malloc(sizeof(csx_method_t));
        if (!cached) return NULL;
        cached->method = method;
        return cached;
}

MonoObject* csx_invoke_method(csx_p csx, csx_method_p method, void** args)
{
        if (!csx || !method || !method->method) return NULL;
        /* 允许任意线程调用：先确保当前线程已 attach（已 attach 时幂等） */
        mono_thread_attach(csx->domain);
        MonoObject* exception = NULL;
        MonoObject* result = mono_runtime_invoke(method->method, NULL, args, &exception);
        if (exception) {
                MonoString* exc_str = mono_object_to_string(exception, NULL);
                if (exc_str) {
                        char* exc_cstr = mono_string_to_utf8(exc_str);
                        log_error("Exception: %s", exc_cstr);
                        mono_free(exc_cstr);
                } else {
                        log_error("Exception (unprintable)");
                }
                return NULL;
        }
        return result;
}

void csx_method_free(csx_method_p method)
{
        free(method);
}

void csx_register_internal_call(const char* name, const void* method) 
{
        mono_add_internal_call(name, method);
}

/* 供工作线程在调用 managed 代码前显式 attach；已 attach 时幂等。
 * csx_invoke_static_method 内部已自动调用，一般无需手动。 */
void csx_thread_attach(csx_p csx)
{
        if (!csx || !csx->domain) return;
        mono_thread_attach(csx->domain);
}

void csx_release(csx_p csx)
{
        if (!csx) return;
        // 程序集会随 domain 卸载自动释放，不需要手动关闭
        assembly_list_free(&csx->assemblies);
        /* mono_jit_cleanup 会卸载 domain 并关闭 JIT；单 domain 场景不要再调
         * mono_domain_unload，否则重复卸载。 */
        mono_jit_cleanup(csx->domain);
        free(csx);
}

#endif // ENABLED_CSHARP_SCRIPT

/*
 * 未启用本模块时的桩实现已统一移到 src/joy_script_stub.c
 * （模块关闭时本文件不参与编译，桩必须由核心侧提供）。
 */
