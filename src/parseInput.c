#include "shell.h"

#include <stdlib.h>

char** ParseInput(char* input, int* count) {
    // Count arguments
    *count = 1;
    char* ptr = input;

    while (*ptr) {
        if (*ptr == ' ' && ptr[1] != ' ')
            (*count)++;

        ptr++;
    }

    char** args = malloc(sizeof(char*) * (*count + 1));

    args[0] = input;

    ptr = input;
    char* start = ptr;
    int i = 1;
    while (*ptr) {
        if (*ptr == ' ' && ptr[1] != ' ') {
            *ptr = 0;
            args[i] = ptr + 1;
            i++;
        }

        ptr++;
    }

    args[*count] = NULL;

    return args;
}