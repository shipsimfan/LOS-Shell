#include <proc.h>
#include <stdio.h>

extern "C" uint64_t SystemCall(uint64_t num, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4);

extern "C" int DisplayString(const char* message) { return SystemCall(1, 0, 0, (uint64_t)message, INT32_MAX); }

extern "C" int ReadLine(char* buffer, uint64_t bufferSize) { return SystemCall(2, 1, 0, (uint64_t)buffer, bufferSize); }

extern "C" pid_t exec(const char* filepath) { return SystemCall(3, (uint64_t)filepath, 0, 0, 0); }

extern "C" void waitPID(pid_t pid, uint64_t* status) { SystemCall(4, pid, (uint64_t)status, 0, 0); }