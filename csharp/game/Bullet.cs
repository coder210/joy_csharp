namespace JoyGame
{
    internal sealed class Bullet
    {
        public const float Radius = 3f;
        public const float Speed = 320f;

        public float X;
        public float Y;
        public float Vx;
        public float Vy;
        public float Life = 1.5f;
        public float Damage = 1f;
    }
}
