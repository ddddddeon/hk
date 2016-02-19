#include "stack.h"

#include <malloc.h>

hk_stack_t *hk_stack_create(int length) {
    hk_stack_t *cur;
    hk_stack_t *head;
    int i;

    head = NULL;

    for (i=0; i<length; i++) {
        hk_stack_push(&head, HK_STACK_INITIALIZE);
    }

    cur = head;
    return cur;
}

void hk_stack_push(hk_stack_t **l, int val) {
    hk_stack_t *cur;
    hk_stack_t *head;

    head = *l;

    cur = (hk_stack_t *) malloc(sizeof(hk_stack_t));
    cur->val = val;
    cur->next = head;

    *l = cur;
}

void hk_stack_pop(hk_stack_t **l, int *var) {
    hk_stack_t *cur = *l;
   
    *var = cur->val;
    *l = cur->next;
    free(cur);
}

int hk_stack_find(hk_stack_t *l, int idx) {
    int i;
    
    for (i=0; i<idx; i++) {
        l = l->next;
    } 
    return l->val;
}
