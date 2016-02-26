#include "string.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int hk_is_ascii(char c) {
    return c > ASCII_FLOOR && 
           c < ASCII_CEIL;
}

size_t hk_strlen(const char *str) {
    if (!str) {
        return 0;
    }

    int i = 0;
    while (str[i] != '\0' && hk_is_ascii(str[i])) {
        i++;
    }

    return (size_t) i;
}

char *hk_strdup(const char *str) {
    size_t len = hk_strlen(str) + 1;
    char *new = malloc(len);

    return memcpy(new, str, len);
}

hk_string_t hk_string(const char *str) {
    hk_string_t s;
    s.val = hk_strdup(str); 
    s.len = hk_strlen(str);

    return s;
}

hk_string_t hk_strcpy(const hk_string_t s) {
    int i;
    char copy[s.len];

    for (i=0; i<s.len; i++) {
        copy[i] = s.val[i];
    }
    copy[i] = '\0';

    hk_string_t copied = hk_string(copy);
    
    return copied;
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

hk_string_t hk_reverse(const hk_string_t s) {
    int i, j;
    char copy[s.len];

    for (i=0, j=s.len-1;
         j >= i;
         i++, j--) {
        copy[i] = s.val[j];
        copy[j] = s.val[i];
    }
    copy[s.len] = '\0';
    
    hk_string_t reversed = hk_string(copy);

    return reversed;
}

void hk_print(const hk_string_t s) {
    printf("%s\n", s.val);
}
