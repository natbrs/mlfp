#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

typedef enum{false,true} boolean;

Pilha*criaPilha(){
  Pilha*pilha=(Pilha *)malloc(sizeof(Pilha));
  if(pilha==NULL){
    printf("Erro ao alocar memória para a pilha! \n");
    exit(1);
  }
  pilha->topoA=-1;
  pilha->topoB=MAX;
  return pilha;
}

// empilha objeto na pilha A
void empilhaA(Pilha *pilha, int obj){
  if(pilha->topoA==MAX-1){
    printf("Pilha A cheia! \n");
    return;
  }
  pilha->topoA++;
  pilha->vetor[pilha->topoA]=obj;
}

// empilha objeto na pilha B
void empilhaB(Pilha*pilha,int obj){
  if(pilha->topoB==0){
    printf("Pilha B cheia! \n");
    return;
  }
  pilha->topoB--;
  pilha->vetor[pilha->topoB]=obj;
}

// verifica se pilha A esta vazia
boolean vaziaA(Pilha*pilha){
  return pilha->topoA==-1;
}

// verifica se pilha B esta vazia
boolean vaziaB(Pilha*pilha){
  return pilha->topoB==MAX;
}

// desempilha objeto da pilha A
int desempilhaA(Pilha *pilha){
  if(vaziaA(pilha)){
    printf("Pilha A vazia! \n");
    return -1;
  }
  int obj=pilha->vetor[pilha->topoA];
  pilha->topoA--;
  return obj;
}

// desempilha objeto da pilha B
int desempilhaB(Pilha *pilha){
  if(vaziaB(pilha)){
    printf("Pilha B vazia! \n");
    return -1;
  }
  int obj=pilha->vetor[pilha->topoB];
  pilha->topoB++;
  return obj;
}

// veririca se pilha A esta cheia
boolean cheiaA(Pilha *pilha){
  return pilha->topoA==MAX-1;
}

// verifica se pilha B esta cheia
boolean cheiaB(Pilha*pilha){
  return pilha->topoB==1;
}

// retorna objeto do topo da pilha A
int topoA(Pilha *pilha){
  if(vaziaA(pilha)){
    printf("Pilha A vazia! \n");
    return -1;
  } return pilha->vetor[pilha->topoA];
}

// retorna objeto do topo da pilha B
int topoB(Pilha *pilha) {
  if(vaziaB(pilha)){
    printf("Pilha B vazia! \n");
    return -1;
  } return pilha->vetor[pilha->topoB];
}

// mostra elementos da pilha A
void mostrarPilhaA(Pilha *pilha){
  if(vaziaA(pilha)){
    printf("Pilha A vazia! \n");
    return; }
  for(int i=0;i<=pilha->topoA;i++){
    printf("%d ", pilha->vetor[i]);
  } printf("\n");
}

// mostra elementos da pilha B
void mostrarPilhaB(Pilha*pilha){
  if(vaziaB(pilha)){
    printf("Pilha B vazia! \n");
    return; }
  for(int i=pilha->topoB;i<MAX;i++){
    printf("%d ", pilha->vetor[i]);
  } printf("\n");
}

// retorna tamanho da pilha A
int tamanhoA(Pilha*pilha){
  return pilha->topoA+1;
}

// retorna tamanho da pilha B
int tamanhoB(Pilha*pilha){
  return MAX-pilha->topoB;
}