#ifndef STACK_H
#define STACK_H

#include "core.h"

#define HK_STACK_INITIALIZE 0

struct hk_stack {
    int val;
    struct hk_stack *next;
};

typedef struct hk_stack hk_stack_t;

hk_stack_t *hk_stack_create();
void hk_stack_push(hk_stack_t **l, int val);
void hk_stack_pop(hk_stack_t **l, int *var);
int hk_stack_find(hk_stack_t *l, int idx);

#endif /* !STACK_H */
