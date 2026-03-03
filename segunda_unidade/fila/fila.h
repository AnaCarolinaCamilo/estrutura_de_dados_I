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

#define N 5

// criando struct para fila implementada com vetor 

struct filav{
    int n; // número de elementos presentes na fila
    int ini; // para indicar o início da fila
    float vet[N]; // para armazenar o vetor

};
typedef struct filav FilaVetor;

// criando struct para fila implementada com lista encadeada simples

struct no
{
    float info; // informação armazenada na lista
    struct no* prox;
};
typedef struct no No;

struct filaLista{
    No* ini; 
    No* fim;
};

typedef struct filaLista FilaLista;

# ifndef FILA_H
# define FILA_H


// operações de fila implementada em vetor

FilaVetor* fila_vetor_cria(void){
    FilaVetor* f = (FilaVetor*)malloc(sizeof(FilaVetor));
    if(f != NULL){
    f->n = 0;
    f->ini = 0;
    return f;
    }
    else printf("Não foi possível alocar a memória");
}

void fila_insere_vetor(FilaVetor* f, float v){
    int fim;
    if(f->n == N){ // fila está cheia 
        printf("A capacidade da fila estorou.\n");
        exit(1);
    }
    // insere elemento na próxima posição livre 
    fim = (f->ini + f->n) % N;  // posição final utilizando o elemento circular
    f->vet[fim] = v; // insere na posição final
    f->n++; // atualiza o número de elementos

}

int fila_vazia_vetor(FilaVetor* f){
    return(f->n == 0);
}

float fila_retira_vetor(FilaVetor* f){
    float v;
    if(fila_vazia_vetor(f)){
        printf("Fila está vazia.\n");
        exit(1);
    }
    // retirar elemento do inicio
    v = f->vet[f->ini]; // adentrando o vetor e localizando o início
    f->ini = (f->ini + 1) % N; //posição inicial utilizando o elemento circular 
    f->n--; // atualiza número de elementos
    return v;
}



FilaVetor* libera_fila_vetor(FilaVetor* f){
    free(f);
}

void fila_imprime(FilaVetor* f){
    int i;
    for (i = 0; i<f->n; i++)
    {
        printf("%f\n", f->vet[(f->ini+i)%N]);
    }
    
}

// operações com a fila implementada com lista encadeada simples

FilaLista* fila_lista_cria(void){
    FilaLista* f = (FilaLista*)malloc(sizeof(FilaLista));
    if(f!=NULL){
    f->ini=NULL;
    f->fim=NULL;
    return f;
    }
    else printf("Não foi possível alocar a memória");
}

int fila_lista_insere(FilaLista* f, float v){
    if(f == NULL) return 0;
    No* n = (No*)malloc(sizeof(No));
    if(n != NULL){
    n->info = v; // armazenando a informação
    n->prox = NULL; // novo nó passa a ser o último
    if(f->fim != NULL){ // verifia se a lista não está vazia
        f->fim->prox = n; 
    }
    else{
        f->ini = n;// fila estava vazia
    }
    f->fim = n; // fila aponta para novo elemento
    return 1;
    }
    else{
        printf("Não foi possível alocar a memória");
    }
}

int fila_lista_vazia(FilaLista* f);

float fila_lista_retira(FilaLista* f){
    if(f == NULL) return 0;
    if(f->ini == NULL) return 0; //fila vazia
    float v;
    No* t = f->ini;
    v = t->info;
    f->ini = f->ini->prox;

    if(f->ini == NULL) f->fim = NULL; //lista ficou vazia
    free(t);
    return v;
}

int fila_lista_vazia(FilaLista* f){
    return(f->ini==NULL);
}

void libera_fila_lista(FilaLista* f){
    if(f != NULL){
    No* q = f->ini; // ponteiro apontando para o inicio da lista
    while (q != NULL)
    {
        No* t = q->prox; // liberando os elementos pelo início
        free(q);
        q = t; // encerra quando chegar no final da lista 
    }
    free(f);
}
}

void fila_imprime_lista(FilaLista* f){
    if(f==NULL) printf("fila vazia não foi possível imprimir");
    if(f->ini == NULL) printf("fila vazia não foi possível imprimir");
    No* q;
    for(q=f->ini; q!= NULL; q=q->prox){
        printf("%f\n", q->info);
    }

}






































































#endif






