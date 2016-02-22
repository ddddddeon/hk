#include "string.h"

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
