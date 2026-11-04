# ============================================================
# C# 业务模板的 C++ 宿主（Windows / MSVC）
#
# 结构：
#   app/main.c   创建窗口 + 主循环 + 事件泵，每帧回调 C# Host.OnFrame
#   ../          本仓的 C# 绑定模块（joy_csharp 静态库）
#   ../csharp    C# 业务程序集 JoyGame.dll（dotnet build 产出）
#
# 用法（在 app/ 目录，joy 默认取仓内子模块 third_party/joy）：
#   cmake -S . -B ../build/app -A x64 \
#         -DMONO_INCLUDE_DIR=... -DMONO_LIBRARIES=...
#   cmake --build ../build/app --config Release
# ============================================================
cmake_minimum_required(VERSION 3.16)
project(joy_csharp_app C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# ---- joy 源码树（其下有 joy.h）---------------------------------------------
# 默认用仓内子模块 third_party/joy（git submodule update --init），
# 也兼容与 joy 源码树同级、或从别的工程里复用 joy 的场景。
set(JOY_SOURCE_DIR "" CACHE PATH "joy 源码目录（其下须有 joy.h）")
if(NOT EXISTS "${JOY_SOURCE_DIR}/joy.h")
    foreach(_joy_cand
        "${CMAKE_CURRENT_SOURCE_DIR}/../third_party/joy"
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
        "joy_csharp_app: 找不到 joy 源码树，请设置 -DJOY_SOURCE_DIR=<含 joy.h 的目录>")
endif()

# ---- Mono 开发包 -----------------------------------------------------------
set(MONO_INCLUDE_DIR "C:/Program Files/Mono/include/mono-2.0" CACHE PATH "Mono include")
set(MONO_LIBRARIES   "C:/Program Files/Mono/lib/mono-2.0-sgen.lib" CACHE FILEPATH "Mono lib")
# 运行期需要把 mono 运行时 DLL 放到 exe 旁边
set(MONO_RUNTIME_DLL "C:/Program Files/Mono/bin/mono-2.0-sgen.dll" CACHE FILEPATH "Mono runtime DLL")

# ---- C# 业务程序集 ---------------------------------------------------------
set(JOY_GAME_DLL "${CMAKE_CURRENT_SOURCE_DIR}/../build/csharp/JoyGame.dll"
    CACHE FILEPATH "JoyGame.dll（dotnet build -o build/csharp 的产物）")

# ---- joy 依赖的第三方工程 ---------------------------------------------------
add_subdirectory("${JOY_SOURCE_DIR}/msgpack" "${CMAKE_BINARY_DIR}/msgpack")
add_subdirectory("${JOY_SOURCE_DIR}/spine"   "${CMAKE_BINARY_DIR}/spine")
add_subdirectory("${JOY_SOURCE_DIR}/SDL"     "${CMAKE_BINARY_DIR}/SDL")
include("${JOY_SOURCE_DIR}/joy_add.cmake")

# ---- 宿主可执行文件 --------------------------------------------------------
add_executable(joy_csharp_app main.c)
joy_add_sources(joy_csharp_app)
target_include_directories(joy_csharp_app PRIVATE "${MONO_INCLUDE_DIR}")

# 本仓即 C# 绑定模块
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/.." "${CMAKE_BINARY_DIR}/joy_csharp")
target_link_libraries(joy_csharp_app PRIVATE joy_csharp)

# ---- 运行期产物：assets/ + JoyGame.dll + mono 运行时 ------------------------
set(_app_out "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>")

add_custom_command(TARGET joy_csharp_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/../assets" "${_app_out}/assets"
    COMMENT "Copying assets")

if(EXISTS "${JOY_GAME_DLL}")
    add_custom_command(TARGET joy_csharp_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${JOY_GAME_DLL}" "${_app_out}/JoyGame.dll"
        COMMENT "Copying JoyGame.dll")
else()
    message(WARNING
        "未找到 JoyGame.dll（${JOY_GAME_DLL}）：先执行 "
        "dotnet build csharp/JoyGame.csproj -c Release -o build/csharp")
endif()

if(EXISTS "${MONO_RUNTIME_DLL}")
    add_custom_command(TARGET joy_csharp_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${MONO_RUNTIME_DLL}" "${_app_out}/mono-2.0-sgen.dll"
        COMMENT "Copying mono runtime")
else()
    message(WARNING "未找到 Mono 运行时 ${MONO_RUNTIME_DLL}：运行时需要 mono-2.0-sgen.dll 与 exe 同目录")
endif()

# ---- 冒烟测试 --------------------------------------------------------------
enable_testing()
if(EXISTS "${JOY_GAME_DLL}")
    add_test(NAME joy_csharp_smoke COMMAND joy_csharp_app --smoke 180)
    set_tests_properties(joy_csharp_smoke PROPERTIES
        WORKING_DIRECTORY "${_app_out}"
        ENVIRONMENT "SDL_VIDEODRIVER=dummy")
endif()
