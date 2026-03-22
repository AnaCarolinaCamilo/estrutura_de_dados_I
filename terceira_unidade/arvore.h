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
