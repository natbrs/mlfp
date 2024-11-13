#include "stdio.h"

#define maxTam 10

typedef struct Fila Fila;
struct Fila {
    int frente;
    int final;
    int tam;
    int elementos[maxTam];
};