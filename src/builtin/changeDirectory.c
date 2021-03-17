#include "builtin.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char previousDirectory[256] = {0};
char buffer[256];

int ChangeDirectory(int argc, const char* argv[]) {
    if (argc > 2) {
        printf("Too many arguments\n");
        return 1;
    }

    if (argc == 1) {
        getcwd(previousDirectory, 256);
        setcwd(":/");
        return 0;
    }

    if (strcmp(argv[1], "-") == 0) {
        if (previousDirectory[0] != 0) {
            getcwd(buffer, 256);
            setcwd(previousDirectory);
            memcpy(previousDirectory, buffer, 256);
        }

        return 0;
    }

    getcwd(buffer, 256);
    if (setcwd(argv[1]) > 0) {
        printf("Unable to locate %s\n", argv[1]);
        return 1;
    }

    memcpy(previousDirectory, buffer, 256);

    return 0;
}