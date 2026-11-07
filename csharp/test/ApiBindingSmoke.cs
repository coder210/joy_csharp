using System;
using System.Reflection;

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

        /* 真正调用已开放的 L0 API 并校验返回值，而不只是「注册成功 + argc 守卫」。
         * 两条都是纯标量、无句柄、无窗口上下文，可在 dummy 驱动下稳定复现。 */
        private static bool CheckRealCalls()
        {
            // jpm_wave_seed(base, wave) = base + wave * 1000003（jprocmap.c:285）
            uint seed = Joy.Api.Bindings.JpmWaveSeed(12345u, 2);
            bool seedOk = seed == 2012351u;

            ulong h1 = Joy.Api.Bindings.Murmur3Hash("joy");
            ulong h2 = Joy.Api.Bindings.Murmur3Hash("joy");
            ulong h3 = Joy.Api.Bindings.Murmur3Hash("Joy");
            bool hashOk = h1 != 0 && h1 == h2 && h1 != h3;

            return seedOk && hashOk;
        }

        /* P4 前置检查：新链路 public 入口不能把 IntPtr / 裸句柄暴露给业务层。 */
        private static bool PublicApiHasNoRawPointers()
        {
            foreach (MethodInfo m in typeof(Joy.Api.Bindings).GetMethods(
                BindingFlags.Public | BindingFlags.Static))
            {
                if (m.ReturnType == typeof(IntPtr)) return false;
                foreach (ParameterInfo p in m.GetParameters())
                {
                    if (p.ParameterType == typeof(IntPtr)) return false;
                }
            }
            return true;
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

                bool realOk = CheckRealCalls();
                bool opaqueOk = PublicApiHasNoRawPointers();

                Passed = liveAfter == live0 + 1
                      && liveNow == live0
                      && deadNow == dead0 + 1
                      && realOk
                      && opaqueOk;
                Detail = "ticks=" + ticks + " cache=" + cached
                       + " live=" + live0 + "->" + liveAfter + "->" + liveNow
                       + " destroyed=" + (deadNow - dead0)
                       + " real=" + realOk + " opaque=" + opaqueOk;
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
