#ifndef JOY_CSHARP_H
#define JOY_CSHARP_H

/*
 * joy_csharp —— joy 的可选 C#(Mono) 脚本后端（独立仓库）。
 *
 * 从 joy 核心拆出：只有需要 C# 脚本/程序集驱动引擎的工程才链接本模块；
 * joy 核心本身不依赖本模块，也不需要 Mono。
 *
 * 依赖：
 *   - joy 公共 API：<src/joy.h>
 *   - Mono 开发包：<mono/metadata/*.h>
 */

#include <stdbool.h>

/*
 * Mono 句柄在此只作不透明前置声明：使用方无需安装 Mono 开发包也能包含本头
 * （未启用 C# 脚本时本模块编译为桩实现，这些指针恒为 NULL）。
 */
typedef struct _MonoClass MonoClass;
typedef struct _MonoObject MonoObject;
typedef struct _MonoMethod MonoMethod;
typedef struct csx_method csx_method_t, * csx_method_p;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct csx csx_t, * csx_p;

/* 创建 / 销毁 Mono 运行时句柄 */
csx_p csx_create(void);
void  csx_release(csx_p csx);

/* 从 .dll(程序集) 加载 C# 代码 */
bool csx_load_assembly(csx_p csx, const char* filename);

/* 反射查找类 / 调用静态方法 / 注册内部调用(C# 调用 C 的入口) */
MonoClass*  csx_find_class(csx_p csx, const char* namespace_name, const char* class_name);
MonoObject* csx_invoke_static_method(csx_p csx, const char* namespace_name,
                                     const char* class_name, const char* method_name,
                                     void** args);
void csx_register_internal_call(const char* name, const void* method);

/* ---- 方法句柄缓存 ----
 * 帧回调这类高频调用不要每次走 csx_invoke_static_method（内部要反射查找），
 * 先用 csx_find_method 查一次，之后 csx_invoke_method 直接调。
 * param_count 传 -1 表示忽略参数个数。 */
csx_method_p csx_find_method(csx_p csx, const char* namespace_name, const char* class_name,
                             const char* method_name, int param_count);
MonoObject* csx_invoke_method(csx_p csx, csx_method_p method, void** args);
void csx_method_free(csx_method_p method);

/* 工作线程调用 managed 代码前确保已 attach（幂等；csx_invoke_static_method 内部已自动处理） */
void csx_thread_attach(csx_p csx);

#ifdef __cplusplus
}
#endif
#endif /* JOY_CSHARP_H */
