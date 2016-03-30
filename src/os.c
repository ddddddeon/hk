#include "core.h"
#include "os.h"

#include <stdio.h>
#include <stdlib.h>

int hk_cmd(char *cmd)
{
    char buf[BUFSIZE];

    FILE *p = popen(cmd, "r");

    if (p == NULL) {
        perror("pipe ");
        return HK_NOK;
    }

    while (fgets(buf, sizeof(buf), p) != NULL) {
        printf("%s", buf);
    }

    return pclose(p);
}
