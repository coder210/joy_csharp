/* C# ↔ joy C API 胶水层：utils 模块（POC）。
 *
 * wrapper 负责 MonoString ↔ char* 转换，再调用 joy 原始 API。
 * 注册名格式 Joy.<类>::<方法>，与 C# 侧 [MethodImpl(InternalCall)] 对应。
 * 下方保留的注释是旧实现参考（livS_ 前缀，未启用）。 */
#include <stdint.h>
#include <stdlib.h>
#include <mono/metadata/object.h>
#include <mono/metadata/appdomain.h>
#include <SDL3/SDL_stdinc.h>
#include "csclib.h"
#include "joy_csharp.h"
#include <joy/joy.h>

static bool w_utils_check_file(MonoString* filename)
{
        char* s = mono_string_to_utf8(filename);
        bool r = utils_check_file(s);
        mono_free(s);
        return r;
}

static MonoString* w_utils_read_file(MonoString* filename)
{
        char* s = mono_string_to_utf8(filename);
        size_t n = 0;
        char* data = utils_read_file(s, &n);
        mono_free(s);
        if (!data) return NULL;
        MonoString* ret = mono_string_new_len(mono_domain_get(), data, (uint32_t)n);
        SDL_free(data);
        return ret;
}

static intptr_t w_utils_random_create(uint32_t seed)
{
        return (intptr_t)utils_random_create(seed);
}

static uint32_t w_utils_random_next(intptr_t rnum)
{
        return utils_random_next((random_num_p)rnum);
}

static void w_utils_random_destroy(intptr_t rnum)
{
        utils_random_destroy((random_num_p)rnum);
}

void csopen_utils(void)
{
        csx_register_internal_call("Joy.Utils::utils_check_file", (const void*)w_utils_check_file);
        csx_register_internal_call("Joy.Utils::utils_read_file", (const void*)w_utils_read_file);
        csx_register_internal_call("Joy.Utils::utils_random_create", (const void*)w_utils_random_create);
        csx_register_internal_call("Joy.Utils::utils_random_next", (const void*)w_utils_random_next);
        csx_register_internal_call("Joy.Utils::utils_random_destroy", (const void*)w_utils_random_destroy);
}

// ---- 以下为旧实现参考（livS_ 前缀，未启用）----
//#include <stdbool.h>
//#include "../mono.h"
//#include "../utils.h"
//#include "csclib.h"
//
//
//static int current_datetime(MonoString* format)
//{
//        char buf[JOY_MAX_BUFFER];
//        memset(buf, 0, JOY_MAX_BUFFER);
//        utils_current_datetime(livS_mono_string_to_utf8(format), buf, JOY_MAX_BUFFER);
//        livS_mono_free(format);
//        return 1;
//}
//
//static int64_t current_time()
//{
//        int64_t time;
//        utils_get_current_time(&time);
//        return time;
//}
//
//static int bit2short(MonoArray* bytes)
//{
//        int result, len;
//        char* buf;
//        len = livS_mono_array_length(bytes);
//        buf = livS_mono_array_addr(bytes, sizeof(char), 0);
//        result = utils_bit2short((uint8_t*)buf);
//        return result;
//}
//
//static MonoArray* short2bit(short value)
//{
//        MonoArray* bytes;
//        MonoDomain* domain;
//        char buf[2];
//        char* data;
//        int len;
//
//        len = 2;
//        utils_short2bit((uint8_t*)buf, value);
//        domain = livS_mono_domain_get();
//        bytes = livS_mono_array_new(domain, livS_mono_get_byte_class(), len);
//        data = livS_mono_array_addr(bytes, sizeof(char), 0);
//        for (int i = 0; i < len; i++) {
//                data[i] = buf[i];
//        }
//        return bytes;
//}
//
//static int bit2int(MonoArray* bytes)
//{
//        int result, len;
//        char* buf;
//        len = livS_mono_array_length(bytes);
//        buf = livS_mono_array_addr(bytes, sizeof(char), 0);
//        result = utils_bit2int((uint8_t*)buf);
//        return result;
//}
//
//static MonoArray* int2bit(short value)
//{
//        MonoArray* bytes;
//        MonoDomain* domain;
//        int len;
//        char buf[4];
//        char* data;
//
//        len = 4;
//        utils_int2bit((uint8_t*)buf, value);
//        domain = livS_mono_domain_get();
//        bytes = livS_mono_array_new(domain, livS_mono_get_byte_class(), len);
//        data = livS_mono_array_addr(bytes, sizeof(char), 0);
//        for (int i = 0; i < len; i++) {
//                data[i] = buf[i];
//        }
//        return bytes;
//
//}
//
//static MonoString* cs_md5(MonoString* input)
//{
//        MonoDomain* domain;
//        short len;
//        char output[64];
//        size_t input_len;
//        char* raw_input;
//        domain = livS_mono_domain_get();
//        raw_input = livS_mono_string_to_utf8(input);
//        input_len = livS_mono_string_length(input);
//        len = utils_md5x(raw_input, input_len, output);
//        livS_mono_free(input);
//        return livS_mono_string_new_len(domain, output, len);
//}
//
//
//static MonoString* md5x(MonoString* input)
//{
//        const char* raw_input;
//        size_t input_len;
//        char output[64];
//        short n;
//        raw_input = livS_mono_string_to_utf8(input);
//        input_len = livS_mono_string_length(input);
//        livS_mono_free(input);
//        n = utils_md5x(raw_input, input_len, output);
//        return livS_mono_string_new_len(livS_mono_domain_get(), output, n);
//}
//
//static MonoString*
//cs_b64_encode(MonoString* input)
//{
//        MonoDomain* domain;
//        size_t size;
//        const char* raw_input;
//        char* result;
//
//        domain = livS_mono_domain_get();
//        raw_input = livS_mono_string_to_utf8(input);
//        size = livS_mono_string_length(input);
//        livS_mono_free(input);
//
//        result = utils_b64_encode(raw_input, size);
//        return livS_mono_string_new_len(domain, result, size);
//}
//
//static MonoString*
//cs_b64_decode(MonoString* input)
//{
//        size_t size, de_size;
//        const char* raw_input;
//        char* result;
//        raw_input = livS_mono_string_to_utf8(input);
//        size = livS_mono_string_length(input);
//        result = utils_b64_decode(raw_input, size, &de_size);
//        livS_mono_free(input);
//        return livS_mono_string_new_len(livS_mono_domain_get(), result, de_size);
//}
//
//static MonoString*
//aes_encrypt256(MonoString* key, MonoString* iv, MonoString* input)
//{
//        MonoDomain* domain;
//        size_t key_len, iv_len, input_len, out_len;
//        const char* raw_key, * raw_iv, * raw_input;
//        unsigned char* raw_out;
//        MonoString* out;
//
//        raw_key = livS_mono_string_to_utf8(key);
//        key_len = livS_mono_string_length(key);
//        raw_iv = livS_mono_string_to_utf8(iv);
//        iv_len = livS_mono_string_length(iv);
//        raw_input = livS_mono_string_to_utf8(input);
//        input_len = livS_mono_string_length(input);
//
//        domain = livS_mono_domain_get();
//
//        if (key_len == 32) {
//                raw_out = utils_aes_encrypt256(raw_input, &out_len, raw_key, raw_iv);
//                out = livS_mono_string_new_len(domain, raw_out, out_len);
//                free(raw_out);
//        }
//        else {
//                out = livS_mono_string_empty(domain);
//        }
//
//        return out;
//}
//
//static MonoString*
//aes_decrypt256(MonoString* key, MonoString* iv, MonoString* input)
//{
//        size_t key_len, iv_len, input_len, out_len;
//        const char* raw_key, * raw_iv;
//        const char* raw_input;
//        unsigned char* raw_out;
//        MonoString* out;
//        MonoDomain* domain;
//
//        domain = livS_mono_domain_get();
//        raw_key = livS_mono_string_to_utf8(key);
//        key_len = livS_mono_string_length(key);
//        raw_iv = livS_mono_string_to_utf8(iv);
//        iv_len = livS_mono_string_length(iv);
//        raw_input = livS_mono_string_to_utf8(input);
//        input_len = livS_mono_string_length(input);
//        if (key_len == 32) {
//                raw_out = utils_aes_decrypt256(raw_input, &out_len, raw_key, raw_iv);
//                out = livS_mono_string_new_len(domain, raw_out, out_len);
//                free(raw_out);
//        }
//        else {
//                out = livS_mono_string_empty(domain);
//        }
//
//        return out;
//}
//
//static MonoString*
//aes_encrypt128(MonoString* key, MonoString* iv, MonoString* input)
//{
//        size_t key_len, input_len, iv_len;
//        const char* raw_key, * raw_iv;
//        const char* raw_input;
//        size_t out_len;
//        unsigned char* raw_out;
//        MonoString* out;
//        MonoDomain* domain;
//
//        domain = livS_mono_domain_get();
//        raw_key = livS_mono_string_to_utf8(key);
//        key_len = livS_mono_string_length(key);
//        raw_iv = livS_mono_string_to_utf8(iv);
//        iv_len = livS_mono_string_length(iv);
//        raw_input = livS_mono_string_to_utf8(input);
//        input_len = livS_mono_string_length(input);
//
//        if (key_len == 16) {
//                raw_out = utils_aes_encrypt128(raw_input, &out_len, raw_key, raw_iv);
//                out = livS_mono_string_new_len(domain, raw_out, out_len);
//                free(raw_out);
//        }
//        else {
//                out = livS_mono_string_empty(domain);
//        }
//        return out;
//}
//
//static MonoString*
//aes_decrypt128(MonoString* key, MonoString* iv, MonoString* input)
//{
//        size_t key_len, input_len, iv_len;
//        const char* raw_key, * raw_iv;
//        const char* raw_input;
//        size_t out_len;
//        unsigned char* raw_out;
//        MonoString* out;
//        MonoDomain* domain;
//
//        domain = livS_mono_domain_get();
//        raw_key = livS_mono_string_to_utf8(key);
//        key_len = livS_mono_string_length(key);
//        raw_iv = livS_mono_string_to_utf8(iv);
//        iv_len = livS_mono_string_length(iv);
//        raw_input = livS_mono_string_to_utf8(input);
//        input_len = livS_mono_string_length(input);
//
//
//        if (key_len == 16) {
//                raw_out = utils_aes_decrypt128(raw_input, &out_len, raw_key, raw_iv);
//                out = livS_mono_string_new_len(domain, raw_out, out_len);
//                free(raw_out);
//        }
//        else {
//                out = livS_mono_string_empty(domain);
//        }
//
//        return out;
//}
//
//static MonoString*
//des_encrypt(MonoString* key, MonoString* text)
//{
//        size_t keysz, textsz, out_len;
//        const char* raw_key, * raw_text;
//        char* result;
//        MonoString* str;
//        MonoDomain* domain;
//
//        domain = livS_mono_domain_get();
//        raw_key = livS_mono_string_to_utf8(key);
//        keysz = livS_mono_string_length(key);
//        raw_text = livS_mono_string_to_utf8(text);
//        textsz = livS_mono_string_length(text);
//        result = utils_des_crypt(raw_key, raw_text, textsz, &out_len);
//        str = livS_mono_string_new_len(domain, result, out_len);
//        SDL_free(result);
//        return str;
//}
//
//static MonoString*
//des_decrypt(MonoString* key, MonoString* text)
//{
//        size_t keysz, textsz, out_len;
//        const char* raw_key, * raw_text;
//        char* result;
//        MonoString* str;
//        MonoDomain* domain;
//
//        domain = livS_mono_domain_get();
//        raw_key = livS_mono_string_to_utf8(key);
//        keysz = livS_mono_string_length(key);
//        raw_text = livS_mono_string_to_utf8(text);
//        textsz = livS_mono_string_length(text);
//
//        result = utils_des_decrypt(raw_key, raw_text, textsz, &out_len);
//        str = livS_mono_string_new_len(domain, result, out_len);
//        SDL_free(result);
//        return str;
//}
//
//static bool
//encrypt_file(MonoString* path, MonoString* key, MonoString** filename)
//{
//        const char* raw_key, * raw_path;
//        char* data, * result, * new_file;
//        size_t path_len, new_file_sz, keysz, datasz, out_len;
//        bool ok;
//        MonoDomain* domain;
//
//        domain = livS_mono_domain_get();
//        raw_path = livS_mono_string_to_utf8(path);
//        path_len = livS_mono_string_length(path);
//        raw_key = livS_mono_string_to_utf8(key);
//        keysz = livS_mono_string_length(key);
//
//        data = (char*)SDL_LoadFile(raw_path, &datasz);
//        if (data) {
//                new_file_sz = sizeof(char) * (path_len + 2);
//                new_file = (char*)SDL_malloc(new_file_sz);
//                SDL_strlcpy(new_file, raw_path, new_file_sz);
//                SDL_strlcat(new_file, "s", new_file_sz);
//                new_file[path_len + 1] = 0;
//                result = utils_des_crypt(raw_key, data, datasz, &out_len);
//                ok = SDL_SaveFile(new_file, result, out_len);
//                *filename = livS_mono_string_new_len(domain, new_file, new_file_sz);
//                SDL_free(result);
//                SDL_free(data);
//                SDL_free(new_file);
//        }
//        else {
//                ok = false;
//                *filename = livS_mono_string_empty(domain);
//        }
//        return ok;
//}
//
//static bool
//decrypt_file(MonoString* path, MonoString* key, MonoString** filename)
//{
//        const char* raw_key, * raw_path;
//        char* data, * result, * new_file;
//        size_t path_len, new_file_sz, keysz, datasz, out_len;
//        bool ok;
//        MonoDomain* domain;
//
//        domain = livS_mono_domain_get();
//        raw_path = livS_mono_string_to_utf8(path);
//        path_len = livS_mono_string_length(path);
//        raw_key = livS_mono_string_to_utf8(key);
//        keysz = livS_mono_string_length(key);
//
//        data = (char*)SDL_LoadFile(raw_path, &datasz);
//        if (data) {
//                new_file_sz = sizeof(char) * (path_len + 1);
//                new_file = (char*)SDL_malloc(new_file_sz);
//                SDL_strlcpy(new_file, raw_path, new_file_sz - 1);
//                SDL_strlcat(new_file, "x", new_file_sz);
//                result = utils_des_decrypt(raw_key, data, datasz, &out_len);
//                ok = SDL_SaveFile(new_file, result, out_len);
//                *filename = livS_mono_string_new_len(domain, new_file, new_file_sz);
//                SDL_free(result);
//                SDL_free(data);
//                SDL_free(new_file);
//        }
//        else {
//                ok = false;
//                *filename = livS_mono_string_empty(domain);
//        }
//
//        return ok;
//}
//
//
//
//
//void csopen_utils()
//{
//      
//        livS_mono_add_internal_call("Joy.Utils::CurrentDatetime", current_datetime);
//        livS_mono_add_internal_call("Joy.Utils::CurrentTime", current_time);
//        livS_mono_add_internal_call("Joy.Utils::Bit2Short", bit2short);
//        livS_mono_add_internal_call("Joy.Utils::Short2Bit", short2bit);
//        livS_mono_add_internal_call("Joy.Utils::Bit2Int", bit2int);
//        livS_mono_add_internal_call("Joy.Utils::Int2Bit", int2bit);
//        livS_mono_add_internal_call("Joy.Utils::Md5", cs_md5);
//        livS_mono_add_internal_call("Joy.Utils::Md5x", md5x);
//        livS_mono_add_internal_call("Joy.Utils::B64Encode", cs_b64_encode);
//        livS_mono_add_internal_call("Joy.Utils::B64Decode", cs_b64_decode);
//        livS_mono_add_internal_call("Joy.Utils::AesEncrypt256", aes_encrypt256);
//        livS_mono_add_internal_call("Joy.Utils::AesDecrypt256", aes_decrypt256);
//        livS_mono_add_internal_call("Joy.Utils::AesEncrypt128", aes_encrypt128);
//        livS_mono_add_internal_call("Joy.Utils::AesDecrypt128", aes_decrypt128);
//        livS_mono_add_internal_call("Joy.Utils::DesEncrypt", des_encrypt);
//        livS_mono_add_internal_call("Joy.Utils::DesDecrypt", des_decrypt);
//        livS_mono_add_internal_call("Joy.Utils::EncryptFile", encrypt_file);
//        livS_mono_add_internal_call("Joy.Utils::DecryptFile", decrypt_file);
//}
