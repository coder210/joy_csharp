namespace JoyGame
{
    internal sealed class GameOverScene : IScene
    {
        private readonly int _kills;
        private readonly float _seconds;
        private GameApp _app;

        public GameOverScene(int kills, float seconds)
        {
            _kills = kills;
            _seconds = seconds;
        }

        public void Enter(GameApp app)
        {
            _app = app;
            Joy.Host.log("[scene] GameOver kills=" + _kills + " time=" + _seconds.ToString("0.0"));
        }

        public void Update(float dt)
        {
            if (_app.Input.Pressed(Keys.Return) || _app.Input.Pressed(Keys.Space))
            {
                _app.ChangeScene(new PlayScene());
                return;
            }
            if (_app.Input.Pressed(Keys.Escape))
            {
                _app.ChangeScene(new MenuScene());
            }
        }

        public void Render()
        {
            float w = _app.Width;
            float h = _app.Height;
            float cx = w * 0.5f;
            float cy = h * 0.5f;

            Painter.Fill(_app, 0f, 0f, w, h, 14, 12, 18);
            Painter.Fill(_app, cx - 150f, cy - 70f, 300f, 140f, 26, 22, 30, 235);
            Painter.Stroke(_app, cx - 150f, cy - 70f, 300f, 140f, 90, 60, 70);

            Painter.TextCenter(_app, "GAME OVER", cx, cy - 40f, big: true, r: 255, g: 120, b: 120);
            Painter.TextCenter(_app, "击杀 " + _kills + " · 存活 " + _seconds.ToString("0.0") + "s",
                               cx, cy - 6f, r: 230, g: 232, b: 240);
            Painter.TextCenter(_app, "Enter 重来 · Esc 回菜单", cx, cy + 28f, r: 160, g: 168, b: 188);
            Painter.TextCenter(_app, "场景：GameOver", cx, 18f, r: 90, g: 96, b: 112);
        }
    }
}
