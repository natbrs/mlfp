#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

// cria fila vazia
Fila*criaFila(){
    Fila *fila=(Fila *)malloc(sizeof(Fila));
    if (fila==NULL){
        printf("Erro na alocação de memória! \n");
        exit(1);
    }
    fila->frente=0;
    fila->final=0;
    fila->tam=0;
    return fila;
}

// insere um elemento na fila
void enfileira(Fila*fila,int obj){
    if(fila->tam==maxTam){
        printf("Fila cheia!\n");
        return;
    }
    fila->elementos[fila->final]=obj;
    fila->final=(fila->final+1)%maxTam;
    fila->tam++;
}

// remove um elemento da fila
int desenfileira(Fila*fila){
    if(fila->tam==0){
        printf("Fila vazia!\n");
        return -1;
    }
    int obj=fila->elementos[fila->frente];
    fila->frente=(fila->frente+1)%maxTam;
    fila->tam--;
    return obj;
}

// obtem primeiro elemento
int cabeca(Fila*fila){
    if(fila->tam==0){
        printf("Fila vazia!\n");
        return -1;
    }
    return fila->elementos[fila->frente];
}

// obtem ultimo elemento
int cauda(Fila*fila){
    if(fila->tam==0){
        printf("Fila vazia!\n");
        return -1;
    }
    return fila->elementos[(fila->final-1+maxTam)%maxTam];
}

// verifica se a fila esta vazia
int vazia(Fila*fila){
    return fila->tam==0;
}

// verifica se a fila esta cheia
int cheia(Fila*fila) {
    return fila->tam==maxTam;
}

// Função para mostrar todos os elementos da fila
void mostrarFila(Fila *fila){
    if(vazia(fila)){
        printf("Fila vazia!\n");
        return;
    }
    for(int i=0;i<fila->tam;i++){
        printf("%d ", fila->elementos[(fila->frente+i)%maxTam]);
    } printf("\n");
}

// Função para pesquisar um elemento na fila
int pesquisa(Fila*fila,int obj){
    for(int i=0;i<fila->tam;i++){
        if(fila->elementos
            [(fila->frente+i)%maxTam]==obj){
            return 1;
        }
    } return 0;
}

// retorna tamanho da fila
int tamanho(Fila*fila){
    return fila->tam;
}