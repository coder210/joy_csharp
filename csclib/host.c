/* C# → joy 胶水层：宿主服务（日志 / 退出）。
 *
 * 日志固定以 "[cs] " 前缀打到 stdout 并立即 flush，方便 CI 断言冒烟结果。
 */
#include <stdio.h>
#include <stdbool.h>
#include <mono/metadata/object.h>
#include "csclib.h"
#include "joy_csharp.h"

static bool s_quit = false;
static int  s_exit_code = 0;

void csx_host_request_quit(void) { s_quit = true; }
bool csx_host_quit_requested(void) { return s_quit; }

void csx_host_set_exit_code(int code) { s_exit_code = code; }
int  csx_host_exit_code(void) { return s_exit_code; }

static void w_log(MonoString* msg)
{
        if (!msg) {
                printf("[cs] (null)\n");
                fflush(stdout);
                return;
        }
        char* s = mono_string_to_utf8(msg);
        printf("[cs] %s\n", s);
        fflush(stdout);
        mono_free(s);
}

static void w_quit(void) { csx_host_request_quit(); }
static void w_set_exit_code(int code) { s_exit_code = code; }

void csopen_host(void)
{
        csx_register_internal_call("Joy.Host::log", (const void*)w_log);
        csx_register_internal_call("Joy.Host::quit", (const void*)w_quit);
        csx_register_internal_call("Joy.Host::set_exit_code", (const void*)w_set_exit_code);
}
