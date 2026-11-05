# ============================================================
# C# 业务模板的 C++ 宿主（Windows / MSVC），仓库根即构建入口
#
# 结构：
#   main.c                        创建窗口 + 主循环 + 事件泵，每帧回调 C# Host.OnFrame
#   third_party/joy/modules/csharp   joy 子项目提供的 C# 绑定模块（MODULES csharp）
#   csharp/                       C# 业务程序集 JoyGame.dll（dotnet build 产出）
#
# 用法（在仓库根目录，joy 默认取仓内子模块 third_party/joy）：
#   cmake -S . -B build/app -A x64 \
#         -DMONO_INCLUDE_DIR=... -DMONO_LIBRARIES=...
#   cmake --build build/app --config Release
# ============================================================
cmake_minimum_required(VERSION 3.16)
project(joy_csharp_test_app C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# ---- joy 源码树（其下有 joy.h）---------------------------------------------
# 默认用仓内子模块 third_party/joy（git submodule update --init），
# 也兼容与 joy 源码树同级、或从别的工程里复用 joy 的场景。
set(JOY_SOURCE_DIR "" CACHE PATH "joy 源码目录（其下须有 joy.h）")
if(NOT EXISTS "${JOY_SOURCE_DIR}/joy.h")
    foreach(_joy_cand
        "${CMAKE_CURRENT_SOURCE_DIR}/third_party/joy"
        "${CMAKE_CURRENT_SOURCE_DIR}/../joy"
        "${CMAKE_CURRENT_SOURCE_DIR}/../joy_topdown_template/third_party/joy")
        if(EXISTS "${_joy_cand}/joy.h")
            set(JOY_SOURCE_DIR "${_joy_cand}" CACHE PATH "joy 源码目录（其下须有 joy.h）" FORCE)
            break()
        endif()
    endforeach()
endif()
if(NOT EXISTS "${JOY_SOURCE_DIR}/joy.h")
    message(FATAL_ERROR
        "joy_csharp_test_app: 找不到 joy 源码树，请设置 -DJOY_SOURCE_DIR=<含 joy.h 的目录>")
endif()

# ---- C# 运行时：joy 子项目 modules/csharp/runtime 提供 ----------------------
# 该构建来自 dotnet/runtime：coreclr.dll 内静态链接了 Mono 运行时组件，
# 同时导出 coreclr_* 与 mono_* 两套宿主 API，因此 joy_csharp.c / csclib
# 仍可沿用 Mono 嵌入 API，无需重写宿主层；BCL 在 libs/（net8.0）。
# 需要换成别的运行时时：-DJOY_CLR_ROOT=<含 coreclr.dll 的目录>。
set(JOY_CLR_ROOT "${JOY_SOURCE_DIR}/modules/csharp/runtime/windows.x64.Release"
    CACHE PATH "CoreCLR 运行时目录（默认取 joy 子项目 modules/csharp/runtime）")
# 缓存里若还留着已失效的旧路径，自动回退到 joy 子项目内置的那套
set(_clr_root "${JOY_SOURCE_DIR}/modules/csharp/runtime/windows.x64.Release")
if(JOY_CLR_ROOT AND EXISTS "${JOY_CLR_ROOT}/coreclr.dll")
    set(_clr_root "${JOY_CLR_ROOT}")
endif()
set(MONO_INCLUDE_DIR "${_clr_root}/include/mono-2.0")
set(MONO_LIBRARIES   "${_clr_root}/coreclr.import.lib")
set(MONO_RUNTIME_DLL "${_clr_root}/coreclr.dll")
set(JOY_CLR_LIB_DIR  "${_clr_root}/libs")

# ---- C# 业务程序集 ---------------------------------------------------------
set(JOY_GAME_DLL "${CMAKE_CURRENT_SOURCE_DIR}/build/csharp/JoyGame.dll"
    CACHE FILEPATH "JoyGame.dll（dotnet build -o build/csharp 的产物）")

# ---- joy 依赖的第三方工程 ---------------------------------------------------
add_subdirectory("${JOY_SOURCE_DIR}/msgpack" "${CMAKE_BINARY_DIR}/msgpack")
add_subdirectory("${JOY_SOURCE_DIR}/spine"   "${CMAKE_BINARY_DIR}/spine")
add_subdirectory("${JOY_SOURCE_DIR}/SDL"     "${CMAKE_BINARY_DIR}/SDL")
include("${JOY_SOURCE_DIR}/joy_add.cmake")

# ---- 宿主可执行文件 --------------------------------------------------------
# C# 绑定层由 joy 子项目提供：MODULES csharp 会自动 add_subdirectory
# third_party/joy/modules/csharp 并链接 joy_module_csharp（OBJECT 库）。
add_executable(joy_csharp_test_app main.c)
joy_add_sources(joy_csharp_test_app MODULES csharp)

# ---- Visual Studio：把 C# 工程一并挂进生成的解决方案 -----------------------
# 仅 VS 生成器生效，其它生成器忽略。C# 仍由 dotnet build 产出 JoyGame.dll，
# 这里只为在 VS 里同时浏览 / 生成 C# 业务代码，不改变 cmake --build 的行为。
if(CMAKE_GENERATOR MATCHES "Visual Studio")
    include_external_msproject(
        JoyGame
        "${CMAKE_CURRENT_SOURCE_DIR}/csharp/JoyGame.csproj"
        TYPE "FAE04EC0-301F-11D3-BF4B-00C04F79EFBC"
        PLATFORM "Any CPU")
    # C# 工程只有 Debug/Release 两个配置；把 CMake 的 MinSizeRel /
    # RelWithDebInfo 映射过去，否则 VS 会提示「配置映射不正确」。
    set_property(TARGET JoyGame PROPERTY MAP_IMPORTED_CONFIG_MINSIZEREL Release)
    set_property(TARGET JoyGame PROPERTY MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release)
endif()

# ---- 运行期产物：assets/ + JoyGame.dll + CoreCLR 运行时与 BCL ---------------
set(_app_out "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>")

add_custom_command(TARGET joy_csharp_test_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/assets" "${_app_out}/assets"
    COMMENT "Copying assets")

if(EXISTS "${JOY_GAME_DLL}")
    add_custom_command(TARGET joy_csharp_test_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${JOY_GAME_DLL}" "${_app_out}/JoyGame.dll"
        COMMENT "Copying JoyGame.dll")
else()
    message(WARNING
        "未找到 JoyGame.dll（${JOY_GAME_DLL}）：先执行 "
        "dotnet build csharp/JoyGame.csproj -c Release -o build/csharp")
endif()

if(EXISTS "${MONO_RUNTIME_DLL}")
    add_custom_command(TARGET joy_csharp_test_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${MONO_RUNTIME_DLL}" "${_app_out}/coreclr.dll"
        COMMENT "Copying coreclr.dll")
else()
    message(WARNING "未找到运行时 ${MONO_RUNTIME_DLL}：coreclr.dll 需与 exe 同目录")
endif()

if(EXISTS "${JOY_CLR_LIB_DIR}")
    add_custom_command(TARGET joy_csharp_test_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${_app_out}/lib"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${JOY_CLR_LIB_DIR}" "${_app_out}/lib"
        COMMENT "Copying .NET BCL (lib/)")
else()
    message(WARNING "未找到 BCL 目录 ${JOY_CLR_LIB_DIR}：运行时需要 lib/ 与 exe 同目录")
endif()

# ---- 冒烟测试 --------------------------------------------------------------
enable_testing()
if(EXISTS "${JOY_GAME_DLL}")
    add_test(NAME joy_csharp_test_smoke COMMAND joy_csharp_test_app --smoke 180)
    set_tests_properties(joy_csharp_test_smoke PROPERTIES
        WORKING_DIRECTORY "${_app_out}"
        ENVIRONMENT "SDL_VIDEODRIVER=dummy")
endif()
