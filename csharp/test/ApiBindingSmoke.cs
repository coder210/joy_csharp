using System;

namespace JoyGame
{
    /// <summary>
    /// P1 新绑定链路的 C# 侧自检，只在 --smoke 下运行。验证三件事：
    ///   1) IDL 驱动的 internal call 能从 C# 走到共享 thunk；
    ///   2) C 层创建的句柄在脚本层表现为强类型对象（public API 无 IntPtr）；
    ///   3) 对象被 GC 后 C 侧自动析构，句柄计数配平。
    /// 旧的 Joy.* 胶水与业务调用点完全不动。
    /// </summary>
    internal static class ApiBindingSmoke
    {
        internal static bool Passed { get; private set; }
        internal static string Detail { get; private set; } = "not-run";

        private static void CreateAndDrop(ulong seed)
        {
            var rng = Joy.Api.Bindings.LcgRandomCreate(seed);
            uint a = Joy.Api.Bindings.LcgRandomNext(rng);
            uint b = Joy.Api.Bindings.LcgRandomNext(rng);
            if (a == b) throw new InvalidOperationException("lcg_random_next returned identical values");
        }

        internal static void Run()
        {
            try
            {
                uint live0 = Joy.Api.Diagnostics.LiveCount;
                uint dead0 = Joy.Api.Diagnostics.DestroyCount;

                ulong ticks = Joy.Api.Bindings.GetTicks();
                int cached = Joy.Api.Bindings.JtextCacheGetCount();

                CreateAndDrop(12345UL);
                uint liveAfter = Joy.Api.Diagnostics.LiveCount;

                GC.Collect();
                GC.WaitForPendingFinalizers();
                GC.Collect();

                uint liveNow = Joy.Api.Diagnostics.LiveCount;
                uint deadNow = Joy.Api.Diagnostics.DestroyCount;

                Passed = liveAfter == live0 + 1
                      && liveNow == live0
                      && deadNow == dead0 + 1;
                Detail = "ticks=" + ticks + " cache=" + cached
                       + " live=" + live0 + "->" + liveAfter + "->" + liveNow
                       + " destroyed=" + (deadNow - dead0);
                Joy.Host.log("[api.cs] " + (Passed ? "PASS " : "FAIL ") + Detail);
            }
            catch (Exception ex)
            {
                Passed = false;
                Detail = ex.GetType().Name + ": " + ex.Message;
                Joy.Host.log("[api.cs] FAIL " + Detail);
            }
        }
    }
}
