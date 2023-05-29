#ifndef _STDDEF_H
#define _STDDEF_H

// Tipos

// um tipo sem sinal para representar tamanhos de objetos
typedef unsigned int size_t; 
// um tipo inteiro usado para representar a diferença entre dois ponteiros
typedef int ptr_diff_t;

// Constantes

// Ponteiro NULO
#define NULL ((void*)0)

// Macros

// Uma macro que retorna o deslocamento (em bytes) do membro especificado.
#define offsetof(type, member) ((size_t)&((type*)0)->member)

#endif
