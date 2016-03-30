#include "test.h"

#include <hk/os.h>
#include <stdio.h>

int os_test()
{
    printf("[*] os tests:\n");

    int ret = hk_cmd("ls -l");

    printf("\n");
    return ret;
}
