using System;

namespace JoyGame
{
    /// <summary>C# 侧的绘制门面：统一走 Joy.Draw 的扁平包装。</summary>
    internal static class Painter
    {
        public static void Fill(GameApp app, float x, float y, float w, float h,
                                int r, int g, int b, int a = 255)
        {
            Joy.Draw.fill_rect(app.R2d, x, y, w, h, r, g, b, a);
        }

        public static void Stroke(GameApp app, float x, float y, float w, float h,
                                  int r, int g, int b, int a = 255)
        {
            Joy.Draw.stroke_rect(app.R2d, x, y, w, h, r, g, b, a);
        }

        public static void Line(GameApp app, float x1, float y1, float x2, float y2,
                                int r, int g, int b, int a = 255)
        {
            Joy.Draw.draw_line(app.R2d, x1, y1, x2, y2, r, g, b, a);
        }

        public static void Text(GameApp app, string text, float x, float y,
                                int r = 232, int g = 236, int b = 245)
        {
            if (app.Assets.FontSmall == IntPtr.Zero) return;
            Joy.Draw.draw_text(app.R2d, app.Assets.FontSmall, text, r, g, b, 255, x, y);
        }

        public static void TextCenter(GameApp app, string text, float cx, float cy, bool big = false,
                                      int r = 232, int g = 236, int b = 245)
        {
            IntPtr font = big ? app.Assets.FontBig : app.Assets.FontSmall;
            if (font == IntPtr.Zero) return;
            Joy.Draw.draw_text_centered(app.R2d, font, text, r, g, b, 255, cx, cy);
        }

        public static int TextWidth(GameApp app, string text)
        {
            if (app.Assets.FontSmall == IntPtr.Zero) return 0;
            return Joy.Draw.text_width(app.R2d, app.Assets.FontSmall, text);
        }

        /// <summary>以 (cx, cy) 为中心画精灵；缺图时退化为同尺寸色块。</summary>
        public static void Sprite(GameApp app, IntPtr image, float cx, float cy, float size,
                                  int fallbackR, int fallbackG, int fallbackB)
        {
            if (image != IntPtr.Zero)
            {
                float w = Joy.Draw.image_width(image);
                float h = Joy.Draw.image_height(image);
                Joy.Draw.draw_image_centered(image, 0f, 0f, w, h, cx, cy, size, size);
            }
            else
            {
                Fill(app, cx - size * 0.5f, cy - size * 0.5f, size, size,
                     fallbackR, fallbackG, fallbackB);
            }
        }
    }
}
