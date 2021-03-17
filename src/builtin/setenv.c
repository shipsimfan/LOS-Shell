#include "builtin.h"

#include <stdio.h>
#include <unistd.h>

int SetEnv(int argc, const char* argv[]) {
    if (argc < 3) {
        printf("Not enough arguments\n");
        return 1;
    }

    if (argc > 3) {
        printf("Too many arguments\n");
        return 1;
    }

    return setenv(argv[1], argv[2], 1);
}