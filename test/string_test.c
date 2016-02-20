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

    hk_string_t mixed = hk_string("Hello WorlD!");
    mixed = hk_lowercase(mixed);
    hk_info("%s\n", mixed.val);

    upper = hk_uppercase(mixed);
    hk_info("%s\n", upper.val);
    printf("\n");

    hk_string_t s3 = hk_string("hi there lol");
    hk_string_t reversed = hk_reverse(s3);
    hk_info("%s\n", reversed.val);

    hk_string_t s4 = hk_string("kalli rulz");
    hk_string_t s5 = hk_strcpy(s4);
    hk_info("%s\n", s5.val);

    return result;
}
