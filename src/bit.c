#include "bit.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char* hk_bitstring(unsigned int set) {
    size_t bits = sizeof(int) * CHAR_BIT;
    char* str = malloc(bits + 1);
    if (!str) {
        return NULL;
    }

    str[bits] = HK_ZERO;
    
    for (/* void */; bits--; set >>= 1) {
        str[bits] = set & 1 ? '1' : '0';
    }

    return str;
}

void hk_print_bits(int level, unsigned int set) {
    hklog_prefix(level);
    char* bits = hk_bitstring(set);
    printf("%s <--- %u\n", bits, set);
    free(bits);
}

int hk_bit_is_set(unsigned int set, unsigned int bit_num) {
    return set & bit_num;
}

void hk_set_bit(unsigned int *set, unsigned int bit_num) {
    *set |= bit_num;
}

void hk_unset_bit(unsigned int *set, unsigned int bit_num) {
    *set &= ~bit_num;
}
