#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* getline() {
    char* line = malloc(128);
    char* ptr = line;
    size_t maxLen = 128;
    size_t len = 0;
    int c;

    if (line == NULL)
        return NULL;

    while (1) {
        c = fgetc(stdin);
        if (c == 0)
            break;

        len++;
        if (len == maxLen) {
            maxLen <<= 1;
            char* newLine = malloc(maxLen);
            if (newLine == NULL) {
                free(line);
                return NULL;
            }

            memcpy(newLine, line, len);

            free(line);
            line = newLine;

            ptr = line + len;
        }

        if (c == '\b') {
            len--;
            if (len > 0) {
                putchar(c);
                ptr--;
            }
        } else {
            putchar(c);

            *ptr = c;
            ptr++;
            if (c == '\n')
                break;
        }
    }

    *ptr = 0;
    return line;
}

int main() {
    printf("\nLOS Shell v0.2");

    char* line;
    while (1) {
        printf("\n> ");
        line = getline();
        printf("\n");

        if (line == NULL)
            abort();

        if (strcmp(line, "exit") == 0)
            break;
        else if (line[0] == ':') {
            pid_t pid = execute(line);
            int status = wait(pid);
            printf("Child exited with status %i\n", status);
        } else
            printf("%s", line);
    }

    return 0;
}