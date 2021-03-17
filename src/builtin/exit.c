#include "builtin.h"

#include <stdio.h>
#include <stdlib.h>

int Exit(int argc, const char* argv[]) {
    if (argc > 2) {
        printf("Too many arguments\n");
        return 1;
    }

    if (argc == 1)
        exit(0);

    int status = atoi(argv[1]);

    exit(status);
}