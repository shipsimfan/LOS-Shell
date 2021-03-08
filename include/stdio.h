#ifndef _STDIO_H
#define _STDIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int DisplayString(const char* message);
extern int ReadLine(char* buffer, uint64_t bufferSize);

#ifdef __cplusplus
}
#endif

#endif