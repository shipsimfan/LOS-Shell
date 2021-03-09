#include <stdio.h>
#include <string.h>

char buffer[128];

int main() {
    printf("\nLOS Shell v0.2\n");

    while (1) {
        printf("\n> ");
        fread(buffer, sizeof(char), 128, stdin);

        if (strcmp(buffer, "EXIT") == 0)
            break;
        else
            printf("\n%s", buffer);
    }

    return 0;
}