#!/usr/bin/env node
/*
 * 从 joy.h 生成 C#(Mono) csclib 源码。
 *
 * 用法（任意目录）：
 *     node tools/gen_csclib.js [--joy <joy 源码目录>]
 *
 * joy 源码目录（其下须有 joy.h）优先级：--joy 参数 > 环境变量 JOY_DIR > 同级 ../joy。
 *
 * 产出：
 *     csclib/generated/csclib_generated.c
 *     csclib/generated/csclib_generated.h
 *     csharp/Joy/InternalCalls.cs
 *
 * 只生成“可安全自动转换”的函数子集：
 *     - 标量（int/uint32/float/double/bool/...）-> 同名 C# 类型
 *     - const char* / char* 入参 -> string（wrapper 内 mono_string_to_utf8）
 *     - 不透明指针 *_p、void* -> IntPtr
 *     - 小结构体（字段全标量、<=16 字节）按值传递 -> C# [StructLayout(Sequential)]
 * 跳过：
 *     - 返回 char*（释放约定因函数而异，需人工指定）
 *     - 结构体指针、结构体返回值、数组、函数指针、可变参数、输出参数（T*）
 *       （绘制热点由 csclib/draw.c 的扁平包装覆盖）
 *     - utils_ 前缀（由 csclib/utils.c 手写 POC 提供，避免重复注册）
 */
'use strict';

const fs = require('fs');
const path = require('path');

const HERE = __dirname;
// 两种落地布局都支持：
//   独立仓 joy_csharp：tools/ 在仓根            → 模块根 = 仓根
//   joy 主仓：          modules/csharp/tools     → 模块根 = modules/csharp，joy.h 在仓根
const REPO = path.resolve(HERE, '..');
const JOY_REPO = path.resolve(HERE, '../../..');
const IN_JOY_REPO = fs.existsSync(path.join(JOY_REPO, 'joy.h'));
const MODULE = IN_JOY_REPO ? path.join(JOY_REPO, 'modules/csharp') : REPO;

function resolveJoyDir() {
  const i = process.argv.indexOf('--joy');
  if (i !== -1 && process.argv[i + 1]) return path.resolve(process.argv[i + 1]);
  if (process.env.JOY_DIR) return path.resolve(process.env.JOY_DIR);
  if (IN_JOY_REPO) return JOY_REPO;          /* joy 主仓：joy.h 就在仓根 */
  return path.resolve(REPO, '../joy');
}

const JOY_DIR = resolveJoyDir();
const JOY_H = path.join(JOY_DIR, 'joy.h');
if (!fs.existsSync(JOY_H)) {
  console.error(`未找到 ${JOY_H}，请用 --joy <joy 源码目录>（其下须有 joy.h）指定`);
  process.exit(1);
}
const OUT_C = path.join(MODULE, 'csclib/generated/csclib_generated.c');
const OUT_H = path.join(MODULE, 'csclib/generated/csclib_generated.h');
const OUT_CS = path.join(MODULE, 'csharp/Joy/InternalCalls.cs');

// ---- 结构体（按值传递）----------------------------------------------------
// 只收「字段全为标量且总大小 <= 16 字节」的结构体：这类在 x64 上按值传递最稳，
// C# 侧用 [StructLayout(Sequential)] 对齐即可。指针参数（const jrect_t*）与
// 结构体返回值仍然跳过——绘制类热点由 csclib/draw.c 的扁平包装覆盖。
const FIELD_CS = {
  float: 'float', ft_t: 'float', double: 'double',
  bool: 'bool',
  int: 'int', int32_t: 'int',
  int16_t: 'short', uint16_t: 'ushort',
  uint8_t: 'byte', uint32_t: 'uint', uint64_t: 'ulong',
  int64_t: 'long', fp_t: 'long',
  size_t: 'nuint',
};
const FIELD_SIZE = {
  float: 4, double: 8, bool: 1, int: 4, short: 2, ushort: 2,
  byte: 1, uint: 4, ulong: 8, long: 8, nuint: 8,
};
const STRUCT_SOURCES = [JOY_H, path.join(JOY_DIR, 'jmath.h')];

function parseStructs() {
  const out = new Map();
  for (const file of STRUCT_SOURCES) {
    if (!fs.existsSync(file)) continue;
    const src = stripComments(fs.readFileSync(file, 'utf8'));
    const re = /typedef\s+struct\s*\w*\s*\{([^}]*)\}\s*(\w+)\s*;/g;
    let m;
    while ((m = re.exec(src)) !== null) {
      const name = m[2];
      if (!name.endsWith('_t')) continue;
      const fields = [];
      let ok = true;
      let size = 0;
      for (const raw of m[1].split(';')) {
        const decl = raw.trim();
        if (!decl) continue;
        const dm = decl.match(/^(.+?)\s+([A-Za-z_]\w*(?:\s*,\s*\w+)*)$/s);
        if (!dm) { ok = false; break; }
        const cs = FIELD_CS[normType(dm[1])];
        if (!cs) { ok = false; break; }
        for (const n of dm[2].split(',')) {
          fields.push([cs, n.trim()]);
          size += FIELD_SIZE[cs];
        }
      }
      if (ok && fields.length && size <= 16) out.set(name, fields);
    }
  }
  return out;
}

const STRUCTS = parseStructs();

// 跳过的函数前缀：
//   utils_            —— 由 csclib/utils.c 手工实现（避免重复注册）
//   jspine_           —— 声明位于 #ifdef JOY_USE_SPINE 下，未启用时类型不存在
//   modules_ / module_instance_ —— jmodule.c 默认不参与编译（插件系统停用）
// 跳过的具体函数名：
//   jecs_test         —— 测试用符号，未被链接
const SKIP_PREFIXES = ['utils_', 'jspine_', 'modules_', 'module_instance_'];
const SKIP_NAMES = ['jecs_test'];

const SCALAR_C = {
  void: 'void',
  bool: 'bool',
  int: 'int',
  int32_t: 'int',
  uint32_t: 'uint32_t',
  'unsigned int': 'unsigned int',
  unsigned: 'unsigned int',
  int64_t: 'int64_t',
  uint64_t: 'uint64_t',
  float: 'float',
  double: 'double',
  size_t: 'size_t',
};

const SCALAR_CS = {
  void: 'void',
  bool: 'bool',
  int: 'int',
  int32_t: 'int',
  uint32_t: 'uint',
  'unsigned int': 'uint',
  unsigned: 'uint',
  int64_t: 'long',
  uint64_t: 'ulong',
  float: 'float',
  double: 'double',
  size_t: 'nuint',
};

const CS_KEYWORDS = new Set([
  'abstract', 'as', 'base', 'bool', 'break', 'byte', 'case', 'catch', 'char', 'checked', 'class',
  'const', 'continue', 'decimal', 'default', 'delegate', 'do', 'double', 'else', 'enum', 'event',
  'explicit', 'extern', 'false', 'finally', 'fixed', 'float', 'for', 'foreach', 'goto', 'if',
  'implicit', 'in', 'int', 'interface', 'internal', 'is', 'lock', 'long', 'namespace', 'new',
  'null', 'object', 'operator', 'out', 'override', 'params', 'private', 'protected', 'public',
  'readonly', 'ref', 'return', 'sbyte', 'sealed', 'short', 'sizeof', 'stackalloc', 'static',
  'string', 'struct', 'switch', 'this', 'throw', 'true', 'try', 'typeof', 'uint', 'ulong',
  'unchecked', 'unsafe', 'ushort', 'using', 'virtual', 'void', 'volatile', 'while',
]);

function csIdent(name) {
  return CS_KEYWORDS.has(name) ? '@' + name : name;
}

function stripComments(s) {
  return s.replace(/\/\*[\s\S]*?\*\//g, '').replace(/\/\/[^\n]*/g, '');
}

function normType(t) {
  t = t.replace(/\bconst\b/g, ' ');
  t = t.replace(/\s+/g, ' ').trim();
  t = t.replace(/\s*\*\s*/g, '*');
  return t;
}

function isOpaquePtr(t) {
  return t.endsWith('_p') && !t.includes('*');
}

function paramKind(t, isConst) {
  if (t === 'char*') return isConst ? 'string' : null; /* 非 const char* 可能是输出缓冲，跳过 */
  if (t === 'void*' || isOpaquePtr(t)) return 'ptr';
  if (SCALAR_C[t] && t !== 'void') return 'scalar';
  if (STRUCTS.has(t)) return 'struct';
  return null;
}

function retKind(t) {
  if (t === 'void') return 'void';
  if (t === 'void*' || isOpaquePtr(t)) return 'ptr';
  if (SCALAR_C[t]) return 'scalar';
  return null; /* 结构体返回值仍跳过（Mono 对按值返回结构体的支持不稳） */
}

function cType(t) {
  if (t === 'char*') return 'MonoString*';
  if (t === 'void*' || isOpaquePtr(t)) return 'intptr_t';
  if (STRUCTS.has(t)) return t;
  return SCALAR_C[t];
}

function csType(t) {
  if (t === 'char*') return 'string';
  if (t === 'void*' || isOpaquePtr(t)) return 'IntPtr';
  if (STRUCTS.has(t)) return t;
  return SCALAR_CS[t];
}

function parseParams(raw) {
  raw = raw.trim();
  if (!raw || raw === 'void') return [];
  if (raw.includes('...') || raw.includes('(*')) return null;
  const parts = raw.split(',');
  const out = [];
  for (let p of parts) {
    p = p.trim();
    if (p.includes('[') || p.endsWith(')')) return null;
    const m = p.match(/^(.*?)([A-Za-z_]\w*)\s*$/s);
    if (!m) return null;
    const rawType = m[1];
    out.push([normType(rawType), m[2], /\bconst\b/.test(rawType)]);
  }
  return out;
}

function parseDecls(src) {
  src = stripComments(src);
  const decls = [];
  const re = /JOY_API\s+([^;]+);/g;
  let m;
  while ((m = re.exec(src)) !== null) {
    const body = m[1].replace(/\s+/g, ' ').trim();
    const mm = body.match(/^(.+?)\s+([A-Za-z_]\w*)\s*\((.*)\)$/);
    if (!mm) continue;
    decls.push([normType(mm[1]), mm[2], mm[3]]);
  }
  return decls;
}

function className(func) {
  const prefix = func.split('_')[0];
  if (!prefix) return 'Native';
  return prefix.charAt(0).toUpperCase() + prefix.slice(1);
}

function gen() {
  const src = fs.readFileSync(JOY_H, 'utf8');
  const supported = [];
  const skipped = [];
  const seen = new Set();

  for (const [ret, name, rawParams] of parseDecls(src)) {
    if (seen.has(name)) continue;
    seen.add(name);
    if (SKIP_NAMES.includes(name) || SKIP_PREFIXES.some((p) => name.startsWith(p))) {
      skipped.push([name, 'manual']);
      continue;
    }
    if (retKind(ret) === null) {
      skipped.push([name, 'ret:' + ret]);
      continue;
    }
    const params = parseParams(rawParams);
    if (params === null) {
      skipped.push([name, 'params']);
      continue;
    }
    if (params.some(([t, , c]) => paramKind(t, c) === null)) {
      skipped.push([name, 'param-type']);
      continue;
    }
    supported.push([ret, name, params]);
  }

  // ---- C 包装层 ----
  const c = [];
  c.push('/* 自动生成，勿手改：tools/gen_csclib.js */');
  c.push('#include <stdint.h>');
  c.push('#include <mono/metadata/object.h>');
  c.push('#include <mono/metadata/appdomain.h>');
  c.push('#include "csclib.h"');
  c.push('#include "joy_csharp.h"');
  c.push('#include <joy/joy.h>');
  c.push('');

  for (const [ret, name, params] of supported) {
    const rk = retKind(ret);
    const cRet = rk === 'void' ? 'void' : cType(ret);
    const sig = params.length
      ? params.map(([t, n]) => `${cType(t)} ${n}`).join(', ')
      : 'void';
    c.push(`static ${cRet} w_${name}(${sig})`);
    c.push('{');
    const callArgs = [];
    const strParams = [];
    for (const [t, n, isConst] of params) {
      const k = paramKind(t, isConst);
      if (k === 'string') {
        c.push(`        char* s_${n} = mono_string_to_utf8(${n});`);
        callArgs.push(`s_${n}`);
        strParams.push(n);
      } else if (k === 'ptr') {
        callArgs.push(`(${t})${n}`);
      } else {
        callArgs.push(n);
      }
    }
    const args = callArgs.join(', ');
    if (rk === 'void') {
      c.push(`        ${name}(${args});`);
    } else {
      c.push(`        ${cRet} _ret = ${rk === 'ptr' ? '(intptr_t)' : ''}${name}(${args});`);
    }
    for (const n of strParams) c.push(`        mono_free(s_${n});`);
    if (rk !== 'void') c.push('        return _ret;');
    c.push('}');
    c.push('');
  }

  c.push('void csopen_generated(void)');
  c.push('{');
  for (const [, name] of supported) {
    c.push(
      `        csx_register_internal_call("Joy.${className(name)}::${name}", (const void*)w_${name});`
    );
  }
  c.push('}');
  c.push('');

  // ---- C 头 ----
  const h = [
    '/* 自动生成，勿手改：tools/gen_csclib.js */',
    '#ifndef JOY_CSCLIB_GENERATED_H',
    '#define JOY_CSCLIB_GENERATED_H',
    '',
    '#ifdef __cplusplus',
    'extern "C" {',
    '#endif',
    '',
    'void csopen_generated(void);',
    '',
    '#ifdef __cplusplus',
    '}',
    '#endif',
    '',
    '#endif /* JOY_CSCLIB_GENERATED_H */',
    '',
  ];

  // ---- C# 声明 ----
  const groups = new Map();
  const usedStructs = new Set();
  for (const [ret, name, params] of supported) {
    const cls = className(name);
    if (!groups.has(cls)) groups.set(cls, []);
    groups.get(cls).push([ret, name, params]);
    for (const [t] of params) {
      if (STRUCTS.has(t)) usedStructs.add(t);
    }
  }

  const cs = [
    '// 自动生成，勿手改：tools/gen_csclib.js',
    'using System;',
    'using System.Runtime.CompilerServices;',
    'using System.Runtime.InteropServices;',
    '',
    'namespace Joy',
    '{',
  ];

  // blittable 结构体（字段顺序/大小与 C 侧一致，按值传给 internal call）
  for (const name of [...usedStructs].sort()) {
    cs.push(`    // C: typedef struct { ... } ${name};`);
    cs.push('    [StructLayout(LayoutKind.Sequential)]');
    cs.push(`    public struct ${name}`);
    cs.push('    {');
    for (const [ct, fn] of STRUCTS.get(name)) {
      cs.push(`        public ${ct} ${fn};`);
    }
    cs.push('    }');
    cs.push('');
  }
  for (const cls of [...groups.keys()].sort()) {
    cs.push(`    internal static class ${cls}`);
    cs.push('    {');
    const list = groups.get(cls).slice().sort((a, b) => a[1].localeCompare(b[1]));
    for (const [ret, name, params] of list) {
      const ps = params.map(([t, n]) => `${csType(t)} ${csIdent(n)}`).join(', ');
      cs.push('        [MethodImpl(MethodImplOptions.InternalCall)]');
      cs.push(`        public static extern ${csType(ret)} ${name}(${ps});`);
      cs.push('');
    }
    cs.push('    }');
    cs.push('');
  }
  cs.push('}');
  cs.push('');

  fs.mkdirSync(path.dirname(OUT_C), { recursive: true });
  fs.mkdirSync(path.dirname(OUT_CS), { recursive: true });
  fs.writeFileSync(OUT_C, c.join('\n'), 'utf8');
  fs.writeFileSync(OUT_H, h.join('\n'), 'utf8');
  fs.writeFileSync(OUT_CS, cs.join('\n'), 'utf8');

  console.log(`generated: ${supported.length} functions, skipped: ${skipped.length}`);
  console.log(`  ${OUT_C}`);
  console.log(`  ${OUT_H}`);
  console.log(`  ${OUT_CS}`);
}

gen();
