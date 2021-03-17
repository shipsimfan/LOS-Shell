#include "../shell.h"

#include "builtin.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    const char* name;
    int (*function)(int argc, const char* argv[]);
} BuiltinCommand;

static BuiltinCommand commands[] = {{"builtin", BuiltinCMD}, {"cd", ChangeDirectory}, {"exit", Exit}, {"printenv", PrintEnv}, {"setenv", SetEnv}};

int BuiltinCMD(int argc, const char* argv[]) {
    if (argc == 1)
        return 0;

    for (int i = 0; i < sizeof(commands) / sizeof(BuiltinCommand); i++) {
        if (strcmp(argv[1], commands[i].name) == 0) {
            commands[i].function(argc - 1, (const char**)argv + 1);
            return 0;
        }
    }

    printf("No builtin %s\n", argv[1]);
    return 1;
}

int Builtin(char* command, char** args, int count) {
    for (int i = 0; i < sizeof(commands) / sizeof(BuiltinCommand); i++) {
        if (strcmp(command, commands[i].name) == 0) {
            commands[i].function(count, (const char**)args);
            return 1;
        }
    }

    return 0;
}