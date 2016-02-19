#include "bit.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * from http://stackoverflow.com/questions/1024389/ \
 * print-an-int-in-binary-representation-using-c
 */
char* hk_int2bin(unsigned int i) {
    size_t bits = sizeof(int) * CHAR_BIT;
    char* str = malloc(bits + 1);
    if (!str) {
        return NULL;
    }

    str[bits] = HK_ZERO;
    
    unsigned u = *(unsigned *)&i;
    for (/* void */; bits--; u >>= 1) {
        str[bits] = u & 1 ? '1' : '0';
    }

    return str;
}

void hk_print_bits(int level, unsigned set) {
    hklog_prefix(level);
    printf("%s <--- %u\n", hk_int2bin(set), set);
}

int hk_bit_is_set(unsigned set, unsigned int bit_num) {
    return set & bit_num;
}

void hk_set_bit(unsigned *set, unsigned int bit_num) {
    *set |= bit_num;
}

void hk_unset_bit(unsigned *set, unsigned int bit_num) {
    *set &= ~bit_num;
}
