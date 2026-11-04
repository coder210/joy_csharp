namespace JoyGame
{
    internal sealed class Player
    {
        public const float Radius = 11f;
        public const float Speed = 130f;
        public const float MaxHp = 100f;
        public const float FireInterval = 0.16f;

        public float X;
        public float Y;
        public float Hp = MaxHp;
        public float FireCooldown;
        public float FacingX = 1f;
        public float FacingY = 0f;

        public bool Alive => Hp > 0f;
    }
}
