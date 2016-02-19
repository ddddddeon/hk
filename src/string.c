#include "string.h"

#include <stdio.h>
#include <hk/log.h>

#define ASCII_UC_FLOOR 96
#define ASCII_UC_CEIL 123
#define ASCII_CASE_DIFF 32

size_t hk_strlen(char *str) {
    if (!str) {
        return 0;
    }

    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (size_t) i;
}

hk_string_t hk_uppercase(hk_string_t s) {
    int i;
    int len = (int) s.len;
    char copy[len];
    
    for (i=0; i<len; i++) {
	if (ASCII_UC_CEIL > s.val[i] && s.val[i] > ASCII_UC_FLOOR) {
	    copy[i] = s.val[i] - ASCII_CASE_DIFF;
	} else {
	    copy[i] = s.val[i];
	}
    }
    copy[i] = '\0';
 
    hk_string_t upper = hk_string(copy);

    return upper;
}

void hk_print(hk_string_t s) {
    printf("%s\n", s.val);
}
