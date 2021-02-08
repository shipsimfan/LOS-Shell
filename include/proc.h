#ifndef _PROC_H
#define _PROC_H

#include <stdint.h>

typedef uint64_t pid_t;

#ifdef __cplusplus
extern "C" {
#endif

extern pid_t exec(const char* filepath);

extern void waitPID(pid_t pid, uint64_t* status);

#ifdef __cplusplus
}
#endif

#endif