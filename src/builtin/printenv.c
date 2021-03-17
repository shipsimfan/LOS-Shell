#include "builtin.h"

#include <stdio.h>
#include <unistd.h>

int PrintEnv(int argc, const char* argv[]) {
    if (argc > 2) {
        printf("Too many arguments\n");
        return 1;
    }

    if (argc == 2) {
        char* env = getenv(argv[1]);
        if (env != NULL)
            printf("%s\n", env);

        return 0;
    }

    char** env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}