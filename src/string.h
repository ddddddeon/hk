#ifndef HK_STRING_H
#define HK_STRING_H

#include <sys/types.h>

#define ASCII_CASE_DIFF 32

#define ASCII_LC_FLOOR 64
#define ASCII_LC_CEIL 91

#define ASCII_UC_FLOOR 96
#define ASCII_UC_CEIL 123

typedef struct {
    char* val;
    size_t len;
} hk_string_t;

#define hk_string(s) { s, hk_strlen(s) }
#define $(s) hk_string(s)

size_t hk_strlen(const char * str);
hk_string_t hk_uppercase(const hk_string_t s);
hk_string_t hk_lowercase(const hk_string_t s);
void hk_print(const hk_string_t s);


#endif /* !HK_STRING_H */
