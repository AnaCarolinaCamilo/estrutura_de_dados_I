#include <stdlib.h>
#include <stdio.h>
#include "list_circular_ordenada.h"
int main(int argc, char const *argv[])
{
    int opcao, valor, anterior;
    Lista lista;
    No *removido;

    criar_lista(&lista);

    do
    {
        printf("\n\t 0 - Sair \n\t 1 - InserirInicio \n\t 2 - InserirFim \n\t 3 - InserirOrdenado \n\t 4 - Remover \n\t 5 - BuscarNum \n\t 6 - ImprimirLista");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            lst_insere_começo(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            lst_insere_final(&lista, valor);
            break;
        case 3:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento removido: %d\n", removido->valor);
                free(removido);
            }
            else printf("elemento inesistente!\n");
            break;
        case 5:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido) printf("Valor encontrado: %d\n", removido->valor);
            else printf("valor não encontrado!\n");
            break;
        case 6:
            imprimir(lista);
            break;
        default:
            if(opcao != 0) printf("opcao invalida!\n");
            break;
        }

    } while (opcao != 0);
    


    return 0;
}
