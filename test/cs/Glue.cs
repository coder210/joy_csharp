using System;
using System.Runtime.CompilerServices;

namespace Joy
{
    internal static class Utils
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool utils_check_file(string filename);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern string utils_read_file(string filename);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr utils_random_create(uint seed);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint utils_random_next(IntPtr rng);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void utils_random_destroy(IntPtr rng);
    }

    public static class Bootstrap
    {
        public static string Run()
        {
            bool exists = Utils.utils_check_file("JoyTest.dll");
            string content = Utils.utils_read_file("hello.txt");
            int len = content == null ? -1 : content.Length;

            IntPtr rng = Utils.utils_random_create(12345u);
            uint n1 = Utils.utils_random_next(rng);
            uint n2 = Utils.utils_random_next(rng);
            Utils.utils_random_destroy(rng);

            uint seed = Jpm.jpm_wave_seed(12345u, 3);

            return "exists=" + exists + ", len=" + len + ", n1=" + n1 + ", n2=" + n2 + ", wave_seed=" + seed;
        }
    }
}
