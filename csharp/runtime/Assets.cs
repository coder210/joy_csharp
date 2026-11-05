using System;

namespace JoyGame
{
    /// <summary>
    /// 运行期资源句柄。加载失败时返回 IntPtr.Zero，渲染层会退化成纯色矩形，
    /// 这样缺资源也能跑起来（冒烟环境不依赖美术资源完整性）。
    /// </summary>
    internal sealed class Assets
    {
        public IntPtr PlayerImage { get; private set; }
        public IntPtr EnemyImage { get; private set; }
        public IntPtr FontSmall { get; private set; }
        public IntPtr FontBig { get; private set; }

        public float PlayerW { get; private set; }
        public float PlayerH { get; private set; }
        public float EnemyW { get; private set; }
        public float EnemyH { get; private set; }

        public void Load(IntPtr r2d)
        {
            PlayerImage = Joy.Image.image_create(r2d, "assets/sprites/player.png");
            EnemyImage = Joy.Image.image_create(r2d, "assets/sprites/enemy.png");
            FontSmall = Joy.Font.font_create("assets/fonts/ARIALNB.TTF", 12);
            FontBig = Joy.Font.font_create("assets/fonts/ARIALNB.TTF", 22);

            PlayerW = PlayerImage != IntPtr.Zero ? Joy.Draw.image_width(PlayerImage) : 16f;
            PlayerH = PlayerImage != IntPtr.Zero ? Joy.Draw.image_height(PlayerImage) : 16f;
            EnemyW = EnemyImage != IntPtr.Zero ? Joy.Draw.image_width(EnemyImage) : 16f;
            EnemyH = EnemyImage != IntPtr.Zero ? Joy.Draw.image_height(EnemyImage) : 16f;

            if (PlayerImage == IntPtr.Zero) Joy.Host.log("[warn] missing assets/sprites/player.png");
            if (EnemyImage == IntPtr.Zero) Joy.Host.log("[warn] missing assets/sprites/enemy.png");
            if (FontSmall == IntPtr.Zero) Joy.Host.log("[warn] missing assets/fonts/ARIALNB.TTF");
        }
    }
}
