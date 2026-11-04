# ============================================================
# joy_csharp —— joy 的可选 C#(Mono) 脚本后端
#
# 依赖：
#   joy 源码树（其下有 joy.h）  默认用仓内子模块 third_party/joy，
#                              换源时才需 -DJOY_SOURCE_DIR=<含 joy.h 的目录>
#   Mono 开发包                -DMONO_INCLUDE_DIR=... -DMONO_LIBRARIES=...
#
# 用法：
#   git submodule update --init --recursive
#   单独构建：cmake -S . -B build ...
#   上层工程：add_subdirectory(joy_csharp) 后 target_link_libraries(<t> PRIVATE joy_csharp)
#
# 未启用本模块时 joy 核心不需要 Mono，也不依赖本仓。
# ============================================================
cmake_minimum_required(VERSION 3.16)

# 作为仓库根 CMakeLists 使用时自带 project()；被上层 add_subdirectory 时跳过。
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(joy_csharp C)
endif()

if(TARGET joy_csharp)
    return()
endif()

# ---- joy 源码树定位 ---------------------------------------------------------
# 默认用仓内子模块 third_party/joy（git submodule update --init），
# 其次找同级 joy/ 或 joy_topdown_template/third_party/joy。
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
        "joy_csharp: 找不到 joy 源码树，请设置 -DJOY_SOURCE_DIR=<含 joy.h 的目录>")
endif()

# ---- Mono 开发包 -----------------------------------------------------------
set(MONO_INCLUDE_DIR "" CACHE PATH "Mono 头文件目录（mono/metadata/*.h 所在目录）")
set(MONO_LIBRARIES "" CACHE FILEPATH "Mono 库（如 mono-2.0-sgen.lib）")
if(NOT MONO_INCLUDE_DIR OR NOT MONO_LIBRARIES)
    message(FATAL_ERROR
        "joy_csharp: 本模块需要 Mono 开发包，请设置 -DMONO_INCLUDE_DIR 与 -DMONO_LIBRARIES")
endif()

# ---- 模块本体 --------------------------------------------------------------
file(GLOB JOY_CS_CLIB CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/csclib/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/csclib/generated/*.c")

add_library(joy_csharp STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/joy_csharp.c"
    ${JOY_CS_CLIB})

target_include_directories(joy_csharp PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/csclib"
    "${CMAKE_CURRENT_SOURCE_DIR}/csclib/generated")
# 使 #include <joy/joy.h> 成立（joy 源码位于 <根>/joy/，根为其父目录）
target_include_directories(joy_csharp PRIVATE
    "${JOY_SOURCE_DIR}/.."
    "${MONO_INCLUDE_DIR}")

# 开关宏以 PUBLIC 传递：宿主侧 joy_script_stub.c 据此关闭桩实现
target_compile_definitions(joy_csharp PUBLIC ENABLED_CSHARP_SCRIPT JOY_STATIC)
target_link_libraries(joy_csharp PUBLIC ${MONO_LIBRARIES})

# joy.h 会 #include <SDL3/SDL_events.h>：上层已建 SDL3 目标时借用，
# 独立构建时退回 joy 源码树内自带的 SDL 头文件目录。
if(TARGET SDL3::SDL3)
    target_link_libraries(joy_csharp PUBLIC SDL3::SDL3)
elseif(EXISTS "${JOY_SOURCE_DIR}/SDL/include")
    target_include_directories(joy_csharp PUBLIC "${JOY_SOURCE_DIR}/SDL/include")
endif()

set_target_properties(joy_csharp PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON)

if(MSVC)
    # 源码为 UTF-8 无 BOM（含中文注释），避免 C4819；/wd4206 兼容全注释翻译单元
    target_compile_options(joy_csharp PRIVATE /utf-8 /wd4206)
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/joy_csharp.c" ${JOY_CS_CLIB})
