# joy_csharp_test

joy 引擎的 **C# 脚本模板**：C 侧只留窗口 / 主循环 / 事件泵，**业务逻辑（场景、玩法、渲染调用）全部写在 C#**，通过 Mono 以 internal call 双向绑定。

一个可直接运行的最小可玩模板：菜单 → 战斗（移动/射击/敌人 AI/击杀）→ 死亡结算，并带无窗口冒烟测试与 Windows CI。

## 目录结构

```
main.c                    C 宿主：窗口 + 主循环 + SDL 事件泵；每帧回调 C# Host.OnFrame
CMakeLists.txt            仓库根构建入口（MODULES csharp 接入 joy 绑定模块 + 拷贝运行期产物）

csharp/                   C# 工程（程序集 JoyGame.dll，netstandard2.0）
  JoyGame.csproj          引用 joy 子项目提供的 InternalCalls.cs
  bindings/               Joy 命名空间的手写 internal call 声明（待上移 joy 子项目）
    Native.cs             Joy.Draw / Joy.Input / Joy.Host
  runtime/                模板运行时骨架
    Host.cs               C 宿主反射入口：OnInit / OnFrame / OnShutdown
    GameApp.cs / IScene.cs              应用外壳 / 场景接口
    InputState.cs / Assets.cs / Painter.cs / Keys.cs   joy API 门面与常量
  game/                   示例玩法
    MenuScene.cs / PlayScene.cs / GameOverScene.cs
    Player.cs / Enemy.cs / Bullet.cs
  test/
    SmokeScript.cs        无窗口冒烟脚本（模拟按键 + 断言）

assets/                   模板资源（玩家/敌人精灵、字体）
third_party/joy/          joy 引擎（git submodule，提交号固定在 gitlink 里）
  modules/csharp/         C# 绑定模块：Mono 宿主 joy_csharp.c/.h、csclib/、
                          csharp/Joy/InternalCalls.cs、tools/gen_csclib.js
```

## 模块归属

C# 绑定层（Mono 宿主、`csclib/`、自动生成的 `Joy.InternalCalls`）属于
**joy 子项目** `third_party/joy/modules/csharp`，本仓不再持有副本：

- C 侧：`joy_add_sources(joy_csharp_test_app MODULES csharp)` 自动启用并链接
  `joy_module_csharp`，同时把 `ENABLED_CSHARP_SCRIPT` 传给宿主编入的 joy 源码。
- C# 侧：`JoyGame.csproj` 直接引用该模块的 `csharp/Joy/InternalCalls.cs`。

`JoyGame.csproj` 按职责显式分组，不再用一个 `game\**\*.cs` 一把梭：

| 目录 | 内容 | 归属 |
|---|---|---|
| `csharp/bindings/` | `namespace Joy` 的手写 internal call 声明 | 应属 joy，暂隔离待上移 |
| `csharp/runtime/` | `Host` / `GameApp` / `IScene` 及 `Joy.*` 门面 | 本仓模板骨架 |
| `csharp/game/` | 场景、玩家、敌人、子弹 | 本仓示例玩法 |
| `csharp/test/` | `SmokeScript` | 本仓测试脚本 |

`bindings/Native.cs` 是唯一仍留在本仓的 `Joy` 命名空间文件：joy 子项目只提供
自动生成的 `InternalCalls.cs`，没有 `Joy.Draw/Input/Host` 的手写声明。直接改动
git 子模块不会随本仓提交（主仓只记录 gitlink），他人 clone 后会编译失败，因此
先隔离存放；待 joy 侧补齐后改为引用并删除本仓副本。

## 运行时架构

```
C 宿主 main.c                              C# 业务 JoyGame.dll
  SDL_AppInit   创建窗口 / r2d / Mono  ──►  Host.OnInit(win, r2d, w, h, smoke)
  SDL_AppEvent  键鼠事件写输入桥        ──►  （C# 通过 Joy.Input 轮询）
  SDL_AppIterate r2d_begin            ──►  Host.OnFrame(dt) ──► 场景 Update/Render
                 r2d_end（present）
  SDL_AppQuit                        ──►  Host.OnShutdown()
```

- C 侧不写任何玩法代码，只负责"帧边界 + 事件泵 + Mono 生命周期"。
- C# 侧通过 internal call 调 joy 的 C API，天然与引擎逻辑同进程、零 IPC。
- 帧回调走 `csx_find_method` 缓存的方法句柄，不做每帧反射查找。

## 依赖

| 依赖 | 说明 |
|---|---|
| joy 引擎 | 仓内 **git 子模块** `third_party/joy`（`git submodule update --init`） |
| C# 绑定模块 | 同一子模块里的 `modules/csharp`，由 `MODULES csharp` 启用；本仓不含副本 |
| Mono 开发包 | `MONO_INCLUDE_DIR` / `MONO_LIBRARIES` / 运行期 `mono-2.0-sgen.dll` |
| .NET SDK 8 | 编译 `JoyGame.dll`（目标框架 netstandard2.0，供 Mono 加载） |
| CMake ≥ 3.16 + MSVC | 构建宿主 |

## 获取代码

```powershell
git clone --recursive https://github.com/coder210/joy_csharp_test.git
# 已 clone 过（或想同步 joy）：
git submodule update --init --recursive
```

`third_party/joy` 指向 `coder210/joy` 的固定提交，构建脚本默认就用它，无需再传 `-DJOY_SOURCE_DIR`。
要临时换用另一份 joy 源码树时，仍可 `-DJOY_SOURCE_DIR=<含 joy.h 的目录>` 覆盖。

## 构建与运行（Windows）

```powershell
# 1) C# 业务程序集
dotnet build csharp/JoyGame.csproj -c Release -o build/csharp

# 2) C++ 宿主（CMake 会自动把 assets / JoyGame.dll / mono 运行时拷到输出目录）
cmake -S . -B build/app -A x64
cmake --build build/app --config Release --parallel

# 3) 运行（也可先 cd 到 build/app/bin/Release）
.\build\app\bin\Release\joy_csharp_test_app.exe
```

操作：`WASD` 移动 · `Space` 或鼠标左键射击 · `Esc` 返回菜单 / 退出。

### 参数

| 参数 | 说明 |
|---|---|
| `--smoke N` | 无窗口冒烟：dummy 视频驱动 + 固定 60Hz，跑 N 帧后按断言结果退出 |
| `--assembly PATH` | 指定程序集（默认 `JoyGame.dll`，相对当前工作目录） |

### 冒烟测试

```powershell
cd build/app/bin/Release
$env:SDL_VIDEODRIVER="dummy"
.\joy_csharp_test_app.exe --smoke 180    # 退出码 0 = 通过
```

脚本模拟按键跑完 **Menu → Play → GameOver → 重开 Play**，断言：

- 结构体按值传递的 ABI 正确（`abi=True`）
- 场景切换发生 2 次（菜单进游戏、死亡后重开）
- 输入真的驱动了移动、射击
- 子弹命中并击杀敌人
- 敌人 AI 确实在靠近玩家

输出 `[smoke] PASS abi=True play=2 ...` 并退出；失败则 `[smoke] FAIL ...` 且退出码为 1。

## 绑定体系

绑定层全部位于 joy 子项目 `third_party/joy/modules/csharp/`：

| 层 | 内容 | 维护位置 |
|---|---|---|
| 自动生成 | 603 个 joy C API（标量 / 字符串 / 不透明指针 / ≤16 字节小结构体按值） | `tools/gen_csclib.js` → `csclib/generated/`、`csharp/Joy/InternalCalls.cs`（相对 `modules/csharp/`） |
| 手写热点 | `Joy.Draw`（图片、矩形、线、文字、贴图尺寸）、`Joy.Input`、`Joy.Host` | `modules/csharp/csclib/draw.c`、`input.c`、`host.c` |
| 手写 POC | `utils_*` 等早期接口 | `modules/csharp/csclib/utils.c` |
| C# 业务侧声明 | 上述手写热点的 internal call 声明 | 本仓 `csharp/bindings/Native.cs`（待上移 joy） |

重新生成（改动落在 joy 子项目里，需在 joy 仓库提交后更新本仓 gitlink）：

```powershell
node third_party/joy/modules/csharp/tools/gen_csclib.js
# 产出写入 modules/csharp/csclib/generated/ 与 modules/csharp/csharp/Joy/
# 默认解析 joy 源码树自身；也可用 --joy <目录> 或环境变量 JOY_DIR 覆盖
```

生成器规则：

- 标量 → 同名 C# 类型；`const char*` 入参 → `string`；`*_p` / `void*` → `IntPtr`
- **小结构体**（字段全标量、总大小 ≤ 16 字节，如 `vec2_t` / `jrect_t` / `jcolor_t`）→ C# `[StructLayout(Sequential)]` 结构体，按值传参
- 跳过：结构体指针、结构体返回值、数组、函数指针、可变参数、输出参数（`T*`）——这些热点由 `modules/csharp/csclib/draw.c` 的扁平包装覆盖

绘制为什么还要手写一层：`image_draw1` / `jtext_printx` 这类 API 走的是结构体指针 + 颜色结构体，C# 侧传 `ref` 既啰嗦又容易踩 ABI 坑；扁平成 `float/int/string` 后业务代码更好写。

## 扩展指引

- **加一个场景**：实现 `runtime/IScene.cs` 的 `IScene`（`Enter/Update/Render`），在 `game/` 下新建场景并用 `app.ChangeScene(...)` 切换。
- **加一种敌人**：复制 `game/Enemy.cs` 的字段，在 `game/PlayScene.cs` 的 `UpdateSpawn` 里决定生成规则，`Render` 里选精灵。
- **加绘制**：优先用 `runtime/Painter.cs`；需要新 API 时在 joy 子项目 `modules/csharp/csclib/draw.c` 加扁平包装 + 本仓 `bindings/Native.cs` 声明 + 注册一行。
- **加输入**：joy 子项目 `modules/csharp/csclib/input.c` 已经透传全部 SDL scancode（宿主写入），C# 侧直接用 `runtime/Keys.cs` 的常量或数字。

## CI

`.github/workflows/windows-build.yml`（仅 Windows x64）：

1. `checkout` 时递归拉取子模块（joy 提交号由 gitlink 固定，绑定模块随之就位）
2. 装 .NET 8 + Mono
3. `dotnet build` C# 业务（自动引用子模块的 `InternalCalls.cs`）
4. CMake + MSVC 构建宿主（`MODULES csharp` 编入 joy 的绑定源码）
5. `joy_csharp_test_app.exe --smoke 180` 无窗口冒烟（必须 `[smoke] PASS`）
6. 上传 exe + dll + assets 产物

## License

MIT，见 [LICENSE](LICENSE)。
