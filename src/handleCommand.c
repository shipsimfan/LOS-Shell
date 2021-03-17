#include "shell.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int HandleCommand(char** args, int count) {
    if (count < 1)
        return 1;

    if (args[0][0] == 0)
        return 1;

    // Check for builtin
    if (Builtin(args[0], args, count))
        return 1;

    // Execute command as is
    pid_t pid = execute(args[0], (const char**)args, NULL);
    if (pid == 0) {
        printf("Unable to locate %s\n", args[0]);
        return 1;
    }

    wait(pid);

    return 1;
}