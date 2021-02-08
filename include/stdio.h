#ifndef _STDIO_H
#define _STDIO_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int DisplayString(const char* message);
extern int ReadLine(char* buffer, size_t bufferSize);

#ifdef __cplusplus
}
#endif

#endif