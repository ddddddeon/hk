#include "test.h"

#include <hk/log.h>
#include <hk/string.h>

int string_test() {
    unsigned int result = HK_PASS;
    char* str = "hello world";
    //    hk_string_t s = { str, hk_strlen(str) };
    hk_string_t s = hk_string("hello world");
    hk_info("%s length: %d\n", s.val, s.len);

    if (s.len != 11) {
        result = HK_FAIL;
    }

    return result;
}
