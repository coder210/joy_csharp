namespace JoyGame
{
    internal interface IScene
    {
        void Enter(GameApp app);
        void Update(float dt);
        void Render();
    }
}
