#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "shell.h"

char cwdBuffer[256];

int main(int argc, char* argv[], char* envp[]) {
    printf("\nLOS Shell v0.3\n");

    setenv("PATH", ":0/BIN", 0);

    char* line = NULL;
    char** args = NULL;
    int count;
    do {
        free(line);
        free(args);

        getcwd(cwdBuffer, 256);
        printf("%s> ", cwdBuffer);
        line = GetInput();
        if (line == NULL)
            return 1;

        printf("\n");

        args = ParseInput(line, &count);

    } while (HandleCommand(args, count));

    return 0;
}