#include <stdio.h>
#include <string.h>

char buffer[128];

int main() {
    DisplayString("LOS Shell v0.1\n");

    while (1) {
        DisplayString("\n> ");
        int bytesRead = ReadLine(buffer, 128);
        if (strcmp(buffer, "EXIT") == 0)
            break;

        DisplayString("\n");
        DisplayString(buffer);
    }

    return 0;
}