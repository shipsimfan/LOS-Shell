#include <string.h>

#include <stdint.h>

extern "C" void* memcpy(void* destination, const void* source, size_t num) {
    int i = 0;
    if (num >= 8)
        for (; num >= 8; num -= 8, i++)
            ((uint64_t*)destination)[i] = ((uint64_t*)source)[i];

    i = i << 1;

    if (num >= 4) {
        ((uint32_t*)destination)[i] = ((uint32_t*)source)[i];
        num -= 4;
        i++;
    }

    i = i << 1;

    if (num >= 2) {
        ((uint16_t*)destination)[i] = ((uint16_t*)source)[i];
        num -= 2;
        i++;
    }

    i = i << 1;

    if (num == 1)
        ((uint8_t*)destination)[i] = ((uint8_t*)source)[i];

    return destination;
}

extern "C" void* memset(void* ptr, int value, size_t num) {
    int i = 0;
    if (num >= 8)
        for (; num >= 8; num -= 8, i++)
            ((uint64_t*)ptr)[i] = 0;

    i = i << 1;

    if (num >= 4) {
        ((uint32_t*)ptr)[i] = 0;
        num -= 4;
        i++;
    }

    i = i << 1;

    if (num >= 2) {
        ((uint16_t*)ptr)[i] = 0;
        num -= 2;
        i++;
    }

    i = i << 1;

    if (num == 1)
        ((uint8_t*)ptr)[i] = 0;

    return ptr;
}

extern "C" int memcmp(const void* str1, const void* str2, size_t n) {
    register const unsigned char* s1 = (const unsigned char*)str1;
    register const unsigned char* s2 = (const unsigned char*)str2;

    while (n-- > 0) {
        if (*s1++ != *s2++)
            return s1[-1] < s2[-1] ? -1 : 1;
    }

    return 0;
}

extern "C" char* strcpy(char* destination, const char* source) {
    int i;
    for (i = 0; source[i]; i++)
        destination[i] = source[i];

    destination[i] = 0;
    return destination;
}

extern "C" char* strcat(char* destination, const char* source) {
    int i;
    size_t len = strlen(destination);
    for (i = 0; source[i]; i++)
        destination[i + len] = source[i];

    destination[i] = 0;
    return destination;
}

extern "C" size_t strlen(const char* str) {
    size_t i;
    for (i = 0; str[i]; i++)
        ;
    return i;
}

extern "C" int strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2))
        s1++, s2++;
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

extern "C" char* strncpy(char* destination, const char* source, size_t num) {
    while (*source && num--) {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return destination;
}

extern "C" char* strncat(char* destination, const char* source, size_t num) {
    size_t i, j;
    for (i = 0; destination[i] != '\0'; i++)
        ;

    for (j = 0; source[j] != '\0' && j < num; j++)
        destination[i + j] = source[j];

    destination[i + j] = '\0';
    return destination;
}

extern "C" int strncmp(const char* s1, const char* s2, size_t n) {
    while (n--)
        if (*s1++ != *s2++)
            return *(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1);
    return 0;
}