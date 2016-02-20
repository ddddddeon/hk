#include "test.h"

#include <stdio.h>
#include <hk/log.h>
#include <hk/string.h>
#include <malloc.h>

int string_test() {
    unsigned int result = HK_PASS;


    /* hk_string */
    char* str = "hello world";
    hk_string_t s = hk_string("hello world");

    hk_print(s);

    hk_info("%s length: %d\n", s.val, s.len);

    if (s.len != 11) {
        result = HK_FAIL;
    }

    printf("\n");


    /* hk_uppercase */
    hk_string_t upper = hk_uppercase(s);
    hk_info("%s\n", upper.val);
    free(upper.val);
    free(s.val);

    /* hk_uppercase (with non-alphabetical chars) */
    hk_string_t s2 = hk_string("hello !@#$%^&*()_+{}|:>?<,./;'[] world");
    hk_string_t upper2 = hk_uppercase(s2);
    hk_info("%s\n", upper2.val);
    free(upper2.val);
    free(s2.val);

    /* hk_lowercase */
    hk_string_t mixed = hk_string("Hello WorlD!");
    hk_string_t m_lower = hk_lowercase(mixed);
    hk_info("%s\n", mixed.val);
    hk_info("%s\n", m_lower.val);

    hk_string_t m_upper = hk_uppercase(mixed);
    hk_info("%s\n", m_upper.val);
    free(m_upper.val);
    free(m_lower.val);
    free(mixed.val);

    /* hk_reverse */
    hk_string_t s3 = hk_string("hi there lol");
    hk_string_t reversed = hk_reverse(s3);
    hk_info("%s\n", reversed.val);
    free(reversed.val);
    free(s3.val);

    /* hk_strcpy */
    hk_string_t s4 = hk_string("kalli rulz");
    hk_string_t s5 = hk_strcpy(s4);
    hk_info("%s\n", s5.val);
    free(s4.val);

    /* hk_strdup */
    char* s6 = hk_strdup(s5.val);
    hk_info("%s\n", s6);
    free(s5.val);
    free(s6);
    
    return result;
}
