#ifndef JOY_CSCLIB_H
#define JOY_CSCLIB_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void csopen_sdl(void);
void csopen_kcp(void);
void csopen_math(void);
void csopen_collision(void);
void csopen_sys(void);
void csopen_utils(void);
void csopen_generated(void);

/* ---- 手写的 C# 友好层（标量参数，避免结构体跨 ABI）---- */
void csopen_draw(void);   /* Joy.Draw::*   绘制/文字热点 */
void csopen_input(void);  /* Joy.Input::*  键鼠状态查询 */
void csopen_host(void);   /* Joy.Host::*   日志 / 退出 */

/* ---- 宿主(main.c) → 胶水层的输入桥 ----
 * 宿主每帧把 SDL 事件写入这里，C# 侧通过 Joy.Input 轮询，
 * 因此 C# 不需要接触 SDL 事件结构体。 */
void csx_input_key(int scancode, bool down);
void csx_input_mouse_move(float x, float y);
void csx_input_mouse_button(int button, bool down);
void csx_input_wheel(float dy);
void csx_input_end_frame(void);       /* 每帧末尾清滚动量等一次性状态 */

/* ---- 宿主状态 ---- */
void csx_host_request_quit(void);     /* C# 请求退出主循环 */
bool csx_host_quit_requested(void);
void csx_host_set_exit_code(int code);/* 冒烟失败等场景设置进程退出码 */
int  csx_host_exit_code(void);

#ifdef __cplusplus
}
#endif

#endif // JOY_CSCLIB_H
