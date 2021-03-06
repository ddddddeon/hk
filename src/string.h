#ifndef HK_STRING_H
#define HK_STRING_H

#include <sys/types.h>

#define CASE_DIFF 32

#define LC_FLOOR 64
#define LC_CEIL 91

#define UC_FLOOR 96
#define UC_CEIL 123

#define ASCII_FLOOR 31
#define ASCII_CEIL 127

typedef struct {
    char *val;
    size_t len;
} hk_string_t;

#define $(s) hk_string(s)

int is_ascii(char c);
size_t hk_strlen(const char *str);
char *hk_strdup(const char *str);
hk_string_t hk_string(const char *str);
void hk_string_free(hk_string_t * s);
void hk_print(const hk_string_t s);
hk_string_t hk_strcpy(const hk_string_t s);
hk_string_t hk_uppercase(const hk_string_t s);
hk_string_t hk_lowercase(const hk_string_t s);
hk_string_t hk_reverse(const hk_string_t s);
hk_string_t hk_replace(const hk_string_t s, const char *search,
                       const char *replace);

#endif                          /* !HK_STRING_H */
