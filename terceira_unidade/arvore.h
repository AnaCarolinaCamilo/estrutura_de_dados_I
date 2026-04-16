# include <stdlib.h>
# include <stdio.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv* arv_cria_vazia(){
    return NULL;
}

Arv* arv_cria(int i, Arv* esq, Arv* dir){
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = i;
    p->esq = esq;
    p->dir = dir;
    return p;
}

int arv_vazia(Arv* a){
    return a == NULL;
}
Arv* arv_cria_no(int i){
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = i;
    p->esq = NULL;
    p->dir = NULL;


}
Arv* insere_n_recursivo(Arv** raiz, int dado){
    
    Arv* novo = arv_cria_no(dado);
    Arv* atual = *raiz;
    Arv* pai = NULL;

    while (atual != NULL)
    {
        pai = atual;
        if(dado < atual->info) atual = atual->esq;
        else if(dado > atual->info) atual = atual->dir;
        else return; 
    }
    if(pai == NULL) *raiz = novo;
    else if(dado < pai->info) pai->esq = novo;
    else pai->dir = novo;
}

static int max2 (int a, int b){
    return (a>b) ? a:b;
}

int arv_altura(Arv* a){
    if(arv_vazia(a))
        return -1;
    else
        return 1 + max2(arv_altura(a->esq->info), arv_altura(a->dir->info));
}

int qtd_nos(Arv* raiz){
    if(raiz == NULL) return 0;
    else return 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);

    return(raiz == NULL) ? 0 : 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);
}


void arv_mostra(Arv* a){ // mostrar infix
    printf("<");
    if(!arv_vazia(a)){
        printf("%d", a->info);
        arv_mostra(a->esq);
        arv_mostra(a->dir);
    }
    printf(">");
}

Arv* arv_libera(Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

void pre_ordem(Arv* a){
    printf("%d", a->info);
    if(a->esq != NULL){
        pre_ordem(a->esq);
    }
    if(a->dir != NULL){
        pre_ordem(a->dir);
    }
}

void em_ordem(Arv* a){      
    if(a->esq != NULL){
        em_ordem(a->esq);
    }
    printf("%d", a->info);
    if(a->dir != NULL){
        em_ordem(a->dir);
    }
}

void pos_ordem(Arv* a){
    if(a->esq != NULL){
        em_ordem(a->esq);
    }
    if(a->dir != NULL){
        em_ordem(a->dir);
    }
    printf("%d", a->info);
}
