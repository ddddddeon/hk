#include "test.h"

#include <stdio.h>
#include <hk/log.h>
#include <hk/bit.h>

int bit_test(int argc, char *argv[])
{
    unsigned int result = HK_PASS;

    unsigned int num1 = 7U;
    unsigned int num2 = 1U;

    printf("[*] bit tests:\n");

    hk_info("integer 7\n");
    hk_print_bits(HK_DEBUG, num1);
    if (hk_bit_is_set(num1, HK_BIT_2)) {
        hk_info("2nd bit is set in integer %d!\n", num1);
    } else {
        hk_err("2nd bit is not set in integer %d but should be...\n",
               num1);
        result = HK_FAIL;
    }

    printf("\n");

    hk_info("integer 1\n");
    hk_print_bits(HK_DEBUG, num2);
    if (!hk_bit_is_set(num2, HK_BIT_2)) {
        hk_info("2nd bit is not set in integer %d!\n", num2);
    } else {
        hk_err("2nd bit is set in integer %d but should be...\n", num2);
        result = HK_FAIL;
    }

    printf("\n");

    hk_info("integer 7\n");
    hk_print_bits(HK_DEBUG, num1);
    hk_unset_bit(&num1, HK_BIT_2);
    if (!hk_bit_is_set(num1, HK_BIT_2)) {
        hk_info("2nd bit was unset!\n");
        hk_info("%d\n", num1);
        hk_print_bits(HK_DEBUG, num1);
        if (num1 != 5) {
            hk_err("%d is not 5!\n");
            result = HK_FAIL;
        }
    } else {
        hk_err("2nd bit was not unset...\n");
        result = HK_FAIL;
    }

    printf("\n");
    hk_info("integer 1\n");
    hk_print_bits(HK_DEBUG, num2);
    hk_set_bit(&num2, HK_BIT_2);
    if (hk_bit_is_set(num2, HK_BIT_2)) {
        hk_info("2nd bit was set!\n");
        hk_info("%d\n", num2);
        hk_print_bits(HK_DEBUG, num2);
        if (num2 != 3) {
            hk_err("%d is not 5!\n");
            result = HK_FAIL;
        }
    } else {
        hk_err("2nd bit was not set...\n");
        result = HK_FAIL;
    }

    printf("\n");

    return result;
}
