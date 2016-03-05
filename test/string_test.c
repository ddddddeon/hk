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
    hk_string_t s4 = hk_string("hello world");
    hk_string_t s5 = hk_strcpy(s4);
    hk_info("%s\n", s5.val);
    hk_string_free(s4);

    /* hk_strdup */
    char* s6 = hk_strdup(s5.val);
    hk_info("%s\n", s6);
    hk_string_free(s5);
    free(s6);

    /* hk_string_replace */
    hk_string_t orig = hk_string("hello world");
    hk_string_t replaced = hk_string_replace(orig, "hello", "hi");
    hk_info("%s -> %s\n", orig.val, replaced.val);
    hk_string_free(orig);

    hk_string_t replaced2 = hk_string_replace(replaced, "hi", "what's good");
    hk_info("%s -> %s\n", replaced.val, replaced2.val);
    hk_string_free(replaced);

    hk_string_t replaced3 = hk_string_replace(replaced2, "what's ", "");
    hk_info("%s -> %s\n", replaced2.val, replaced3.val);
    hk_string_free(replaced2);

    hk_string_t replaced4 = hk_string_replace(replaced3, "good", "good morning");
    hk_info("%s -> %s\n", replaced3.val, replaced4.val);
    hk_string_free(replaced3);
    
    hk_string_t replaced5 = hk_string_replace(replaced4, "world", "yall");
    hk_info("%s -> %s\n", replaced4.val, replaced5.val);
    hk_string_free(replaced4);


    hk_string_t replaced6 = hk_string_replace(replaced5, "asdf", "fdsa");
    hk_info("%s -> %s\n", replaced4.val, replaced5.val);   
    hk_string_free(replaced5);
    hk_string_free(replaced6);

    printf("\n");

    return result;
}
