using System;

namespace JoyGame
{
    /// <summary>
    /// 帧输入快照：把 Joy.Input 的轮询结果 + 冒烟脚本的模拟按键合成一份状态，
    /// 并提供 Pressed（本帧刚按下）用于场景切换这类边沿触发。
    /// </summary>
    internal sealed class InputState
    {
        private const int KeyCount = 512;

        private readonly bool[] _prev = new bool[KeyCount];
        private readonly bool[] _now = new bool[KeyCount];
        private readonly bool[] _scripted = new bool[KeyCount];

        public float MouseX { get; private set; }
        public float MouseY { get; private set; }
        public bool MouseLeft { get; private set; }

        public void BeginFrame()
        {
            Array.Copy(_now, _prev, KeyCount);
            for (int i = 0; i < KeyCount; i++)
            {
                _now[i] = _scripted[i] || Joy.Input.key_down(i);
            }
            MouseX = Joy.Input.mouse_x();
            MouseY = Joy.Input.mouse_y();
            MouseLeft = Joy.Input.mouse_button(1);
        }

        public bool Down(int scancode)
        {
            return scancode >= 0 && scancode < KeyCount && _now[scancode];
        }

        public bool Pressed(int scancode)
        {
            return scancode >= 0 && scancode < KeyCount && _now[scancode] && !_prev[scancode];
        }

        /// <summary>冒烟脚本用：无窗口环境下模拟按键。</summary>
        public void SetScripted(int scancode, bool down)
        {
            if (scancode >= 0 && scancode < KeyCount) _scripted[scancode] = down;
        }

        public void ClearScripted()
        {
            for (int i = 0; i < KeyCount; i++) _scripted[i] = false;
        }
    }
}
