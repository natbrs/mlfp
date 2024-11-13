#include <stdio.h>

typedef struct No No;
struct No{
    char *nome;
    struct No*anterior;
    struct No*proximo;
};