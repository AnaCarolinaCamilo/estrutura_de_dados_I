#include <stdlib.h>
#include <stdio.h>


typedef struct No
{
    char info;
    struct No* prox;
}No;

typedef struct pilha
{
    No* topo;
}Pilha;

# ifndef PILHA_H
# define PILHA_H

Pilha* pilha_cria(void){
    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_push (Pilha* p, char v){
    No* n = (No*)malloc(sizeof(No));
    n->info = v;
    n->prox = p->topo;
    p->topo = n;
}

int pilha_vazia(Pilha* p){
    return(p->topo==NULL);
}

char pilha_pop(Pilha* p){
    No* t;
    char v;
    if(pilha_vazia(p)){
        printf("Pilha vazia!\n");
        exit(1);
    }
    t = p->topo;
    v = t->info;
    p->topo = t->prox;
    return v;
    free(t);
}



void pilha_libera(Pilha* p){
    No* q = p->topo;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_imprime(Pilha* p){
    No* q;
    for(q=p->topo; q!=NULL; q=q->prox){
        printf("%c\n", q->info);
    }
}

char pilha_topo(Pilha* p) {
    // 1. Verifica se a pilha ou o topo é NULL
    if (p == NULL || p->topo == NULL) {
        printf("Pilha vazia!\n");
        return '\0'; // Retorna caractere nulo indicando erro
    }
    
    // 2. Acessa o info do nó topo diretamente
    char topoc = p->topo->info;
    
    return topoc;
}





















































#endif

