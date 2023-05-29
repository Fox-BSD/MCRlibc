#include "string.h"
#include "stdbool.h"

size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

char* strcpy(char *dest, const char *src) {
    char *temp = dest;
    while ((*dest++ = *src++))
        ;
    return temp;
}

char* strcat(char *dest, const char *src) {
    char *temp = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
    return temp;
}
