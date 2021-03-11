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
                len--;
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

char cwdBuffer[256];

int main() {
    printf("\nLOS Shell v0.2");

    char* line;
    while (1) {
        getcwd(cwdBuffer, 256);
        printf("\n%s> ", cwdBuffer);
        line = getline();
        printf("\n");

        if (line == NULL)
            abort();

        if (strcmp(line, "exit") == 0)
            break;
        if (memcmp(line, "echo", 4) == 0) {
            if (strlen(line) > 5)
                printf("%s", line + 5);
        } else {
            pid_t pid = execute(line);
            if (pid == ~0)
                printf("Unable to locate %s", line);
            else {
                int status = wait(pid);
                printf("Child exited with status %i\n", status);
            }
        }
    }

    return 0;
}