#include "shell.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char pathBuffer[256];

int HandleCommand(char** args, int count) {
    if (count < 1)
        return 1;

    if (args[0][0] == 0)
        return 1;

    // Check for builtin
    if (Builtin(args[0], args, count))
        return 1;

    // Check for slash
    int slash = 0;
    char* cmd = args[0];
    while (*cmd) {
        if (*cmd == '/') {
            slash = 1;
            break;
        }

        cmd++;
    }

    // Check against path
    if (!slash) {
        char* path = getenv("PATH");
        if (path != NULL) {
            while (*path) {
                char* ptr = path;
                while (*ptr != ';' && *ptr)
                    ptr++;

                char oldVal = *ptr;
                *ptr = 0;
                strcpy(pathBuffer, path);
                *ptr = oldVal;

                strcat(pathBuffer, "/");
                strcat(pathBuffer, args[0]);

                pid_t pid = execute(pathBuffer, (const char**)args, (const char**)environ);
                if (pid) {
                    wait(pid);
                    return 1;
                }

                if (*ptr == ';')
                    ptr++;

                path = ptr;
            }
        }
    }

    // Execute command as is
    pid_t pid = execute(args[0], (const char**)args, (const char**)environ);
    if (pid == 0) {
        printf("Unable to locate %s\n", args[0]);
        return 1;
    }

    wait(pid);

    return 1;
}