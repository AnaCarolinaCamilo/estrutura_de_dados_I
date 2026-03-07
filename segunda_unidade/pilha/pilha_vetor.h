#include <stdlib.h>
#include <stdio.h>

#define MAX 10

// Biblioteca com funções de pilha para vetores

typedef struct pilha{
    int n;
    char v[MAX];
}Pilha;


Pilha* pilha_cria_vetor(Pilha* p){
    p = (Pilha*)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

int pilha_vazia_vetor(Pilha* p){
    if(p->n == 0) return 1;
    else return 0;
}

# ifndef PILHA_H
# define PILHA_H



void pilha_push_vetor(Pilha*p, char c){

    if(p->n == MAX){
        printf("Capacidade da pilha estourada!");
    }
    // Colocar o valor na próxima posição possível 
    p->v[p->n] = c;
    p->n++;
}

char pilha_pop_vetor(Pilha* p){
    char c;
    if(pilha_vazia_vetor(p)){
        printf("pilha vazia!\n");
    }
    // retirar o elemento do topo

    c = p->v[p->n-1];
    p->n--;
    return c;
}

void pilha_libera(Pilha* p){
    free(p);
}

int checar_topo (Pilha* p){
    if(pilha_vazia_vetor(p)){
        return 0;
    }
    return p->v[p->n];  // pegamos justamente o char no topo da pilha
}

char mostrar_topo (Pilha* p){
    if(pilha_vazia_vetor(p)){
        printf("Não tem topo!");
    }
    return p->v[p->n];

}
 
#endif
