#ifndef _STDLIB_H
#define _STDLIB_H
#define RAND_MAX 0xFFFFFFFF

#include "stddef.h"

// Conversões Númericas
int atoi(const char* str);
long int strtol(const char* str, char** endptr, int base);
double strtod(const char* str, char** endptr);

// Geração de números pseudoaleatórios
int rand(void);
void srand(unsigned int seed);

// Outras funções

void qsort(void* base, size_t nmemb, size_t size,
           int (*compar)(const void*, const void*));

void* bsearch(const void* key, const void* base, size_t nmemb, size_t size,
              int (*compar)(const void*, const void*));
#endif 
