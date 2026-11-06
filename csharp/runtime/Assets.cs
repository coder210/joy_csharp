using System;

namespace JoyGame
{
    /// <summary>
    /// 运行期资源句柄。加载失败时返回 IntPtr.Zero，渲染层会退化成纯色矩形，
    /// 这样缺资源也能跑起来（冒烟环境不依赖美术资源完整性）。
    /// </summary>
    internal sealed class Assets
    {
        // 模板自带的 ARIALNB.TTF 只有拉丁字形，中文码点查不到字形会落到 .notdef，
        // 渲染成豆腐块/乱码。底层 jfont.c 用 stbtt_InitFont(data, 0)，只稳妥支持
        // TrueType glyf 轮廓的单字体 .ttf，不要放 .ttc 字体集合或 CFF 轮廓的 .otf。
        // 仓库不附带二进制字体：想固定用某套中文字体，把它放到 CJK.ttf 即可。
        private const string FallbackFont = "assets/fonts/ARIALNB.TTF";
        private static readonly string[] CjkFonts =
        {
            "assets/fonts/CJK.ttf",
            "C:/Windows/Fonts/simhei.ttf",
            "C:/Windows/Fonts/Deng.ttf",
        };

        public IntPtr PlayerImage { get; private set; }
        public IntPtr EnemyImage { get; private set; }
        public IntPtr FontSmall { get; private set; }
        public IntPtr FontBig { get; private set; }

        /// <summary>当前字体是否含中文字形；界面文案据此选择中文或 ASCII 兜底。</summary>
        public bool HasCjkFont { get; private set; }

        public float PlayerW { get; private set; }
        public float PlayerH { get; private set; }
        public float EnemyW { get; private set; }
        public float EnemyH { get; private set; }

        public void Load(IntPtr r2d)
        {
            PlayerImage = Joy.Image.image_create(r2d, "assets/sprites/player.png");
            EnemyImage = Joy.Image.image_create(r2d, "assets/sprites/enemy.png");

            // 靠 font_create 返回 Zero 判断文件是否存在/可用（裁剪 BCL 里没有 File.Exists）。
            // 命中第一个候选后就用同一路径建两个字号，避免重复探测。
            foreach (string path in CjkFonts)
            {
                IntPtr small = Joy.Font.font_create(path, 12);
                if (small == IntPtr.Zero) continue;
                FontSmall = small;
                FontBig = Joy.Font.font_create(path, 22);
                HasCjkFont = true;
                break;
            }
            if (FontSmall == IntPtr.Zero)
            {
                FontSmall = Joy.Font.font_create(FallbackFont, 12);
                FontBig = Joy.Font.font_create(FallbackFont, 22);
            }

            PlayerW = PlayerImage != IntPtr.Zero ? Joy.Draw.image_width(PlayerImage) : 16f;
            PlayerH = PlayerImage != IntPtr.Zero ? Joy.Draw.image_height(PlayerImage) : 16f;
            EnemyW = EnemyImage != IntPtr.Zero ? Joy.Draw.image_width(EnemyImage) : 16f;
            EnemyH = EnemyImage != IntPtr.Zero ? Joy.Draw.image_height(EnemyImage) : 16f;

            if (PlayerImage == IntPtr.Zero) Joy.Host.log("[warn] missing assets/sprites/player.png");
            if (EnemyImage == IntPtr.Zero) Joy.Host.log("[warn] missing assets/sprites/enemy.png");
            if (FontSmall == IntPtr.Zero) Joy.Host.log("[warn] no usable font, HUD text disabled");
        }
    }
}
