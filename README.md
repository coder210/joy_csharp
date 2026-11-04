# joy_csharp

joy 引擎的 **C# 脚本模板**：C 侧只留窗口 / 主循环 / 事件泵，**业务逻辑（场景、玩法、渲染调用）全部写在 C#**，通过 Mono 以 internal call 双向绑定。

一个可直接运行的最小可玩模板：菜单 → 战斗（移动/射击/敌人 AI/击杀）→ 死亡结算，并带无窗口冒烟测试与 Windows CI。

## 目录结构

```
app/                      C++ 宿主（可执行 joy_csharp_app）
  main.c                  窗口 + 主循环 + SDL 事件泵；每帧回调 C# Host.OnFrame
  CMakeLists.txt          宿主构建（含 assets / JoyGame.dll / mono 运行时拷贝）

csharp/                   C# 业务（程序集 JoyGame.dll，netstandard2.0）
  JoyGame.csproj
  Joy/InternalCalls.cs    自动生成的绑定声明（勿手改）
  game/
    Native.cs             手写 internal call 声明（Joy.Draw / Joy.Input / Joy.Host）
    Host.cs               入口：OnInit / OnFrame / OnShutdown
    GameApp.cs            场景管理 + 资源 + 输入快照
    MenuScene.cs / PlayScene.cs / GameOverScene.cs
    Player.cs / Enemy.cs / Bullet.cs
    SmokeScript.cs        无窗口冒烟脚本（模拟按键 + 断言）
    Painter.cs / Assets.cs / InputState.cs / Keys.cs

joy_csharp.h / .c         Mono 宿主（csx_*：创建 / 加载程序集 / 反射调用 / 方法句柄缓存）
csclib/                   C# → C 的 internal call 胶水层
  draw.c                  绘制热点（扁平参数：图片 / 矩形 / 文字 / 线）
  input.c                 宿主写入键鼠状态，C# 轮询
  host.c                  日志 / 退出 / 退出码
  utils.c sys.c sdl.c mathx.c kcp.c collision.c   其他手写部分
  generated/              生成器产出（勿手改）
tools/gen_csclib.js       绑定代码生成器
assets/                   模板资源（玩家/敌人精灵、字体）
third_party/joy/          joy 引擎（git submodule，提交号固定在 gitlink 里）
```

## 运行时架构

```
C 宿主 app/main.c                          C# 业务 JoyGame.dll
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
| Mono 开发包 | `MONO_INCLUDE_DIR` / `MONO_LIBRARIES` / 运行期 `mono-2.0-sgen.dll` |
| .NET SDK 8 | 编译 `JoyGame.dll`（目标框架 netstandard2.0，供 Mono 加载） |
| CMake ≥ 3.16 + MSVC | 构建宿主 |

## 获取代码

```powershell
git clone --recursive https://github.com/coder210/joy_csharp.git
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
cmake -S app -B build/app -A x64
cmake --build build/app --config Release --parallel

# 3) 运行（也可先 cd 到 build/app/bin/Release）
.\build\app\bin\Release\joy_csharp_app.exe
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
.\joy_csharp_app.exe --smoke 180    # 退出码 0 = 通过
```

脚本模拟按键跑完 **Menu → Play → GameOver → 重开 Play**，断言：

- 结构体按值传递的 ABI 正确（`abi=True`）
- 场景切换发生 2 次（菜单进游戏、死亡后重开）
- 输入真的驱动了移动、射击
- 子弹命中并击杀敌人
- 敌人 AI 确实在靠近玩家

输出 `[smoke] PASS abi=True play=2 ...` 并退出；失败则 `[smoke] FAIL ...` 且退出码为 1。

## 绑定体系

| 层 | 内容 | 维护方式 |
|---|---|---|
| 自动生成 | 603 个 joy C API（标量 / 字符串 / 不透明指针 / ≤16 字节小结构体按值） | `tools/gen_csclib.js` |
| 手写热点 | `Joy.Draw`（图片、矩形、线、文字、贴图尺寸）、`Joy.Input`、`Joy.Host` | `csclib/draw.c`、`input.c`、`host.c` |
| 手写 POC | `utils_*` 等早期接口 | `csclib/utils.c` |

重新生成：

```powershell
node tools/gen_csclib.js
# 默认取仓内子模块 third_party/joy；也可用 --joy <目录> 或环境变量 JOY_DIR 覆盖
```

生成器规则：

- 标量 → 同名 C# 类型；`const char*` 入参 → `string`；`*_p` / `void*` → `IntPtr`
- **小结构体**（字段全标量、总大小 ≤ 16 字节，如 `vec2_t` / `jrect_t` / `jcolor_t`）→ C# `[StructLayout(Sequential)]` 结构体，按值传参
- 跳过：结构体指针、结构体返回值、数组、函数指针、可变参数、输出参数（`T*`）——这些热点由 `csclib/draw.c` 的扁平包装覆盖

绘制为什么还要手写一层：`image_draw1` / `jtext_printx` 这类 API 走的是结构体指针 + 颜色结构体，C# 侧传 `ref` 既啰嗦又容易踩 ABI 坑；扁平成 `float/int/string` 后业务代码更好写。

## 扩展指引

- **加一个场景**：实现 `IScene`（`Enter/Update/Render`），用 `app.ChangeScene(new XxxScene())` 切换。
- **加一种敌人**：复制 `Enemy.cs` 的字段，在 `PlayScene.UpdateSpawn` 里决定生成规则，`Render` 里选精灵。
- **加绘制**：优先用 `Painter`；需要新 API 时在 `csclib/draw.c` 加扁平包装 + `Native.cs` 声明 + 注册一行。
- **加输入**：`csclib/input.c` 已经透传全部 SDL scancode（宿主写入），C# 侧直接用 `Keys` 常量或数字。

## CI

`.github/workflows/windows-build.yml`（仅 Windows x64）：

1. `checkout` 时递归拉取子模块（joy 提交号由 gitlink 固定）
2. 装 .NET 8 + Mono
3. `dotnet build` C# 业务
4. CMake + MSVC 构建宿主
5. `joy_csharp_app.exe --smoke 180` 无窗口冒烟（必须 `[smoke] PASS`）
6. 上传 exe + dll + assets 产物

## License

MIT，见 [LICENSE](LICENSE)。
