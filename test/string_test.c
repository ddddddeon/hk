#include "test.h"

#include <stdio.h>
#include <hk/log.h>
#include <hk/string.h>
#include <malloc.h>

int string_test() {
    unsigned int result = HK_PASS;

    printf("[*] string tests:\n");

    /* hk_string */
    char* str = "hello world";
    hk_string_t s = hk_string("hello world");

    hklog_prefix(HK_INFO);
    hk_print(s);

    hk_info("%s length: %d\n", s.val, s.len);

    if (s.len != 11) {
        result = HK_FAIL;
    }

    printf("\n");

    /* hk_uppercase */
    hk_string_t upper = hk_uppercase(s);
    hk_info("%s\n", upper.val);
    hk_string_free(upper);
    hk_string_free(s);

    /* hk_uppercase (with non-alphabetical chars) */
    hk_string_t s2 = hk_string("hello !@#$%^&*()_+{}|:>?<,./;'[] world");
    hk_string_t upper2 = hk_uppercase(s2);
    hk_info("%s\n", upper2.val);
    hk_string_free(upper2);
    hk_string_free(s2);

    /* hk_lowercase */
    hk_string_t mixed = hk_string("Hello WorlD!");
    hk_string_t m_lower = hk_lowercase(mixed);
    hk_info("%s\n", mixed.val);
    hk_info("%s\n", m_lower.val);

    hk_string_t m_upper = hk_uppercase(mixed);
    hk_info("%s\n", m_upper.val);
    hk_string_free(m_upper);
    hk_string_free(m_lower);
    hk_string_free(mixed);

    /* hk_reverse */
    hk_string_t s3 = hk_string("hi there lol");
    hk_string_t reversed = hk_reverse(s3);
    hk_info("%s\n", reversed.val);
    hk_string_free(reversed);
    hk_string_free(s3);

    /* hk_strcpy */
    hk_string_t s4 = hk_string("kalli rulz");
    hk_string_t s5 = hk_strcpy(s4);
    hk_info("%s\n", s5.val);
    hk_string_free(s4);

    /* hk_strdup */
    char* s6 = hk_strdup(s5.val);
    hk_info("%s\n", s6);
    hk_string_free(s5);
    free(s6);

    printf("\n");

    return result;
}
