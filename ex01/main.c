#include "class.c"

int main(){
    int opcao;
    char nome[maxLength];
    char nAntigo[maxLength],nNovo[maxLength];
    char nomeArquivo[]="nomes.txt";
    lerNomes(nomeArquivo);
    do{
        printf("\nOpções:\n");
        printf("1. Adicionar um nome\n");
        printf("2. Pesquisar um nome\n");
        printf("3. Remover um nome\n");
        printf("4. Renomear um nome\n");
        printf("5. Verificar se a estrutura está vazia\n");
        printf("6. Contar a quantidade de nomes cadastrados\n");
        printf("7. Imprimir todos os nomes\n"); //opcional
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1: 
                printf("Digite o nome a ser adicionado: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")]='\0';
                adicionarNomeArquivo(nome, nomeArquivo);
                break;
            case 2: 
                printf("Digite o nome a ser pesquisado: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")]='\0';
                buscarNome(nome);
                break;
            case 3:
                printf("Digite o nome a ser removido: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")]='\0';
                removerNome(nome);
                break;
            case 4: 
                printf("Digite o nome a ser renomeado: ");
                fgets(nAntigo, sizeof(nAntigo), stdin);
                nAntigo[strcspn(nAntigo, "\n")]='\0';
                printf("Digite o novo nome: ");
                fgets(nNovo, sizeof(nNovo), stdin);
                nNovo[strcspn(nNovo, "\n")]='\0';
                renomearNome(nAntigo, nNovo);
                break;
            case 5: 
                if(estaVazia()){
                    printf("A estrutura está vazia.\n");
                }else{
                    printf("A estrutura não está vazia.\n");
                }
                break;
            case 6:
                printf("Quantidade de nomes cadastrados: %d\n", contarNomes());
                break;
            case 7:
                imprimirNomes();
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
            printf("Opção inválida! Tente novamente.\n");
        }
    } 
    while(opcao!=8); 
    clear();
    return 0;
}