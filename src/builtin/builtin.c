#include "../shell.h"

#include "builtin.h"

#include <string.h>

typedef struct {
    const char* name;
    int (*function)(int argc, const char* argv[]);
} BuiltinCommand;

static BuiltinCommand commands[] = {{"cd", ChangeDirectory}, {"exit", Exit}};

int Builtin(char* command, char** args, int count) {
    for (int i = 0; i < sizeof(commands) / sizeof(BuiltinCommand); i++) {
        if (strcmp(command, commands[i].name) == 0) {
            commands[i].function(count, (const char**)args);
            return 1;
        }
    }

    return 0;
}