#include "class.c"

int main(){
  Pilha*p=criaPilha();
  empilhaA(p,10);
  empilhaA(p,20);
  empilhaB(p,30);
  empilhaB(p,40);
  printf("Pilha A: ");
  mostrarPilhaA(p);
  printf("Pilha B: ");
  mostrarPilhaB(p);
  printf("Desempilhando da Pilha A: %d\n", desempilhaA(p));
  printf("Desempilhando da Pilha B: %d\n", desempilhaB(p));
  printf("Pilha A após desempilhar: ");
  mostrarPilhaA(p);
  printf("Pilha B após desempilhar: ");
  mostrarPilhaB(p);
  printf("Tamanho da Pilha A: %d\n", tamanhoA(p));
  printf("Tamanho da Pilha B: %d\n", tamanhoB(p));
  free(p);
  return 0;
}