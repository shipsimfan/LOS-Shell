#include <proc.h>
#include <stdio.h>
#include <string.h>

char buffer[128];

int main() {
    DisplayString("LOS Shell v0.1\n");

    /*while (1) {
        DisplayString("\n> ");
        ReadLine(buffer, 128);
        DisplayString("\n");
        if (strcmp(buffer, "EXIT") == 0)
            break;
        else if (buffer[0] == ';') {
            buffer[0] = ':';
            pid_t pid = exec(buffer);
            if (pid > 0) {
                uint64_t status;
                waitPID(pid, &status);
            }
        } else {
            DisplayString(buffer);
        }
    }*/

    return 0;
}