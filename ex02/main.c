#include "class.c"


int main(){
    Fila*fila1=criaFila();
    printf("Fila 1 (vazia):\n");
    mostrarFila(fila1);
    printf("Fila vazia? %s\n",vazia(fila1)?"Sim":"Não");

    // enfileira
    enfileira(fila1,10);
    printf("\nFila 1 após enfileirar um elemento:\n");
    mostrarFila(fila1);
    printf("Fila vazia? %s\n", vazia(fila1)?"Sim":"Não");
    printf("Cabeça: %d\n", cabeca(fila1));
    printf("Cauda: %d\n", cauda(fila1));

    // teste 1
    Fila*fila2=criaFila();
    enfileira(fila2,20);
    printf("\nFila 2 com um elemento:\n");
    mostrarFila(fila2);
    printf("Cabeça: %d\n", cabeca(fila2));
    printf("Cauda: %d\n", cauda(fila2));

    // enfileira 4
    Fila*fila3=criaFila();
    enfileira(fila3,30);
    enfileira(fila3,40);
    enfileira(fila3,50);
    enfileira(fila3,60);
    printf("\nFila 3 com quatro elementos:\n");
    mostrarFila(fila3);
    printf("Cabeça: %d\n", cabeca(fila3));
    printf("Cauda: %d\n", cauda(fila3));

    // desenfileira 1
    printf("\nDesenfileirando da Fila 3: %d\n", desenfileira(fila3));
    mostrarFila(fila3);

    // pesquisa
    printf("\nElemento 40 está na fila? %s\n", pesquisa(fila3,40)?"Sim":"Não");
    printf("Elemento 100 está na fila? %s\n", pesquisa(fila3,100)?"Sim":"Não");

    // teste tamanho
    printf("\nTamanho da Fila 3: %d\n", tamanho(fila3));

    // teste fila cheia
    Fila*fila4=criaFila();
    enfileira(fila4,70);
    enfileira(fila4,80);
    enfileira(fila4,90);
    enfileira(fila4,100);
    enfileira(fila4,110);
    enfileira(fila4,120);
    enfileira(fila4,130);
    enfileira(fila4,140);
    enfileira(fila4,150);
    enfileira(fila4,160);
    printf("\nFila 4 cheia:\n");
    mostrarFila(fila4);
    printf("Fila cheia? %s\n",cheia(fila4)?"Sim":"Não");
    return 0;
}