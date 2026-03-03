#include <stdlib.h>
#include <stdio.h>

// criar as funções
// struct fila2 Fila2
// cria_fila2
// fila2_insere_ini
// fila2_insere_fim
// fila2_retira_ini
// fila2_retira_fim
// fila_vazia 
// fila libera 

typedef struct no
{
    float info;
    struct no* prox;
    struct no* ant;
}No;

typedef struct fila2
{
    No* ini;
    No* fim;
}Fila2;

# ifndef FILA_H
# define FILA_H

Fila2* fila2_cria(void){
    Fila2* f = (Fila2*)malloc(sizeof(Fila2));
    if(f!=NULL){
    f->ini=NULL;
    f->fim=NULL;
    return f;
    }
    else printf("Não foi possível alocar a memória");
}

int fila2_vazia(Fila2* f){
    return(f->ini==NULL);
}

// função auxiliar para inserir no início

static No* ins2_ini(No* ini,float v){
    No* p = (No*)malloc(sizeof(No));
    p->info = v;
    p->prox = ini;
    p->ant = NULL;
    if(ini != NULL) ini->ant = p; // verifica se a lista ta vazia
    return p;

}

// função auxilia para inserir no fim

static No* ins2_fim(No* fim, float v){
    No* p = (No*)malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    p->ant = fim;
    if(fim!=NULL) fim->prox=p; //verifica se a lista ta vazia
    return p;
}

// função auxiliar retirar do início

static No* ret2_ini (No* ini){
    No* p = ini->prox;
    if(p!=NULL) p->ant; // verifica se a lista ficou vazia
    free(ini);
    return p;   
}

// função auxiliar retirar do fim

static No* ret2_fim(No* fim){
    No* p = fim->ant;
    if(p!= NULL) p->prox = NULL;
    free(fim);
    return p;
}

// funções que manipulam a fila e atualizam os ponteiros

void fila2_insere_ini (Fila2* f, float v){
    f->ini = ins2_ini(f->ini,v);
    if(f->fim == NULL) f->fim = f->ini; // fila estava vazia
}

void fila2_insere_fim(Fila2* f, float v){
    f->fim = ins2_fim(f->fim,v);
    if(f->ini== NULL) f->ini = f->fim; // fila estava vazia
}

float fila2_retira_ini(Fila2* f){
    float v;
    if(fila2_vazia(f)){
        printf("Fila vazia\n");
        return 0;
    }
    v = f->ini->info;
    f->ini = ret2_fim(f->ini);
    if(f->ini == NULL) f->fim = NULL; // fila ficou vazia
    return v;
}

float fila2_retira_fim(Fila2* f){
    float v;
    if(fila2_vazia(f)){
        printf("fila vazia\n");
        return 0;
    }
    v = f->fim->info;
    f->fim = ret2_fim(f->fim);
    if(f->fim == NULL) f->ini= NULL; // fila ficou vazia
    return v;
}
void libera_fila2(Fila2* f){
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

// void fila2_imprime (Fila2* f){
//     No* q;
//     for(q=f->ini; q!=NULL; q=q->prox) printf("%f\n", q->info);
// }

// void imprimirFila(Fila2* dq) {
//     if (dq->ini == NULL) {
//         printf("Fila vazia\n");
//         return;
//     }

//     No* temp = dq->ini;
//     printf("Fila: ");
//     while (temp != NULL) {
//         printf("%f\n ", temp->info);
//         temp = temp->prox;
//     }
//     printf("\n");
// }


}






























































#endif




