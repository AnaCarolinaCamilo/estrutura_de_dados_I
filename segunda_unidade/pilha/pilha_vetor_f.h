#include <stdlib.h>
#include <stdio.h>

#define MAX 10

// Biblioteca com funções de pilha para vetores

typedef struct pilha{
    int n;
    float v[MAX];
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



void pilha_push_vetor(Pilha* p, float f){

    if(p->n == MAX){
        printf("Capacidade da pilha estourada!");
    }
    // Colocar o valor na próxima posição possível 
    p->v[p->n] = f;
    p->n++;
}

float pilha_pop_vetor(Pilha* p){
    float f;
    if(pilha_vazia_vetor(p)){
        printf("pilha vazia!\n");
        exit(1);
    }
    // retirar o elemento do topo
    f = p->v[p->n-1];
    p->n--;
    return f;
}

void pilha_libera(Pilha* p){
    free(p);
}

float checar_topo (Pilha* p){
    if(pilha_vazia_vetor(p)){
        return 0;
    }
    return p->v[p->n-1];  // pegamos justamente o char no topo da pilha
}

float mostrar_topo (Pilha* p){
    if(pilha_vazia_vetor(p)){
        printf("Não tem topo!");
    }
    return p->v[p->n-1];
}

void pilha_imprime(Pilha* p){
    int i;
    for (i = p->n-1; i>= 0; i--)
    {
        printf("%.2f\n", p->v[i]);
    }
}

Pilha* concat_pilha(Pilha* p1, Pilha* p2){

    if (pilha_vazia_vetor(p1) || pilha_vazia_vetor(p2)) return NULL;
    if(pilha_vazia_vetor(p1)){
        pilha_imprime(p2);
        exit(1);
    }
    if(pilha_vazia_vetor(p2)){
        pilha_imprime(p1);
        exit(1);
    }
    Pilha* aux = pilha_cria_vetor(aux);

    while (!pilha_vazia_vetor(p2))
    {
        pilha_push_vetor(aux, pilha_pop_vetor(p2));
    }
    while (!pilha_vazia_vetor(aux))
    {
        pilha_push_vetor(p1, pilha_pop_vetor(aux));
    }

    return p1;
}

Pilha* copia_pilha (Pilha* p){
    Pilha* aux = pilha_cria_vetor(aux);
    Pilha* copia = pilha_cria_vetor(copia);
    int i;
    for(i=p->n-1; i>=0; i--){
        pilha_push_vetor(aux, p->v[i]);
    }
    for(i=aux->n-1; i>=0; i--){
        pilha_push_vetor(copia, aux->v[i]);
    }
    return copia;
}
#endif
