#pragma once

char* GetInput();

char** ParseInput(char* input, int* count);

int HandleCommand(char** arg, int count);

int Builtin(char* command, char** args, int count);