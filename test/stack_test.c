#include "test.h"

#include <stdio.h>
#include <hk/log.h>
#include <hk/stack.h>

int stack_test(int argc, char* argv[]) {
    unsigned int result = HK_PASS;

    printf("[*] stack tests:\n");

    /* ll_create */
    hk_stack_t *cur = hk_stack_create(0);    
    
    /* hk_stack_push */
    hk_stack_push(&cur, 420);
    hk_stack_push(&cur, 69);
    hk_stack_push(&cur, 666);
    hk_info("pushed 3 values: 420, 69, 666\n");
    printf("\n");

    /* hk_stack_find */
    int num = hk_stack_find(cur, 2);
    hk_info("value at index 2: %d\n", num);
    if (num != 420) {
	result = HK_FAIL;
    }
    printf("\n");

    /* hk_stack_pop */
    int n;
    hk_stack_pop(&cur, &n);
    hk_info("popped %d off the list and assigned to n\n", n);
    if (n != 666) {
	result = HK_FAIL;
    }
    printf("\n");

    hk_info("remaining items in list:\n");
    while(cur) {
	hk_info("%d\n", cur->val);
	cur = cur->next;
    }
    printf("\n");

    return result;
}
