#include "stack.h"

#include <malloc.h>

hk_stack_t *hk_stack_create() {
    hk_stack_t *head = NULL;
    return head;
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

int hk_stack_top(hk_stack_t *l) {
    return l->val;
}

int hk_stack_isempty(hk_stack_t *l) {
    if (l == NULL) {
	return HK_TRUE;
    }

    return HK_FALSE;

}

int hk_stack_find(hk_stack_t *l, int idx) {
    int i;
    
    for (i=0; i<idx; i++) {
        l = l->next;
    } 
    return l->val;
}

