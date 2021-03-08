#include <stdio.h>
#include <string.h>

char buffer[128];

int main() {
    fwrite("\nLOS Shell v0.2\n\n", sizeof(char), 18, stdout);

    while (1) {
        fwrite("\n> ", sizeof(char), 4, stdout);
        fread(buffer, sizeof(char), 128, stdin);

        if (strcmp(buffer, "EXIT") == 0)
            break;
        else {
            fwrite("\n", sizeof(char), 2, stdout);
            fwrite(buffer, sizeof(char), 128, stdout);
        }
    }

    return 0;
}