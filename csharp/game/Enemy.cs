using System;

namespace JoyGame
{
    internal sealed class Enemy
    {
        public const float Radius = 11f;

        public float X;
        public float Y;
        public float SpawnX;
        public float SpawnY;
        public float Hp = 3f;
        public float Speed = 46f;

        /// <summary>与出生点相比是否已靠近玩家（冒烟断言 AI 真的在追）。</summary>
        public bool Approached(float px, float py)
        {
            float sx = SpawnX - px, sy = SpawnY - py;
            float nx = X - px, ny = Y - py;
            float before = (float)Math.Sqrt(sx * sx + sy * sy);
            float now = (float)Math.Sqrt(nx * nx + ny * ny);
            return now < before - 2f;
        }
    }
}
