#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int info;
    struct no *proximo;
    struct no *ant;
} No;
typedef No*;
typedef struct lista
{
    No *inicio;
    No *fim;
    int tam;
}Lista;


#ifndef LIST_DUPLAMENTE_CIRCULAR_H
#define LIST_DUPLAMENTE_CIRCULAR_H

void cria_lista(LISTA* pl){
    *pl = (LISTA)malloc(sizeof(No));
    if(!(*pl)){
        printf("\nMemória insuficiente!");
        exit(1);
    }
    (*pl)->info=0;
    (*pl)->ant=(*pl)->proximo=*pl;
}

int eh_vazia(LISTA l){
    return(l->info == 0);
}

void lst_insere_começo(lista, int i)
{
    No *novo = (No*)malloc(sizeof(No)); 
    if( novo == NULL){
        printf("falha na alocação de memória");
    }
    else{
        novo->info = i;
        novo->proximo = lista-> ;
        lista->inicio = novo;
        if(lista->fim == NULL) lista->fim = novo;
        lista->fim->proximo = lista->inicio;
        lista->tam++;

    
    }

}

void inserir(LISTA l, int v, int k){
    LISTA aux, novo;
    if(k<1 || k > tam(l)+1){
        printf("\nERRO! Posição invalida!\n");
        exit(1);
    }
    novo = (LISTA)malloc(sizeof(No));
    if(!novo){
        printf("\nERRO!\n");
        exit(1);
    }
    novo->info = v;
    for(aux=l; k>1; aux=aux->proximo, k--){
        novo->proximo = aux->proximo;
        novo->ant = aux;
        aux->proximo = novo;
        novo->proximo->ant = novo;
        l->info++;
    }
}

void ret (LISTA l, int k){
    if(k<1 || k>tam(l)){
        printf("Erro! posição inválida!");
        exit(1);
    }
    l->info--;
    for(;k>0;k--,l=l->proximo);
    l->ant->proximo = l->proximo;
    l->proximo->ant = l->ant;
    free(l);

}

void l2circ_imprime_rev(LISTA l){
    LISTA p = l; // aponta para o nó inicial
    // testa se a lista não é vazia e então percorre do-while
    if(p) do
    {
        printf("%d\n", p->info); // imprime a informação do nó
        p = p->ant; // avança para a posião
    } while (p!=l);
}


#endif
