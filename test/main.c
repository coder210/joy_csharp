#include <stdio.h>
#include <mono/metadata/object.h>
#include <mono/metadata/appdomain.h>
#include "joy_csharp.h"

int main(void)
{
        csx_p csx = csx_create();
        if (!csx) {
                printf("csx_create FAILED\n");
                return 1;
        }

        if (!csx_load_assembly(csx, "JoyTest.dll")) {
                printf("csx_load_assembly FAILED\n");
                csx_release(csx);
                return 2;
        }
        printf("csx_load_assembly OK\n");

        int a = 3, b = 4;
        void* args[2] = { &a, &b };
        MonoObject* r = csx_invoke_static_method(csx, "JoyTest", "Calc", "Add", args);
        if (!r) {
                printf("invoke Add FAILED\n");
                csx_release(csx);
                return 3;
        }
        int sum = *(int*)mono_object_unbox(r);
        printf("Add(3,4) = %d\n", sum);

        MonoString* name = mono_string_new(mono_domain_get(), "Mono");
        void* sargs[1] = { name };
        MonoObject* s = csx_invoke_static_method(csx, "JoyTest", "Calc", "Hello", sargs);
        if (s) {
                char* str = mono_string_to_utf8((MonoString*)s);
                printf("Hello -> %s\n", str);
                mono_free(str);
        }

        /* C# → C：Bootstrap.Run 内部调用 Joy.Utils 的 internal call */
        MonoObject* boot = csx_invoke_static_method(csx, "Joy", "Bootstrap", "Run", NULL);
        if (boot) {
                char* bstr = mono_string_to_utf8((MonoString*)boot);
                printf("Bootstrap.Run -> %s\n", bstr);
                mono_free(bstr);
        } else {
                printf("Bootstrap.Run FAILED\n");
        }

        csx_release(csx);
        printf("csx_release OK\n");
        return sum == 7 ? 0 : 4;
}
