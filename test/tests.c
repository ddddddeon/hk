#include "test.h"

#include <hk/log.h>

int main(int argc, char* argv[]) {
    int result = HK_PASS;
    
    if (log_test() != HK_PASS) {
	hk_err("log tests failing...!\n");
	result = HK_FAIL;
    } else {
	hk_info("log test passing!\n\n");
    }
    
    if (bit_test() != HK_PASS) {
	hk_err("bit tests failing...!\n");
	result = HK_FAIL;
    } else {
	hk_info("bit tests passing!\n\n");
    }
    
    if (stack_test() != HK_PASS) {
	hk_err("stack tests failing...!\n");
    } else {
	hk_info("stack tests passing!\n\n");
	
    }
    
    return result;
}