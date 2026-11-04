/* ============================================================
 * joy_csharp 宿主：C 侧只负责窗口 / 主循环 / 事件泵 / 渲染帧边界，
 * 业务逻辑全部在 C#（JoyGame.dll）。
 *
 * 每帧：r2d_begin → C# Host.OnFrame(dt) → r2d_end
 * 输入：SDL 事件写入 csclib 的输入桥，C# 通过 Joy.Input 轮询
 *
 * 参数：
 *   --smoke N       无窗口冒烟：dummy 视频驱动 + 固定 60Hz 步长，跑 N 帧后退出
 *   --assembly PATH 指定 C# 程序集（默认 JoyGame.dll，相对当前目录）
 * ============================================================ */
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <joy/joy.h>
/* 用相对路径包含本仓头文件：joy 源码树自带的 modules/csharp 也存在同名
 * joy_csharp.h（旧版），靠 include 顺序解析容易拿到错的那个。 */
#include "../joy_csharp.h"
#include "../csclib/csclib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
static Uint64   g_last_tick = 0;
static const char* g_assembly = "JoyGame.dll";

static int find_arg(int argc, char* argv[], const char* name)
{
        for (int i = 1; i < argc; ++i) {
                if (strcmp(argv[i], name) == 0) return i;
        }
        return -1;
}

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
        (void)appstate;

        int i = find_arg(argc, argv, "--smoke");
        if (i >= 0 && i + 1 < argc) g_smoke_frames = atoi(argv[i + 1]);
        i = find_arg(argc, argv, "--assembly");
        if (i >= 0 && i + 1 < argc) g_assembly = argv[i + 1];

        if (g_smoke_frames > 0) {
                /* CI 无桌面会话：dummy 视频 + 软件渲染，保证 CreateWindow/Renderer 可用 */
                SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "dummy");
                SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
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
                fprintf(stderr, "[host] csx_create failed (Mono runtime unavailable?)\n");
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

        printf("[host] mono up, assembly=%s, smoke=%d\n", g_assembly, g_smoke_frames);
        fflush(stdout);
        g_last_tick = SDL_GetTicks();
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
                Uint64 now = SDL_GetTicks();
                dt = (float)(now - g_last_tick) / 1000.0f;
                g_last_tick = now;
                if (dt <= 0.0f) dt = 1.0f / 60.0f;
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
