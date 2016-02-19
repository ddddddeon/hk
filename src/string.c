#include "string.h"

#include <stdio.h>
#include <hk/log.h>

size_t hk_strlen(const char *str) {
    if (!str) {
        return 0;
    }

    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (size_t) i;
}

hk_string_t hk_uppercase(const hk_string_t s) {
    int i;
    char copy[s.len];
    
    for (i=0; i<s.len; i++) {
        if (UC_CEIL > s.val[i] && s.val[i] > UC_FLOOR) {
            copy[i] = s.val[i] - CASE_DIFF;
        } else {
            copy[i] = s.val[i];
        }
    }
    copy[i] = '\0';
    
    hk_string_t upper = hk_string(copy);

    return upper;
}

hk_string_t hk_lowercase(const hk_string_t s) {
    int i;
    char copy[s.len];

    for (i=0; i<s.len; i++) {
        if (LC_CEIL > s.val[i] && s.val[i] > LC_FLOOR) {
            copy[i] = s.val[i] + CASE_DIFF;
        } else {
            copy[i] = s.val[i];
        }
    }
    copy[i] = '\0';
    
    hk_string_t lower = hk_string(copy);

    return lower;
}

void hk_print(const hk_string_t s) {
    printf("%s\n", s.val);
}
