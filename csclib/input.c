/* C# → joy 胶水层：输入状态桥。
 *
 * 宿主(main.c)持有 SDL 事件循环，把键鼠状态写进本文件；C# 侧通过
 * Joy.Input 的 internal call 轮询。这样 C# 不需要理解 SDL_Event。
 *
 * 注册名格式：Joy.<类>::<方法>，与 C# 侧 [MethodImpl(InternalCall)] 对应。
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <mono/metadata/object.h>
#include "csclib.h"

#define CSX_KEY_COUNT 512
#define CSX_MOUSE_BUTTON_COUNT 8

static bool  s_keys[CSX_KEY_COUNT];
static bool  s_mouse_buttons[CSX_MOUSE_BUTTON_COUNT];
static float s_mouse_x = 0.0f;
static float s_mouse_y = 0.0f;
static float s_wheel = 0.0f;

/* ---------------- 宿主调用 ---------------- */

void csx_input_key(int scancode, bool down)
{
        if (scancode >= 0 && scancode < CSX_KEY_COUNT) {
                s_keys[scancode] = down;
        }
}

void csx_input_mouse_move(float x, float y)
{
        s_mouse_x = x;
        s_mouse_y = y;
}

void csx_input_mouse_button(int button, bool down)
{
        if (button >= 0 && button < CSX_MOUSE_BUTTON_COUNT) {
                s_mouse_buttons[button] = down;
        }
}

void csx_input_wheel(float dy) { s_wheel += dy; }

void csx_input_end_frame(void) { s_wheel = 0.0f; }

/* ---------------- C# 调用 ---------------- */

static bool w_key_down(int scancode)
{
        return (scancode >= 0 && scancode < CSX_KEY_COUNT) ? s_keys[scancode] : false;
}

static bool w_mouse_button(int button)
{
        return (button >= 0 && button < CSX_MOUSE_BUTTON_COUNT) ? s_mouse_buttons[button] : false;
}

static float w_mouse_x(void) { return s_mouse_x; }
static float w_mouse_y(void) { return s_mouse_y; }
static float w_wheel(void)   { return s_wheel; }

void csopen_input(void)
{
        csx_register_internal_call("Joy.Input::key_down", (const void*)w_key_down);
        csx_register_internal_call("Joy.Input::mouse_button", (const void*)w_mouse_button);
        csx_register_internal_call("Joy.Input::mouse_x", (const void*)w_mouse_x);
        csx_register_internal_call("Joy.Input::mouse_y", (const void*)w_mouse_y);
        csx_register_internal_call("Joy.Input::wheel", (const void*)w_wheel);
}
