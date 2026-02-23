#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int valor;
    struct no *proximo;
}No; 

typedef struct 
{
    No *inicio;
    No *fim;
    int tam;
}Lista;

# ifndef LIST_CIRCULAR_H
# define LIST_CIRCULAR_H

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

// inserção no começo da lista (retorna a atualizada)

void lst_insere_começo(Lista *lista, int i)
{
    No *novo = (No*)malloc(sizeof(Lista)); 
    if( novo == NULL){
        printf("falha na alocação de memória");
    }
    else{
        novo->valor = i;
        novo->proximo = lista->inicio ;
        lista->inicio = novo;
        if(lista->fim == NULL) lista->fim = novo;
        lista->fim->proximo = lista->inicio;
        lista->tam++;

    
    }

}

// inserção no fim da lista 

void lst_insere_final(Lista *lista, int i){
    No *aux,*novo = (No*)malloc(sizeof(Lista));
    if(novo){
        novo->valor = i;

        // verificando se a lista está vazia
        if (lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else{
            lista->fim->proximo = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        lista->tam++;
        
    }
    else{
        printf("erro ao alocar memória");
    }
}

// inserir ordenado

void inserir_ordenado(Lista *lista, int i){
    No *aux, *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = i;
        if(lista->inicio == NULL){
            lst_insere_começo(lista,i);
        }
        else if(novo->valor < lista->inicio->valor){
            lst_insere_começo(lista, i);
        }
        else{
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            if(aux->proximo == lista->inicio) lst_insere_final(lista,i);
            else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;
            }
            
        }
    }
    else printf("falha em alocar memória!\n");
}

No* remover(Lista *lista, int i){
    No *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->valor == i){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }
        else if(lista->inicio->valor == i){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && aux->proximo->valor != i){
                aux = aux->proximo;
            }
            if(aux->proximo->valor == i){
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
                }
                else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tam--;
            }
            
        }
    }
    return remover;
}

No* buscar(Lista *lista, int i){
    No *aux = lista->inicio;
    if(aux){
        do
        {
            if(aux->valor == i) return aux;
            aux = aux->proximo;
        } while (aux != lista->inicio);
        
    }
    return NULL;

}

void imprimir(Lista lista){
    No *no = lista.inicio;
   printf("\n\tLista tam %d: ", lista.tam);
   if(no){
        do{
            printf("%d", no->valor);
            no = no->proximo;
        }
        while (no != lista.inicio);
        printf("\nInicio: %d\n", no->valor);
    }
    printf("\n\n");
}
#endif

