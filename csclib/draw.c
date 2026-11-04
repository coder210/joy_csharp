/* C# → joy 胶水层：绘制热点。
 *
 * joy 的绘制 API 大量使用 vec2_t / jrect_t / jcolor_t 结构体（按值或指针），
 * 自动生成的绑定只覆盖标量/字符串/不透明指针。这里手写一层"扁平参数"包装，
 * C# 侧只传 float / int / string，避免跨 ABI 传递结构体带来的不确定性。
 *
 * 注册名格式：Joy.<类>::<方法>
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <mono/metadata/object.h>
#include "csclib.h"
#include "joy_csharp.h"
#include <joy/joy.h>

static void set_color(jr2d_p r2d, int r, int g, int b, int a)
{
        r2d_set_colorf(r2d, (float)r / 255.0f, (float)g / 255.0f,
                       (float)b / 255.0f, (float)a / 255.0f);
}

/* 整张图按原尺寸画在 (x, y) */
static void w_draw_image(intptr_t image, float x, float y)
{
        vec2_t pos = { x, y };
        image_draw((image_p)image, pos);
}

/* 取源矩形一块，缩放到目标矩形 */
static void w_draw_image_rect(intptr_t image,
                              float sx, float sy, float sw, float sh,
                              float dx, float dy, float dw, float dh)
{
        jrect_t src = { sx, sy, sw, sh };
        jrect_t dst = { dx, dy, dw, dh };
        image_draw1((image_p)image, &src, &dst);
}

/* 取源矩形一块，以 (cx, cy) 为中心缩放绘制（便于把精灵中心对齐实体中心） */
static void w_draw_image_centered(intptr_t image,
                                  float sx, float sy, float sw, float sh,
                                  float cx, float cy, float dw, float dh)
{
        jrect_t src = { sx, sy, sw, sh };
        jrect_t dst = { cx - dw * 0.5f, cy - dh * 0.5f, dw, dh };
        image_draw1((image_p)image, &src, &dst);
}

static void w_fill_rect(intptr_t r2d, float x, float y, float w, float h,
                        int r, int g, int b, int a)
{
        jr2d_p rd = (jr2d_p)r2d;
        set_color(rd, r, g, b, a);
        jrect_t rect = { x, y, w, h };
        shape_draw_rectangle(rd, "fill", rect);
}

static void w_stroke_rect(intptr_t r2d, float x, float y, float w, float h,
                          int r, int g, int b, int a)
{
        jr2d_p rd = (jr2d_p)r2d;
        set_color(rd, r, g, b, a);
        jrect_t rect = { x, y, w, h };
        shape_draw_rectangle(rd, "line", rect);
}

static void w_draw_line(intptr_t r2d, float x1, float y1, float x2, float y2,
                        int r, int g, int b, int a)
{
        jr2d_p rd = (jr2d_p)r2d;
        set_color(rd, r, g, b, a);
        shape_draw_line_f(rd, x1, y1, x2, y2);
}

static void draw_text_impl(intptr_t r2d, intptr_t font, MonoString* str,
                           int r, int g, int b, int a, float x, float y)
{
        if (!str || !font) return;
        char* s = mono_string_to_utf8(str);
        jcolor_t c;
        c.r = (uint8_t)r; c.g = (uint8_t)g; c.b = (uint8_t)b; c.a = (uint8_t)a;
        jtext_printx((jr2d_p)r2d, (font_p)font, s, (int)strlen(s), c, x, y);
        mono_free(s);
}

static void w_draw_text(intptr_t r2d, intptr_t font, MonoString* str,
                        int r, int g, int b, int a, float x, float y)
{
        draw_text_impl(r2d, font, str, r, g, b, a, x, y);
}

/* 以 (cx, cy) 为中心画一行文字 */
static void w_draw_text_centered(intptr_t r2d, intptr_t font, MonoString* str,
                                 int r, int g, int b, int a, float cx, float cy)
{
        if (!str || !font) return;
        char* s = mono_string_to_utf8(str);
        int w = 0, h = 0;
        jcolor_t c;
        c.r = (uint8_t)r; c.g = (uint8_t)g; c.b = (uint8_t)b; c.a = (uint8_t)a;
        jtext_measurex((jr2d_p)r2d, (font_p)font, s, (int)strlen(s), c, &w, &h);
        jtext_printx((jr2d_p)r2d, (font_p)font, s, (int)strlen(s), c,
                     cx - (float)w * 0.5f, cy - (float)h * 0.5f);
        mono_free(s);
}

/* 图片原始尺寸（C# 侧拿不到 float* 出参，这里拆成两个标量返回） */
static float w_image_width(intptr_t image)
{
        float w = 0.0f, h = 0.0f;
        image_get_size((image_p)image, &w, &h);
        return w;
}

static float w_image_height(intptr_t image)
{
        float w = 0.0f, h = 0.0f;
        image_get_size((image_p)image, &w, &h);
        return h;
}

/* 文字渲染宽度（像素），HUD 排版用 */
static int w_text_width(intptr_t r2d, intptr_t font, MonoString* str)
{
        if (!str || !font) return 0;
        char* s = mono_string_to_utf8(str);
        int w = 0, h = 0;
        jcolor_t c = { 255, 255, 255, 255 };
        jtext_measurex((jr2d_p)r2d, (font_p)font, s, (int)strlen(s), c, &w, &h);
        mono_free(s);
        return w;
}

/* ---- 结构体按值传递的 ABI 自检 ----
 * 生成器会给 vec2_t / jrect_t 这类小结构体生成按值传递的 internal call。
 * 一旦 Mono 侧的 ABI 与 C 不一致（例如被当成指针传），这里会立刻算错，
 * 冒烟测试断言它就能发现问题，而不是等到画面出怪事。 */
static float w_abi_vec2_sum(vec2_t v) { return v.x + v.y; }
static float w_abi_rect_area(jrect_t r) { return r.w * r.h; }

void csopen_draw(void)
{
        csx_register_internal_call("Joy.Draw::draw_image", (const void*)w_draw_image);
        csx_register_internal_call("Joy.Draw::draw_image_rect", (const void*)w_draw_image_rect);
        csx_register_internal_call("Joy.Draw::draw_image_centered", (const void*)w_draw_image_centered);
        csx_register_internal_call("Joy.Draw::image_width", (const void*)w_image_width);
        csx_register_internal_call("Joy.Draw::image_height", (const void*)w_image_height);
        csx_register_internal_call("Joy.Draw::fill_rect", (const void*)w_fill_rect);
        csx_register_internal_call("Joy.Draw::stroke_rect", (const void*)w_stroke_rect);
        csx_register_internal_call("Joy.Draw::draw_line", (const void*)w_draw_line);
        csx_register_internal_call("Joy.Draw::draw_text", (const void*)w_draw_text);
        csx_register_internal_call("Joy.Draw::draw_text_centered", (const void*)w_draw_text_centered);
        csx_register_internal_call("Joy.Draw::text_width", (const void*)w_text_width);
        csx_register_internal_call("Joy.Draw::abi_vec2_sum", (const void*)w_abi_vec2_sum);
        csx_register_internal_call("Joy.Draw::abi_rect_area", (const void*)w_abi_rect_area);
}
