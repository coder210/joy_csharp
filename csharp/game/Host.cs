using System;

namespace JoyGame
{
    /// <summary>
    /// C 宿主反射调用的入口：OnInit / OnFrame / OnShutdown。
    /// 名字与参数个数必须和 host/main.c 里的 csx_find_method 一致。
    /// </summary>
    public static class Host
    {
        private static GameApp _app;
        private static SmokeScript _smoke;

        public static void OnInit(IntPtr window, IntPtr r2d, int width, int height, int smokeFrames)
        {
            _app = new GameApp(r2d, width, height, smokeFrames);
            _smoke = smokeFrames > 0 ? new SmokeScript() : null;
            _app.Start();
            Joy.Host.log("[host] init " + width + "x" + height +
                         (smokeFrames > 0 ? " smoke=" + smokeFrames : ""));
        }

        public static void OnFrame(float dt)
        {
            if (_app == null) return;
            _smoke?.BeforeTick(_app);
            _app.Tick(dt);
            _smoke?.AfterTick(_app);
        }

        public static void OnShutdown()
        {
            Joy.Host.log("[host] shutdown frames=" + (_app != null ? _app.Frame : 0));
        }
    }
}
