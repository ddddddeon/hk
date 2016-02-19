
#include "test.h"

#include <stdio.h>
#include <hk/log.h>
#include <hk/string.h>

int string_test() {
    unsigned int result = HK_PASS;

    char* str = "hello world";
    hk_string_t s = hk_string("hello world");

    hk_print(s);

    hk_info("%s length: %d\n", s.val, s.len);

    if (s.len != 11) {
        result = HK_FAIL;
    }

    printf("\n");

    hk_string_t upper = hk_uppercase(s);
    hk_info("%s\n", upper.val);

    hk_string_t s2 = hk_string("hello !@#$%^&*()_+{}|:>?<,./;'[] world");
    hk_string_t upper_test = hk_string("HELLO !@#$%^&*()_+{}|:>?<,./;'[] WORLD");
    
    upper = hk_uppercase(s2);
    hk_info("%s\n", upper.val);

    printf("\n");

    return result;
}
