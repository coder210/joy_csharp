# joy_csharp

joy 引擎的可选 **C#（Mono）脚本后端**，包含绑定层、绑定代码生成器与端到端测试工程。

- joy 核心本身**不依赖**本仓，也不需要 Mono。
- 只有想让 C# 脚本/程序集驱动引擎的工程才链接本仓。
- 依赖：joy 公共 API（`<joy/joy.h>`）+ Mono 开发包（`mono/metadata/*`）。

## 目录结构

```
CMakeLists.txt                 模块本体，产出静态库 joy_csharp
joy_csharp.h                   C++ 侧 API（csx_*，Mono 句柄仅作不透明前置声明）
joy_csharp.c                   Mono 嵌入宿主（create / load_assembly / invoke_static_method）

csclib/                        C# → C 的 internal call 胶水层
  csclib.h
  sdl.c sys.c mathx.c kcp.c collision.c utils.c   手写部分
  generated/csclib_generated.c / .h               由生成器产出（勿手改）

csharp/Joy/InternalCalls.cs    C# 侧 internal call 声明（生成物，勿手改）

tools/gen_csclib.js            绑定代码生成器：扫 joy.h → 生成 csclib_generated.* + InternalCalls.cs

test/                          端到端测试工程
  CMakeLists.txt               C++ 测试宿主的 CMake
  main.c                       C++ 测试 main（C++ → C# → C++ 双向调用）
  cs/JoyTest.csproj            C# 测试项目（复用本仓 InternalCalls.cs）
  cs/Calc.cs                   被测方法（纯 C#）
  cs/Glue.cs                   走 internal call 回 C 的用例（utils_*）
  cs/hello.txt                 utils_read_file 的读文件样例
```

## 构建模块

```powershell
cmake -S . -B build `
  -DJOY_SOURCE_DIR="D:/github/joy_topdown_template/third_party/joy" `
  -DMONO_INCLUDE_DIR="C:/Program Files/Mono/include/mono-2.0" `
  -DMONO_LIBRARIES="C:/Program Files/Mono/lib/mono-2.0-sgen.lib"
cmake --build build --config Release
```

作为上层工程的子模块使用时：

```cmake
add_subdirectory(third_party/joy_csharp)
target_link_libraries(<game> PRIVATE joy_csharp)
```

`ENABLED_CSHARP_SCRIPT` 由本模块 `PUBLIC` 传递，宿主侧 `joy_script_stub.c` 据此关闭桩实现。

## 端到端测试

```powershell
# 1) 编译 C# 被测程序，产出 JoyTest.dll
dotnet build test/cs/JoyTest.csproj -c Release -o test/cs/out

# 2) 编译 C++ 测试宿主（CMakeLists 在 test/ 下）
cmake -S test -B build/e2e `
  -DJOY_SOURCE_DIR="D:/github/joy_topdown_template/third_party/joy" `
  -DMONO_INCLUDE_DIR="C:/Program Files/Mono/include/mono-2.0" `
  -DMONO_LIBRARIES="C:/Program Files/Mono/lib/mono-2.0-sgen.lib"
cmake --build build/e2e --config Release

# 3) 把运行期产物放到 exe 同目录后运行
copy test/cs/out/JoyTest.dll build/e2e/Release/
copy test/cs/hello.txt      build/e2e/Release/
./build/e2e/Release/joy_csharp_e2e.exe
```

预期输出：

```
csx_load_assembly OK
Add(3,4) = 7
Hello -> Hello, Mono
Bootstrap.Run -> exists=True, len=21, n1=..., n2=..., wave_seed=...
csx_release OK
```

覆盖三条链路：

1. `csx_load_assembly` 从文件加载程序集；
2. `csx_invoke_static_method` 反射调用纯 C# 静态方法（`Calc.Add` / `Calc.Hello`）；
3. C# 侧 `[MethodImpl(InternalCall)]` 回调 C（`Joy.Utils.utils_*`、以及生成的 `Joy.<Class>::<func>`）。

## 重新生成绑定

```powershell
node tools/gen_csclib.js --joy "D:/github/joy_topdown_template/third_party/joy"
```

默认 joy 源码目录为同级 `../joy`（其下须有 `joy.h`），也可用环境变量 `JOY_DIR` 指定。

生成器只转换"可安全自动转换"的子集：

- 标量（`int` / `uint32_t` / `float` / `double` / `bool` …）→ 同名 C# 类型；
- `const char*` 入参 → `string`（wrapper 内 `mono_string_to_utf8`，调用后释放）；
- 不透明指针 `*_p`、`void*` → `IntPtr`。

跳过：返回 `char*`、结构体/结构体指针、数组、函数指针、可变参数、输出参数（`T*`）、
`utils_` / `jspine_` / `modules_` 前缀与 `jecs_test`（由 `csclib/utils.c` 手写或未链接）。
手写部分请放在 `csclib/*.c` 并在 `csclib.h` 中声明 `csopen_*()`，由 `joy_csharp.c` 注册。

## License

MIT，见 [LICENSE](LICENSE)。
