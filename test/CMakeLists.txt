# ============================================================
# C++ 端到端测试宿主：链接 joy 核心 + 本仓 C# 绑定模块，
# 加载 JoyTest.dll 并验证 C++ → C#、C# → C++ 双向调用。
#
# 用法（在 test/ 目录）：
#   cmake -S . -B ../build/e2e -DJOY_SOURCE_DIR=<含 joy.h 的目录> \
#         -DMONO_INCLUDE_DIR=... -DMONO_LIBRARIES=...
#   cmake --build ../build/e2e --config Release
# ============================================================
cmake_minimum_required(VERSION 3.16)
project(joy_csharp_e2e C CXX)

# ---- joy 源码树（其下有 joy.h）---------------------------------------------
set(JOY_SOURCE_DIR "" CACHE PATH "joy 源码目录（其下须有 joy.h）")
if(NOT EXISTS "${JOY_SOURCE_DIR}/joy.h")
    foreach(_joy_cand
        "${CMAKE_CURRENT_SOURCE_DIR}/../../joy"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../joy_topdown_template/third_party/joy")
        if(EXISTS "${_joy_cand}/joy.h")
            set(JOY_SOURCE_DIR "${_joy_cand}" CACHE PATH "joy 源码目录（其下须有 joy.h）" FORCE)
            break()
        endif()
    endforeach()
endif()
if(NOT EXISTS "${JOY_SOURCE_DIR}/joy.h")
    message(FATAL_ERROR
        "joy_csharp_e2e: 找不到 joy 源码树，请设置 -DJOY_SOURCE_DIR=<含 joy.h 的目录>")
endif()

# ---- Mono 开发包 -----------------------------------------------------------
set(MONO_INCLUDE_DIR "C:/Program Files/Mono/include/mono-2.0" CACHE PATH "Mono include")
set(MONO_LIBRARIES   "C:/Program Files/Mono/lib/mono-2.0-sgen.lib" CACHE FILEPATH "Mono lib")

# ---- joy 依赖的第三方工程 ---------------------------------------------------
add_subdirectory("${JOY_SOURCE_DIR}/msgpack" "${CMAKE_BINARY_DIR}/msgpack")
add_subdirectory("${JOY_SOURCE_DIR}/spine"   "${CMAKE_BINARY_DIR}/spine")
add_subdirectory("${JOY_SOURCE_DIR}/SDL"     "${CMAKE_BINARY_DIR}/SDL")
include("${JOY_SOURCE_DIR}/joy_add.cmake")

# ---- 测试宿主 --------------------------------------------------------------
add_executable(joy_csharp_e2e main.c)
# joy 核心源码直接编入（脚本模块由本仓提供，故不传 MODULES）
joy_add_sources(joy_csharp_e2e)
target_include_directories(joy_csharp_e2e PRIVATE "${MONO_INCLUDE_DIR}")

# 本仓即 C# 绑定模块
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/.." "${CMAKE_BINARY_DIR}/joy_csharp")
target_link_libraries(joy_csharp_e2e PRIVATE joy_csharp)

# ---- 运行时产物：exe 需与 JoyTest.dll / hello.txt 同目录 --------------------
# JoyTest.dll 由 dotnet build 产出（见 README），这里只做提示，不参与编译。
