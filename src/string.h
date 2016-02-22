#ifndef HK_STRING_H
#define HK_STRING_H

#include <sys/types.h>

typedef struct {
    char* val;
    size_t len;
} hk_string_t;

size_t hk_strlen(char * str);

#endif /* !HK_STRING_H */
