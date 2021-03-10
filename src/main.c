#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[128];

int main() {

    printf("\nLOS Shell v0.2\n\n");

    while (1) {
        printf("> ");
        fread(buffer, sizeof(char), 128, stdin);
        printf("\n");

        if (strcmp(buffer, "EXIT") == 0)
            break;
        else
            printf("%s\n", buffer);
    }

    return 0;
}