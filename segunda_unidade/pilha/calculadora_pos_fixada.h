#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha_vetor.h"


// Calc* calc_cria (char* f);
// void calc_operando (Calc* c, float v);
// void calc_operador (Calc* c, char op);
// void calc_libera(Calc* c);


typedef struct calc {
    char f[21]; // formato da expressão
    Pilha* p; // pilha para fazer as operações
}Calc;

// criar pilha vazia
Calc* calc_cria (char* formato){
    Calc* c = (Calc*)malloc(sizeof(Calc)); 
    strcpy(c->f, formato);
    c->p = pilha_cria_vetor(c->p);
    return c;
}

void calc_numero(Calc* c, int v){
    // reconhecer os numeros e dar push na pilha
    pilha_push_vetor(c->p, v);
    // imprime o topo da pilha
    printf("%d\n", (c->f,v));
}

void calc_operador(Calc*c, char op){
    int v1,v2,v;
    // desempilhando os numeros
    if(pilha_vazia_vetor(c->p)){
        v2 = 0;
    }
    else v2 = ((int)pilha_pop_vetor(c->p));
    if(pilha_vazia_vetor(c->p)){
        v1 = 0;
    } 
    else v1 = ((int)pilha_pop_vetor(c->p));

    // fazer as operações
    switch (op)
    {
    case '+': v = v1+v2; break;
    case '-': v = v1-v2; break;
    case '*': v = v1*v2; break;
    case '/': v = v1/v2; break;
    }
    pilha_push_vetor(c->p, v); // empilhar resultado
    printf("%d\n", (c->f,v)); //imprime topo da lista
}
void calc_libera(Calc* c){
    pilha_libera(c->p);
    free(c);
}

void verifica_expressao(Calc* c){
    if(pilha_vazia_vetor(c->p)){
        printf("expressao invalida\n");
        exit(1);

    }
    if((c->p->n > 1)){
        printf("expressao invalida\n");
        exit(1);
    }
}














# ifndef FILA_H
# define FILA_H
















































#endif
