#ifndef HK_STRING_H
#define HK_STRING_H

#include <sys/types.h>

typedef struct {
    char* val;
    size_t len;
} hk_string_t;

#define hk_string(s) { s, hk_strlen(s) }

size_t hk_strlen(char * str);
hk_string_t hk_uppercase(hk_string_t s);
void hk_print(hk_string_t s);


#endif /* !HK_STRING_H */
