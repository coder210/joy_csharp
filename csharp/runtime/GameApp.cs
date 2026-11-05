using System;

namespace JoyGame
{
    /// <summary>
    /// 应用外壳：持有渲染句柄、资源、输入快照与当前场景。
    /// 每帧由宿主的 C# 入口 Host.OnFrame 驱动 Tick。
    /// </summary>
    internal sealed class GameApp
    {
        public IntPtr R2d { get; }
        public int Width { get; }
        public int Height { get; }
        public int SmokeFrames { get; }

        public Assets Assets { get; } = new Assets();
        public InputState Input { get; } = new InputState();
        public Random Rng { get; } = new Random(12345);

        public IScene Scene { get; private set; }
        public int Frame { get; private set; }

        public bool Smoke => SmokeFrames > 0;

        public GameApp(IntPtr r2d, int width, int height, int smokeFrames)
        {
            R2d = r2d;
            Width = width;
            Height = height;
            SmokeFrames = smokeFrames;
        }

        public void Start()
        {
            Assets.Load(R2d);
            ChangeScene(new MenuScene());
        }

        public void ChangeScene(IScene next)
        {
            Scene = next;
            next.Enter(this);
        }

        public void Tick(float dt)
        {
            if (dt < 0f) dt = 0f;
            if (dt > 0.05f) dt = 0.05f;

            Frame++;
            Input.BeginFrame();
            Scene.Update(dt);
            Scene.Render();
        }
    }
}
