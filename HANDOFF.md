# 交接文档：joy 统一绑定层（IDL → 共享 C 运行层 → 三端薄适配）

> 生成：2026-11-07 · 工作区 `e:/c++/joy_csharp_test` · Windows / PowerShell / MSVC / .NET SDK 9 / Node 20
> 接手时状态：主仓 `main` @ `8516ba4`，子模块 `third_party/joy` `main` @ `00a85c42`，gitlink 对齐。
> 2026-11-07 更新：完成 P2-B 数据质量一刀 + P2-A 的 `checkbox` 域 L2 试点
> （见第 5 / 8 节），两仓有尚未提交的改动。
> **权威细节在 `third_party/joy/api/README.md`；本文是接手导航，不替代它。**

---

## 0. 一句话现状

用户要的终态：**Lua / JS / C# 三个脚本层用基本一样的方式使用 `joy.h` 的绝大多数能力**，
不依赖某语言独有特性；脚本层看不到裸指针（`IntPtr` / lightuserdata / pointer），
C 层创建的内存自动释放；同时要求生成器出错概率可控、后续改得动。

| 目标 | 现状 |
|---|---|
| 三端用法一致、同名同参数、句柄自动释放 | **已达成并实测** |
| 出错概率可控（默认关闭、分级、CI 门禁、生成物入库） | **已达成** |
| 覆盖面 | **448 / 935 = 47.9%**，未达成「绝大多数」 |
| 旧业务调用点迁移、删除旧胶水 | **未开始** |
| L2 试点（`checkbox` 域 2 条） | **已打通，剩 72 条 L2** |
| L3 / X、`jmath.h` | **未处理** |

**不要把「三端接通」误读成「目标完成」**：管道通了，覆盖面还差一半多。
另外，448 条里只有 4 条（`GetTicks` / `JtextCacheGetCount` / `LcgRandomCreate` /
`LcgRandomNext`）在三端验证过完整运行时语义；其余 444 条只验证「注册成功 + argc
守卫生效」（其中 2 条 L2 另有「展开参数个数 + 类型守卫」专项自检），这是刻意保留的边界。

---

## 1. 硬性约束（动手前必读）

1. **两个 git 仓**：主仓 `https://github.com/coder210/joy_csharp_test.git`、
   子模块 `https://github.com/coder210/joy.git`。改子仓内容要在子仓提交推送，
   再回主仓提交更新后的 `third_party/joy` gitlink。只推一边会让 CI 拿错代码。
2. **生成物入库 + 门禁**：`api/coverage.md`、`api/thunks_generated.c`、
   `modules/cs/bindings/api_generated.c`、`modules/cs/scripts/Api.generated.cs`
   四个生成物必须提交，CI 跑 `--check` 校验无 diff。改生成器不重生成 = CI 红。
3. **生成 ≠ 启用**：`joy.idl` 默认 `status: off`；只有 `--enable` 逐条过闸才置 `on`。
   **开放 ≠ 业务已调用 / 语义已验证**。
4. **三端契约统一**：脚本侧一律 `Joy.Api.Bindings.<PascalName>`，参数顺序与 `joy.h`
   一致；句柄只以不透明对象出现，GC 时自动 `joy_obj_release()`。方法名只能来自
   `api/naming.js`，不许后端自己写一套 `pascal()`。
5. **新旧并行**：不删旧 `modules/*/bindings/` 手写胶水，不改 C# 业务调用点。
   旧 Lua 宿主的全局表是小写 `joy`，新链路是大写 `Joy`，两者刻意并存。
6. **不要手改生成物**：改 `api/emit_*.js` / `gen_bindings.js` → 重生成 → 一起提交。
7. **CRLF**：Windows `core.autocrlf` 会把 LF 转 CRLF；`--check` 用 `normEol()` 归一后比较。
   删掉它 CI 会误报。
8. **每刀必须跑第 7 节验证清单**，别只跑 `--check` 就说完成。

---

## 2. 目录地图

### `third_party/joy/api/`（契约与共享 C 层）

| 文件 | 维护 | 作用 |
|---|---|---|
| `gen_bindings.js` | 人工 | 总入口：解析 `joy.h` → 维护 IDL → 产出 4 个生成物；`--scan` / `--enable` / `--disable` / `--check`。零 npm 依赖 |
| `naming.js` | 人工 | **三端共用**的 `isOpaque` / `methodName`(PascalCase) / `handleClass` |
| `emit_thunks.js` | 人工 | 生成 `thunks_generated.c`：每条 on 的 L0/L1 一个纯 C thunk、`s_thunks[]` 注册表、`joy_api_selftest()`；导出 `canThunk` / `ownsIssue` |
| `emit_cs.js` | 人工 | 生成 cs 侧 C icall 与 C# 强类型包装；导出 `canEmitCs` |
| `joy.idl` | 工具初始化 + 人工 | 唯一真相源，一行一条 JSON（935 条） |
| `coverage.md` | 生成 | 分级统计、按域分布、所有权待裁决、L3 清单 |
| `thunks_generated.c` | 生成 | 446 个 thunk + `s_thunks[]` + 注册表自检 |
| `README.md` | 人工 | **权威操作手册**（字段、分级、三种操作、边界） |
| `runtime/joy_value.*` | 人工 | 统一值容器：`JOY_V_NULL/BOOL/I32/U32/I64/U64/F64/STR/HANDLE` |
| `runtime/joy_obj.*` | 人工 | 句柄表（generation + refcount + tag）、`joy_obj_register/deref/release`、live/destroy 计数 |
| `runtime/joy_thunk.*` | 人工 | `joy_thunk_fn` 签名、`joy_thunk_entry` 注册表结构、按名调用 `joy_api_call()` |
| `joy_api.h` | 人工 | 对外唯一入口 `const char* joy_api_selftest(void)` |

`joy_thunk_entry` 当前字段顺序（**改结构必须同步改 `emit_thunks.js` 的初始化**）：
```text
domain, name(C snake_case), script_name(PascalCase), fn, argc, arg_kinds[], ret_kind
```

### `third_party/joy/modules/<后端>/`

| 文件 | 作用 |
|---|---|
| `cs/bindings/api_generated.c` | 生成：Mono 值 → `joy_value[]` → `joy_api_call()`，注册 `Joy.Api.Native::*` |
| `cs/scripts/Api.generated.cs` | 生成：`Joy.Api.Bindings` / `Diagnostics` / 强类型句柄类，public API 无 `IntPtr` |
| `cs/jcsx.c` / `stub.c` / `joy_csharp.h` | `csopen_api()` 注册 + 关闭时空桩 |
| `lua/bindings/lapi.c` | **人工**：遍历注册表注册 `Joy.Api.Bindings.*`；句柄 = userdata + `__gc`；`luax_api_selftest()` |
| `js/bindings/japi.c` | **人工**：同上；句柄 = 普通对象 + 隐藏字段 + finalizer；`jsopen_api_selftest()` |
| `lua/jluax.c` / `js/jsx.c` | 宿主创建时各多调一次 `luax_open_api()` / `jsopen_api()` |
| `lua/joy_lua.h` / `js/joy_js.h` / 各自 `stub.c` | 新入口声明与空桩（用 `void*` 避免头文件依赖第三方 VM 头） |

### 主仓

| 文件 | 作用 |
|---|---|
| `main.c` | `--smoke` 分支依次跑 C / lua / js / cs 四段自检 |
| `CMakeLists.txt` | `joy_add_sources(... MODULES cs lua js)`；显式编入 `runtime/*.c` + `thunks_generated.c` |
| `csharp/test/ApiBindingSmoke.cs` | C# 侧自检（调用、强类型对象、GC 自动释放） |
| `csharp/test/SmokeScript.cs` | `ok &= ApiBindingSmoke.Passed`，输出 `[smoke] PASS api=True ...` |
| `.github/workflows/windows-build.yml` | Node 20 + `--check` 门禁 + 冒烟四条断言 |
| `README.md` | 对外说明（含绑定契约章节与 CI 步骤） |

---

## 3. 数据流

```text
                    joy.h ──gen_bindings.js──> joy.idl ──> 4 个入库生成物
                                                  │
脚本层（三端同名）                                 │
Joy.Api.Bindings.GetTicks()                       │
  │                                              │
  ├─ Lua : lapi.c      VM值 ↔ joy_value          │
  ├─ JS  : japi.c      VM值 ↔ joy_value          │
  └─ C#  : api_generated.c + Api.generated.cs    │
              │                                  │
              └──> joy_api_call(name, args, n) ──┤
                         │                       │
                  joy_thunks_table()  ← thunks_generated.c
                         │
                  thunk（纯 C，不含任何 VM 类型）
                         │
              joy_obj_register / deref / release
                         │
                   真正的 joy C API
```

**关键设计**：Lua / JS 的适配层遍历注册表动态注册，**不为每条 API 生成后端代码**。
新增 API 只重新生成 `thunks_generated.c`，两个后端自动跟随。
C# 例外：Mono internal call 必须静态绑定，所以由 `emit_cs.js` 生成静态 icall。

---

## 4. 命令速查（PowerShell，仓库根目录）

```powershell
# 契约（默认生成 4 个产物；--check 只读；--scan 会保留 status/owns/note）
node third_party/joy/api/gen_bindings.js
node third_party/joy/api/gen_bindings.js --scan
node third_party/joy/api/gen_bindings.js --enable L0|L1|all|domain:<名>|name:<API>
node third_party/joy/api/gen_bindings.js --disable <同样的选择子>
node third_party/joy/api/gen_bindings.js --check

# 构建
dotnet build third_party/joy/modules/cs/Joy.Bindings.csproj -c Release -o build/csharp
dotnet build csharp/JoyGame.csproj -c Release -o build/csharp
cmake -S . -B build/app -A x64        # 首次可能需要 -DMONO_INCLUDE_DIR / -DMONO_LIBRARIES
cmake --build build/app --config Release --parallel

# 冒烟（180 帧无窗口）
Push-Location build/app/bin/Release
$env:SDL_VIDEODRIVER='dummy'
.\joy_csharp_test_app.exe --smoke 180
Pop-Location
```

`--enable` 逐条过闸，打印 `changed / skipped` 与每条跳过原因；`--disable` 对称回退。
`all` 目前只覆盖 L0/L1；`name:` 显式点名可豁免「返回句柄需人工确认所有权」这条软限制，
但**不能绕过 `owns` 类型严格匹配的硬校验**。

---

## 5. 当前数据（2026-11-07 实测，勿凭记忆改）

| 项 | 数量 |
|---|---|
| `joy.h` 的 `JOY_API` 声明 / IDL 条目 | 935 |
| 已开放 `status: on` | **448**（含 L2 试点 2 条） |
| L0 / L1 / L2 / L3 / X | 44 / 538 / 74 / 229 / 50 |
| 所有权待裁决（`ownsIssue`） | 38 |
| 缺 `owns` | 38 |
| orphan | 0 |
| `joy.h` 中值类型 `typedef struct` | 48 |

两个 38 是同一批条目：P2-B 数据质量一刀把 42 条错误推断逐条裁决完，
4 条补上合规 dtor（`create_window` / `simple_fps_create` / `r2d_wrap` /
`jtilemap_load_file_json`），其余 38 条确认没有可通过硬校验的单参数 dtor，
`owns` 置空、结论写进 `joy.idl` 的 `note`，并显示在 `coverage.md` 两张待办表里。

剩余 487 条的分解（复现 `canOpen` 统计）：

| 原因 | 数量 |
|---|---|
| 非 L0/L1（= L2 72 + L3 229 + X 50） | 351 |
| 返回句柄、批量模式需人工确认所有权 | 52 |
| 返回句柄但缺合规 `owns`（已人工裁决，见 `note`） | 36 |
| `void*` 缓冲参数需手写适配 | 31 |
| 返回 `char*`、所有权未标注 | 12 |
| 不支持的返回类型（枚举 / `fp_t` 等） | 5 |
| **合计** | **487** |

L2 试点开放了 `checkbox_set_colors` / `checkbox_set_text_color` 两条（原本属
「非 L0/L1」），其余 72 条 L2 仍未开放；`--enable all` 仍只含 L0/L1，L2 必须
`name:` 逐条点名。改掉错误 `owns` 推断后，原来的「`owns` 目标不是单参数 23 /
类型不匹配 15 / 缺 `owns` 2」三类合并成「缺合规 `owns` 36」；4 条修好的条目
落到了后面几道闸门。
L3 的 229 条成因：`非不透明指针 / 输出参数` 98、`未知类型需人工标注` 46、
`结构体指针参数` 35、`结构体按值返回` 23、`非 const char* 输出缓冲` 10、
`函数指针 / 回调` 8、`数组参数` 5、`可变参数` 4。

---

## 6. 已踩过的坑（别重犯）

**生成器**
- 块注释里出现 `modules/*/bindings/` 会提前闭合 JS 注释；`stripComments()` 必须保留换行，否则 `source` 行号漂移。
- `collectStructs()` 必须同时读 `joy.h` 和 `jmath.h`，否则 `vec2_t` 等被误判为 L3。
- `get_ticks` / `find_*` 这类通用动词开头的名字，domain 要用第二段（`GENERIC_FIRST`）。
- Windows CRLF：`--check` 比较前必须 `normEol()`，已验证模拟 CRLF checkout 通过且能抓到真实 diff。
- L2 展开试点：结构体重组必须按**字段名**赋值，不能按偏移 `memcpy`（padding 未知）；
  局部变量用 `= { 0 }` 初始化，否则漏字段会带脏值。`argc` / `arg_kinds[]` 一律用展开后
  的序列，三端适配层才能自动跟随，不必改 `lapi.c` / `japi.c`。

**所有权**
- 早期只校验「`owns` 是单指针」不够：L1 里 39 条把 `void*` 配给 `jwindow_p` 的
  destroy，dtor 会拿错类型，运行时才崩。现在 `ownsIssue()` 要求 **dtor 参数类型
  == create 返回类型**，`--check` 与 `buildThunks` 双重拦截。
- 已实测：把 `get_raw_window` 强行设 `on`，门禁报「所有权不可信」并拒绝生成。
- `get_*` / `wrap_*` 可能返回**借用指针**，类型匹配也不代表可以自动释放；批量模式
  一律跳过返回句柄的条目，只能 `name:` 点名。
- `inferOwns()` 曾有两个系统性错判：`name.replace(/_create[\s\S]*$/, ...)` 对不含
  `_create` 的名字是恒等变换，`owns` 会填成自己；`domain_destroy` 兜底又把
  `r3d_destroy(jr3d_p)` 套到返回 `void*` 的 GPU 对象上。现在推断时就用
  `ownsIssue()` 的同一套硬校验过滤候选。
- **`--scan` 永不覆盖 `owns` / `status` / `note`**（`mergeIdl()` 视其为人工字段）：
  修生成器只影响今后新增 API 的初值，已有错误必须逐条改 `joy.idl` 再重生成。
- 借用指针能通过类型校验但不能自动释放：`scene_node_destroy(scene_node_p)`、
  `scene_destroy(scene_p)` 对 `scene_find_node_by_name` /
  `scene_manager_get_current` 类型完全匹配，填上去就是双重释放，已逐条核对实现并留
  `owns:null`。

**C# / Mono**
- `void` 返回不要声明未使用的 `joy_value_t r`（MSVC 告警）。
- `const char*` 参数要 `mono_string_to_utf8` → 调用 → `mono_free`；`char*` 返回
  因所有权未标注被 `canEmitCs` 拒绝。
- `[MethodImpl(InternalCall)]` 的方法可以是 `internal`（Mono 按名查找，不要求 public）。
- `Api.generated.cs` 的 `Native` 是 internal，句柄只以 `ulong` 出现在那里；public API 无 `IntPtr`。

**C / 生成器类型**
- thunk 里的 `char*` 参数必须声明成 `const char*`，否则 MSVC `C4090`（曾出现 16 处）。
- `bool` 内部用 `int32_t` 承载。

**Lua**
- 新链路全局是 `Joy`（大写），旧宿主是 `joy`（小写），刻意并存别合并。
- 句柄用 userdata + `luaL_newmetatable` + `__gc`；`collectgarbage('collect')` 或 `lua_close` 触发释放。

**JS / duktape**
- `DUK_ERR_INTERNAL_ERROR` 常量**不存在**，用 `DUK_ERR_ERROR`。
- **plain buffer 不是 object**，`duk_set_finalizer()` 会抛 `object required, found [buffer:8]`。
  句柄用普通对象 + 两个隐藏 32 位字段（`\xFF joylo` / `\xFF joyhi`）拼回 `uint64_t`。
- 参数转换用 `duk_has_prop_string` 做类型守卫；`duk_gc(ctx, 0)` + `duk_destroy_heap` 触发 finalizer。

**构建 / git**
- `modules/<name>/CMakeLists.txt` 用 `file(GLOB bindings/*.c)`，新建适配 .c 会自动被收集，不必手改 CMake。
- `joy_add_sources(... MODULES ...)` 的 `MODULES` 是 multi-value，可写 `cs lua js`。
- 两仓分别提交推送；主仓 gitlink 必须指向子仓实际 HEAD。
- `--smoke` 在模块关闭时 stub 返回 `"lua/disabled"` / `"js/disabled"`，`main.c` 把它当「跳过」而非失败。

---

## 7. 验证清单（每刀结束必跑）

```text
1. node third_party/joy/api/gen_bindings.js --check          → "check OK: 935 IDL entries ..."
2. dotnet build Joy.Bindings.csproj -c Release -o build/csharp → 0 warning / 0 error
3. dotnet build csharp/JoyGame.csproj -c Release -o build/csharp → 0 warning / 0 error
4. cmake --build build/app --config Release --parallel      → 0 error；新增 .c 不应产生 C4090 等告警
5. --smoke 180（dummy 驱动）→ exit 0 且必须同时出现：
      [api] selftest PASS
      [api] lua selftest PASS
      [api] js selftest PASS
      [api.cs] PASS ... destroyed=1
      [smoke] PASS api=True abi=True play=2 ...
6. CI 门禁篡改测试（可选但建议）：手改任一生成物 → --check 必须失败；恢复后必须通过
7. git status 两仓 + gitlink 对齐；分别 push
```

`joy_api_selftest()` 对每条开放 API 故意传错 `argc` 调一次 `joy_api_call()`：
thunk 第一行就返回，**不执行任何 joy 业务函数**，因此批量开放有副作用 / 需要上下文的
API 不会在自检里被真的调用。别把这个机制改成「真的调用每条 API」。
对开放的 L2 试点条目，另用「展开后的正确 argc + 全 `JOY_V_NULL` 参数」调一次，
期望 `JOY_ERR_TYPE`：验证展开序列与 `arg_kinds[]` 生效，同样不执行业务函数。

---

## 8. 未完成工作与建议顺序

> 除标注「已完成」的条目外都是**建议，尚未实施**；动手前先跟用户确认优先级。

**P2-A：L2 结构体按值展开（试点 2 条已完成，剩 72 条；绘制/数学类 API 最需要）**
试点已落地（`checkbox` 域 `jcolor_t`）：新增 `api/structs.js` 统一解析值类型布局，
`gen_bindings.js` / `emit_thunks.js` / `emit_cs.js` 共用；POD 结构体参数按字段展开成
标量序列，thunk 里按字段名重新组装 C 结构体。`--enable all` 仍只含 L0/L1，L2 必须
`name:` 点名；`check()` / `buildThunks()` / `canThunk()` / `canEmitCs()` 只放行
「字段全是已知标量」的可展开 L2，返回句柄的 L2 也暂不支持。

**已知偏离**：试点阶段脚本侧传的是展开后的标量序列（如 `CheckboxSetColors(cb,
r,g,b,a, ...)` 共 13 个值），不是单个对象，参数个数与 `joy.h` 不一致；三端仍同名、
同顺序、同类型。要回到「脚本传一个对象」需下一刀做记录类型：

- `runtime/joy_value.*`：增加 `JOY_V_RECORD`（字节块 + `sizeof` 静态断言）。
- `runtime/joy_thunk.h`：`joy_thunk_entry` 增加字段 schema（字段 kind、偏移、结构 tag），
  并同步改 `emit_thunks.js` 的 `s_thunks[]` 初始化。
- `lapi.c` / `japi.c` / C# 包装：结构体对象 ↔ `joy_value` 记录的转换。
- 其余 72 条 L2 还有 `vec2_t` / `vec3_t` 等（`jmath.h`，`ft_t` 未进映射表），
  以及含数组 / 嵌套 / 指针字段的结构体，当前一律不展开。
- 约束：展开后参数个数不能超过 `LUAX_MAX_ARGS` / `JSAPI_MAX_ARGS`（都是 16）；
  逐条点名开放，跑完第 7 节清单再批量放。

**P2-B：136 条被闸门跳过的条目（数据质量一刀已完成）**
已做：修 `inferOwns()` 两个系统性错判；42 条 `ownsIssue` 逐条核对实现裁决，
4 条补合规 dtor、38 条留空并在 `note` 写明「借用 / 双参数 dtor / 无合规 dtor」；
`coverage.md` 两张待办表新增 `note` 列。**该刀本身未开放任何 API（当时 446 条不变）**。
剩余按原因分批处理：52 条返回句柄需 `name:` 点名确认、36 条缺合规 `owns`
（要手写 thunk 或引入显式 `borrowed` 标记才能开放）、31 条 `void*` 缓冲、
12 条 `char*` 返回（标注谁 free）、5 条未知返回类型。

**P3：L3 229 条**
按第 5 节成因分类手写 thunk：输出参数 98 条最有希望做成通用模式；
回调 8 条、varargs 4 条、数组 5 条建议逐个人工处理。

**P4：业务收尾**
把约 39 处旧 `Joy.*` C# 调用点迁到 `Joy.Api.Bindings.*`，确认 public API 再无 `IntPtr`，
再删约 70 个旧胶水 `.c` 文件（这一步之前别删，新旧并行是安全网）。

**P5：`jmath.h`**
1756 行、134 个 `JOY_INLINE`、10 个 `typedef struct`，没有 `JOY_API`；
目前只在 `coverage.md` 做粗统计，需单独解析并映射成值类型/记录。

---

## 9. 接手第一步建议

1. 读 `third_party/joy/api/README.md`（权威）+ 本文第 1 节。
2. 跑一次第 7 节清单，确认基线是绿的（不要跳过，环境可能变）。
3. 跟用户确认下一刀（P2-A / P2-B 剩余条目 / P4）；**不要自行全量开放剩余 API**。
4. 每刀结束：重生成 → 验证 → 子仓提交推送 → 主仓提交推送（含 gitlink）→ 更新本文第 5 节数字。
