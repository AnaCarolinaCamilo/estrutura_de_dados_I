// biblioteca com funções relacionadas a lista

# include <stdlib.h>
# include <stdio.h>

struct Lista
{
    int info;
    struct Lista* prox;
    
};
typedef struct Lista Lista;



# ifndef LIST_H
# define LIST_H

// cria uma lista vazia
Lista* lista_cria(void){
    return NULL;
}

// inserção no começo da lista (retorna a atualizada)

void lst_insere_começo(Lista **lista, int i)
{
    Lista *novo = (Lista*)malloc(sizeof(Lista)); 
    if( novo == NULL){
        printf("falha na alocação de memória");
    }
    else{
        novo->info = i;
        novo->prox = *lista;
        *lista = novo;
    }

}

// inserção no fim da lista 

void lis_insere_final(Lista **lista, int i){
    Lista *aux,*novo = (Lista*)malloc(sizeof(Lista));
    if(novo){
        novo->info = i;
        novo ->prox = NULL;

        // verificando se a lista está vazia
        if (*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->prox)
            {
                aux = aux -> prox;
            }
            aux ->prox = novo;
            

        }
        
    }
    else{
        printf("erro ao alocar memória");
    }
}

// inserção no meio da lista

void inserir_no_meio(Lista **lista, int i, int ant){
    Lista *novo, *aux = (Lista*)malloc(sizeof(Lista));
    if(novo){
        novo->info = i;
        // checando se a lista está vazia
        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->info != ant && aux->prox)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;

        }

    }
}

// função de imprimir a lista
void lst_imprime(Lista *lista){
    printf("\n Lista: ");
    while (lista)
    {
        printf("%d\n", lista->info);
    }
}
// função de busca: busca um elemento na lista

Lista* lst_busca(Lista **lista, int i){
    Lista *p;
    while (p->prox)
    {
        if(p->info == i) return p;
    }
    return NULL;
}

Lista* lst_retira(Lista *lista, int i){
    Lista *ant = NULL; // ponteiro pro elemento anterior
    Lista *p = lista; // ponteiro para percorrer a lista

    // procura elemento na lista, guardando o anterior

    while (p != NULL && p->info != i)
    {
        ant = p;
        p = p->prox;

    }

    // verifica se achou o elemento
    if (p == NULL)
    {
        return NULL;
    }
    // retira elemento
    if(ant == NULL){
        // retira elemento do inicio
        lista = p->prox;
    }
    else{
        // retira elemento do meio da lista 
        ant->prox = p->prox;
    }
    free(p);
    return lista;
}

// função para liberar lista

void lst_libera(Lista *lista){

    Lista *p = lista;
    while (p != NULL)
    {
        Lista *t = p->prox; // guarda referência pro próximo elemento
        free(p); // libera a memória apontada por p
        p=t; // faz o p apontar pro próximo
    }
}

int lst_igual(Lista *l1, Lista *l2){
    Lista *p1; // ponteiro para percorrer l1
    Lista *p2; // ponteiro para percorrer l2

    for (p1=l1, p2=l2; p1!=NULL&&p2!=NULL; p1=p1->prox, p2=p2->prox)
    {
        if(p1->info != p2->info){
            return 0;
        }
    }
    return p1==p2; 
}










#endif