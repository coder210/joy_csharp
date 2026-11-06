namespace JoyGame
{
    /// <summary>
    /// 界面文案：只有字体确实含 CJK 字形时才显示中文，否则降级为纯 ASCII。
    /// 这样在没有中文字体的环境下也不会出现 .notdef 豆腐块/乱码。
    /// </summary>
    internal static class Texts
    {
        public static string Pick(GameApp app, string zh, string en)
        {
            return app.Assets.HasCjkFont ? zh : en;
        }
    }
}
