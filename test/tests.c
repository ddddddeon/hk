#include "test.h"

#include <stdio.h>
#include <hk/log.h>

int main(int argc, char *argv[])
{
    hk_init("hk tests");
    printf("\n");

    int result = HK_PASS;

    if (log_test() != HK_PASS) {
        hk_err("log tests failing...!\n\n");
        result = HK_FAIL;
    } else {
        hk_info("log test passing!\n\n");
    }

    if (bit_test() != HK_PASS) {
        hk_err("bit tests failing...!\n\n");
        result = HK_FAIL;
    } else {
        hk_info("bit tests passing!\n\n");
    }

    if (stack_test() != HK_PASS) {
        hk_err("stack tests failing...!\n\n");
        result = HK_FAIL;
    } else {
        hk_info("stack tests passing!\n\n");
    }

    if (string_test() != HK_PASS) {
        hk_err("string tests failing...!\n\n");
        result = HK_FAIL;
    } else {
        hk_info("string tests passing!\n\n");
    }

    if (os_test() != HK_PASS) {
        hk_err("os test failing...!\n\n");
        result = HK_FAIL;
    } else {
        hk_info("os test passing!\n\n");
    }

    if (result == HK_PASS) {
        result = HK_FAIL;
        hk_info("[OK] all tests passed!\n");
    } else {
        hk_err("[ERR] some tests failing!\n");
    }

    return result;
}
