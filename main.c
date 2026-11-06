/* ============================================================
 * joy_csharp_test 宿主：C 侧只负责窗口 / 主循环 / 事件泵 / 渲染帧边界，
 * 业务逻辑全部在 C#（JoyGame.dll）。
 *
 * 每帧：r2d_begin → C# Host.OnFrame(dt) → r2d_end
 * 输入：SDL 事件写入 csclib 的输入桥，C# 通过 Joy.Input 轮询
 * 帧率：正常模式用 SDL_MAIN_CALLBACK_RATE 把迭代固定在 60Hz，dt 取
 *       SDL_GetTicksNS() 的高精度真实间隔，游戏速度不随帧率变化；
 *       冒烟模式不限制迭代速率，只把 dt 固定成 1/60 以保证断言可复现。
 *
 * 参数：
 *   --smoke N       无窗口冒烟：dummy 视频驱动 + 固定步长，跑 N 帧后退出
 *   --assembly PATH 指定 C# 程序集（默认 JoyGame.dll，相对当前目录）
 * ============================================================ */
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <joy/joy.h>
/* C# 后端只通过 joy_csharp.h 交互：MODULES cs 把 joy/modules/cs
 * 的源码直接编入本 target，本仓不自带绑定层源码。 */
#include "joy_csharp.h"
/* 共享绑定运行层（joy/api）：只在冒烟时跑 C 层自检，不改变业务链路。 */
#include <joy/api/joy_api.h>
/* lua / js 后端的新绑定层（与 cs 同名 Joy.Api.Bindings.*），同样只在冒烟时自检。 */
#include "joy_lua.h"
#include "joy_js.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32)
#include <direct.h>
#else
#include <unistd.h>
#endif

#define APP_TITLE "Joy C# Topdown"
#define APP_W 480
#define APP_H 320

static jwindow_p    g_window = NULL;
static jr2d_p       g_r2d = NULL;
static csx_p        g_csx = NULL;
static csx_method_p g_on_init = NULL;
static csx_method_p g_on_frame = NULL;
static csx_method_p g_on_shutdown = NULL;

static int      g_smoke_frames = 0;
static int      g_frame = 0;
static Uint64   g_last_tick_ns = 0;      /* SDL_GetTicksNS()，纳秒单调时钟 */
static const char* g_assembly = "JoyGame.dll";

static int find_arg(int argc, char* argv[], const char* name)
{
        for (int i = 1; i < argc; ++i) {
                if (strcmp(argv[i], name) == 0) return i;
        }
        return -1;
}

/* 把工作目录切到 exe 所在目录：
 * JoyGame.dll 与 assets/ 都按相对路径加载，这样从任意目录启动（双击、
 * 快捷方式、CI 里在仓库根执行）都能找到资源。 */
static void chdir_to_exe_dir(void)
{
        /* SDL3 的 SDL_GetBasePath 返回 const char*，内存由 SDL 内部缓存管理，
         * 不要 SDL_free（否则退出时堆损坏）。 */
        const char* base = SDL_GetBasePath();
        if (!base) return;
#if defined(_WIN32)
        _chdir(base);
#else
        chdir(base);
#endif
}

/* 仓内 CoreCLR 运行时的 BCL 放在 exe 旁的 lib/。
 * joy 的 csx_setup_mono_dirs() 只认系统 Mono 安装路径或 MONO_LIB_DIR，
 * 因此必须在 csx_create() 之前显式把目录指过去。 */
static void setup_clr_dirs(void)
{
        const char* base = SDL_GetBasePath();
        if (!base) return;
        char lib[512];
        snprintf(lib, sizeof(lib), "%slib", base);
#if defined(_WIN32)
        _putenv_s("MONO_LIB_DIR", lib);
#else
        setenv("MONO_LIB_DIR", lib, 1);
#endif
}

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
        (void)appstate;

        chdir_to_exe_dir();
        setup_clr_dirs();

        int i = find_arg(argc, argv, "--smoke");
        if (i >= 0 && i + 1 < argc) g_smoke_frames = atoi(argv[i + 1]);
        i = find_arg(argc, argv, "--assembly");
        if (i >= 0 && i + 1 < argc) g_assembly = argv[i + 1];

        if (g_smoke_frames > 0) {
                /* P1：共享绑定运行层自检（值容器 / 句柄 / 类型校验 / 自动释放）。
                 * 只跑纯内存的 lcg / ticks API，依赖 joy.idl 里 status:on 的条目。 */
                const char* api_err = joy_api_selftest();
                if (api_err) {
                        fprintf(stderr, "[api] selftest FAILED: %s\n", api_err);
                        return SDL_APP_FAILURE;
                }
                printf("[api] selftest PASS\n");
                {
                        /* 同一份注册表在 lua / js 上的端到端验证：
                         * 调用、句柄创建、参数类型守卫、GC 自动释放。 */
                        const char* lua_err = luax_api_selftest();
                        if (lua_err && strcmp(lua_err, "lua/disabled") == 0) {
                                printf("[api] lua skipped (module off)\n");
                        } else if (lua_err) {
                                fprintf(stderr, "[api] lua selftest FAILED: %s\n", lua_err);
                                return SDL_APP_FAILURE;
                        } else {
                                printf("[api] lua selftest PASS\n");
                        }

                        const char* js_err = jsopen_api_selftest();
                        if (js_err && strcmp(js_err, "js/disabled") == 0) {
                                printf("[api] js skipped (module off)\n");
                        } else if (js_err) {
                                fprintf(stderr, "[api] js selftest FAILED: %s\n", js_err);
                                return SDL_APP_FAILURE;
                        } else {
                                printf("[api] js selftest PASS\n");
                        }
                }
                fflush(stdout);
                /* CI 无桌面会话：dummy 视频 + 软件渲染，保证 CreateWindow/Renderer 可用。
                 * 冒烟不限制迭代速率，让固定步长的 N 帧尽快跑完。 */
                SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "dummy");
                SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
        } else {
                /* r2d_create() 建的 renderer 默认 vsync=0；不设这个 hint 时
                 * SDL_AppIterate 会以尽可能快的速度被调用（几百~上千 FPS）。
                 * "60" = 每秒迭代 60 次；Windows 走 SDL 的 generic main callbacks，
                 * 其 AddHintCallback 会用当前值立即触发一次，因此这里设置有效。 */
                SDL_SetHint(SDL_HINT_MAIN_CALLBACK_RATE, "60");
        }

        g_window = create_window(APP_TITLE, APP_W, APP_H);
        if (!g_window) {
                fprintf(stderr, "[host] create_window failed: %s\n", SDL_GetError());
                return SDL_APP_FAILURE;
        }
        g_r2d = r2d_create(g_window);
        if (!g_r2d) {
                fprintf(stderr, "[host] r2d_create failed: %s\n", SDL_GetError());
                return SDL_APP_FAILURE;
        }
        r2d_set_blend_mode(g_r2d, JR2D_BLEND_BLEND);

        g_csx = csx_create();
        if (!g_csx) {
                fprintf(stderr, "[host] csx_create failed (CLR runtime unavailable?)\n");
                return SDL_APP_FAILURE;
        }
        if (!csx_load_assembly(g_csx, g_assembly)) {
                fprintf(stderr, "[host] load assembly failed: %s\n", g_assembly);
                return SDL_APP_FAILURE;
        }

        g_on_init = csx_find_method(g_csx, "JoyGame", "Host", "OnInit", 5);
        g_on_frame = csx_find_method(g_csx, "JoyGame", "Host", "OnFrame", 1);
        g_on_shutdown = csx_find_method(g_csx, "JoyGame", "Host", "OnShutdown", 0);
        if (!g_on_init || !g_on_frame) {
                fprintf(stderr, "[host] JoyGame.Host.OnInit/OnFrame not found\n");
                return SDL_APP_FAILURE;
        }

        {
                void* win = (void*)g_window;
                void* r2d = (void*)g_r2d;
                int w = APP_W;
                int h = APP_H;
                int smoke = g_smoke_frames;
                void* args[5] = { &win, &r2d, &w, &h, &smoke };
                csx_invoke_method(g_csx, g_on_init, args);
        }

        printf("[host] clr up, assembly=%s, smoke=%d\n", g_assembly, g_smoke_frames);
        fflush(stdout);
        g_last_tick_ns = SDL_GetTicksNS();
        return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* e)
{
        (void)appstate;
        switch (e->type) {
        case SDL_EVENT_KEY_DOWN:
                csx_input_key((int)e->key.scancode, true);
                break;
        case SDL_EVENT_KEY_UP:
                csx_input_key((int)e->key.scancode, false);
                break;
        case SDL_EVENT_MOUSE_MOTION: {
                vec2_t p = r2d_coordinates_from_window(g_r2d, e->motion.x, e->motion.y);
                csx_input_mouse_move(p.x, p.y);
                break;
        }
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
                csx_input_mouse_button((int)e->button.button, true);
                break;
        case SDL_EVENT_MOUSE_BUTTON_UP:
                csx_input_mouse_button((int)e->button.button, false);
                break;
        case SDL_EVENT_MOUSE_WHEEL:
                csx_input_wheel(e->wheel.y);
                break;
        case SDL_EVENT_QUIT:
                return SDL_APP_SUCCESS;
        default:
                break;
        }
        return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
        (void)appstate;

        float dt;
        if (g_smoke_frames > 0) {
                dt = 1.0f / 60.0f;          /* 冒烟用固定步长，结果可复现 */
        } else {
                /* 纳秒精度且不丢余量：SDL_GetTicks() 只有毫秒精度，帧间隔不足 1ms
                 * 时会得到 dt=0；旧代码把 0 兜底成 1/60，等于凭空推进 16.7ms，
                 * 帧率越高，游戏内时间被放大得越厉害（敌人/子弹/伤害全部变快）。 */
                Uint64 now = SDL_GetTicksNS();
                dt = (float)((double)(now - g_last_tick_ns) / (double)SDL_NS_PER_SECOND);
                g_last_tick_ns = now;
                if (dt < 0.0f) dt = 0.0f;   /* dt=0 就是这一帧没有时间推进 */
                if (dt > 0.1f) dt = 0.1f;   /* 断点/窗口拖动后不要一次跳太远 */
        }

        r2d_begin(g_r2d);
        {
                void* args[1] = { &dt };
                csx_invoke_method(g_csx, g_on_frame, args);
        }
        r2d_end(g_r2d);
        csx_input_end_frame();

        g_frame++;
        if (g_smoke_frames > 0 && g_frame >= g_smoke_frames) {
                printf("[host] smoke finished: frames=%d exit=%d\n", g_frame, csx_host_exit_code());
                fflush(stdout);
                return csx_host_exit_code() == 0 ? SDL_APP_SUCCESS : SDL_APP_FAILURE;
        }
        if (csx_host_quit_requested()) {
                return csx_host_exit_code() == 0 ? SDL_APP_SUCCESS : SDL_APP_FAILURE;
        }
        return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
        (void)appstate;
        (void)result;

        if (g_csx && g_on_shutdown) {
                csx_invoke_method(g_csx, g_on_shutdown, NULL);
        }
        if (g_on_init) csx_method_free(g_on_init);
        if (g_on_frame) csx_method_free(g_on_frame);
        if (g_on_shutdown) csx_method_free(g_on_shutdown);
        if (g_csx) csx_release(g_csx);
        if (g_r2d) r2d_destroy(g_r2d);
        if (g_window) destroy_window(g_window);
}
