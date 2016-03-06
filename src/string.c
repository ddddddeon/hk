#include "string.h"

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
    if (new == NULL) {
        return NULL;
    }
    memcpy(new, str, len);
    new[len-1] = '\0';

    return new;
}

hk_string_t hk_string(const char *str) {
    hk_string_t s;
    s.val = hk_strdup(str); 
    s.len = hk_strlen(str);

    return s;
}

void hk_string_free(hk_string_t *s) {
    free(s->val);
    s->val = NULL;
    s->len = 0;
}

void hk_print(const hk_string_t s) {
    printf("%s\n", s.val);
}

hk_string_t hk_strcpy(const hk_string_t s) {
    int i;
    char copy[s.len + 1];

    for (i=0; i<s.len; i++) {
        copy[i] = s.val[i];
    }
    copy[i] = '\0';

    hk_string_t copied = hk_string(copy);
    
    return copied;
}

hk_string_t hk_uppercase(const hk_string_t s) {
    int i;
    char copy[s.len + 1];
    
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
    char copy[s.len + 1];

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
    char copy[s.len + 1];

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

hk_string_t hk_replace(const hk_string_t s, const char *search, const char *replace) {
    int replace_len = (int) hk_strlen(replace);
    int diff_len = replace_len - hk_strlen(search);
    int new_len = s.len + diff_len + 1;

    char *index = strstr(s.val, search);
    if (index == NULL) {
        return hk_string(s.val);
    }

    char replaced_string[new_len];
    int  replace_start = index - s.val;
    int  i = 0;
    int  j = 0;

    for (/* void */; i < replace_start; i++) {
        replaced_string[i] = s.val[i];
    }

    for (/* void */; i < ( replace_start + replace_len ); i++) {
        replaced_string[i] = replace[j];
        j++;
    }

    for (/* void */; i < new_len; i++) {
        replaced_string[i] = s.val[i - diff_len];
    } 
    replaced_string[i] = '\0';

    hk_string_t replaced = hk_string(replaced_string);

    return replaced;
}
