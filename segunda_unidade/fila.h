#include <stdlib.h>
#include <stdio.h>

// criar as funções
// struct fila Fila
// cria_fila
// fila_insere
// fila_retira
// fila_vazia 
// fila libera 

// fila com vetores 

#define N = 100;

// criando struct para fila implementada com vetor 

struct filav{
    int n; // número de elementos presentes na fila
    int ini; // para indicar o início da fila
    float [N]; // para armazenar o vetor

};
typedef struct filav FilaVetor;

// criando struct para fila implementada com lista encadeada simples

struct no
{
    float info; // informação armazenada na lista
    struct no* prox;
};
typedef struct no No;

struct lista{
    No* ini; //
    No* fim;
    int tam;
};

# ifndef FILA_H
# define FILA_H




























































#endif






