#include "test.h"

#include <stdio.h>
#include <hk/log.h>

int log_test(int argc, char* argv[]) {
  printf("[*] log tests:\n");
  hk_info("everything is fine%s\n", "!");
  hk_debug("just debugging%s\n", "...");
  hk_warn("i'm warning you%s\n", "...!");
  hk_err("error%s\n", "!");
  hk_fatal("fatal%s\n", "!!");

  hklog_prefix(HK_INFO);
  printf("prefix test\n");

  printf("\n");

  return HK_PASS;
}
