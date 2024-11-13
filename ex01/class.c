#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "no.c"

#define maxLength 100
No *nIndex[26]={NULL};

void updateList(const char *nArquivo);

// obtem a letra inicial do nome
int indice(char *nome){
    return tolower(nome[0])-'a';
}

// cria um nó com nome constado
No* criarNo(char *nome){
    No *novoNo=(No *)malloc(sizeof(No));
    novoNo->nome=strdup(nome);
    novoNo->anterior=NULL;
    novoNo->proximo=NULL;
    return novoNo;
}

// adiciona um nome na lista correspondente
void addNome(char *nome){
    int i=indice(nome);
    No *novoNo=criarNo(nome);

    if(nIndex[i]==NULL){
        nIndex[i]=novoNo;
    }else{
        No*atual=nIndex[i];
        No*anterior=NULL;
        while(atual!=NULL&&strcmp(
            atual->nome, nome)<0){
            anterior=atual;
            atual=atual->proximo;
        }
        if(anterior==NULL){ 
            novoNo->proximo=nIndex[i];
            nIndex[i]->anterior=novoNo;
            nIndex[i]=novoNo;
        }else if(atual==NULL){
            anterior->proximo=novoNo;
            novoNo->anterior=anterior;
        }else{
            anterior->proximo=novoNo;
            novoNo->anterior=anterior;
            novoNo->proximo=atual;
            atual->anterior=novoNo;}
    }
}

// adiciona um nome ao arquivo nomes.txt
void adicionarNomeArquivo(char *nome, const char *nArquivo){
    addNome(nome);
    FILE*arquivo=fopen(nArquivo, "a");
    if(arquivo==NULL){
        perror("Erro ao abrir o arquivo!");
        return;
    }
    fprintf(arquivo, "%s\n", nome);
    fclose(arquivo);
    printf("'%s' foi adicionado com sucesso! \n", nome);
}

// pesquisa um nome existe na estrutura de dados
void buscarNome(char *nome){
    int i=indice(nome);
    No*atual=nIndex[i];
    while(atual!=NULL){
        if(strcmp(atual->nome, nome)==0){
            printf("'%s' encontrado. \n", nome);
            return;
        } atual=atual->proximo;
    }
    printf("'%s' não foi encontrado.  \n", nome);
}

// renomeia um nome na lista
void renomearNome(char *nAntigo, char *nNovo){
    int i=indice(nAntigo);
    No*atual=nIndex[i];
    while(atual!=NULL&&strcmp(atual->nome, nAntigo)!=0){
        atual=atual->proximo;
    }
    if(atual==NULL){
        printf("Nome '%s' não encontrado! \n", nAntigo);
        return;
    }
    free(atual->nome);
    atual->nome=strdup(nNovo);
    updateList("nomes.txt");
    FILE*arquivo=fopen("nomes.txt", "w");
    if(arquivo==NULL){
        printf("Erro ao abrir o arquivo! \n");
        return;}
    for(int i=0;i<26;i++){
        No*atual=nIndex[i];
        while(atual!=NULL){
            fprintf(arquivo, "%s\n", atual->nome);
            atual=atual->proximo;
        }
    } fclose(arquivo);
    printf("Nome '%s' foi renomeado para '%s' com sucesso!\n", nAntigo, nNovo);
}


// faz a leitura dos nomes contidos no arquivo nomes.txt
void lerNomes(const char *nArquivo){
    FILE*arquivo=fopen(nArquivo, "r");
    if(arquivo==NULL){
        perror("Erro ao abrir o arquivo!");
        return;}
    char linha[maxLength];
    while(fgets(linha, sizeof(linha), arquivo)){
        linha[strcspn(linha, "\n")]='\0';
        addNome(linha);
    } fclose(arquivo);
}

// imprime todos os nomes
void imprimirNomes(){
    for(int i=0;i<26;i++){
        No*atual=nIndex[i];
        if(atual!=NULL){
            printf("Letra %c:\n",'A'+i);
            while(atual!=NULL){
                printf("  %s\n",atual->nome);
                atual=atual->proximo;
            }
        }
    }
}
void updateList(const char *nArquivo){
    FILE*arquivo=fopen(nArquivo, "w");
    if(arquivo==NULL){
        perror("Erro ao abrir o arquivo para escrita!");
        return;
    }
    for(int i=0;i<26;i++){
        No*atual=nIndex[i];
        while(atual!=NULL){
            fprintf(arquivo, "%s\n", atual->nome);
            atual=atual->proximo;
        }
    }fclose(arquivo);
}

// busca e remove um nome específico
void removerNome(char *nome){
    int i=indice(nome);
    if(i<0||i>=26){
        printf("Nome '%s' não é válido.\n", nome);
        return;
    }
    No*atual=nIndex[i];
    while(atual!=NULL&&strcmp(atual->nome, nome)!=0){
        atual=atual->proximo;
    }
    if(atual==NULL){
        printf("Nome '%s' não encontrado.\n", nome);
        return;
    } 
    if(atual->anterior!=NULL){
        atual->anterior->proximo=atual->proximo;
    }else{
        nIndex[i]=atual->proximo;
    }
    if(atual->proximo!=NULL){
        atual->proximo->anterior=atual->anterior;
    }
    free(atual->nome);
    free(atual);
    printf("Nome '%s' removido com sucesso! \n", nome);
    updateList("nomes.txt");
}

void clear(){
    for(int i=0;i<26;i++){
        No*atual=nIndex[i];
        while(atual!=NULL){
            No*temp=atual;
            atual=atual->proximo;
            free(temp->nome);
            free(temp);
        }nIndex[i]=NULL;
    }
}
// verifica se a estrutura está vazia
int estaVazia(){
    for(int i=0;i<26;i++){
        if(nIndex[i]!=NULL){
            return 0;}
    } return 1;
}
// retorna a quantidade de nomes cadastrados
int contarNomes(){
    int contador=0;
    for(int i=0;i<26;i++){
        No *atual=nIndex[i];
        while(atual!=NULL){
            contador++;
            atual=atual->proximo;}
    } return contador;
}