#include <stdio.h>

#define MAX 5

typedef struct Pilha Pilha;
struct Pilha{
  int topoA;
  int topoB;
  int vetor[MAX];
};