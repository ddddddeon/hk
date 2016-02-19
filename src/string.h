#ifndef HK_STRING_H
#define HK_STRING_H

#include <sys/types.h>

#define CASE_DIFF 32

#define LC_FLOOR 64
#define LC_CEIL 91

#define UC_FLOOR 96
#define UC_CEIL 123

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
