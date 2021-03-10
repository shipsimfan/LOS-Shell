#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char buffer[128];

int main() {
    printf("\nLOS Shell v0.2");

    while (1) {
        printf("\n> ");
        fread(buffer, sizeof(char), 128, stdin);
        printf("\n");

        if (strcmp(buffer, "EXIT") == 0)
            break;
        else if (buffer[0] == ';') {
            buffer[0] = ':';
            pid_t pid = execute(buffer);
            int status = wait(pid);
            printf("Child exited with status %i\n", status);
        } else
            printf("%s", buffer);
    }

    return 0;
}