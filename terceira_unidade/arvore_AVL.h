# include <stdlib.h>
# include <stdio.h>

typedef struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
    short altura;
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
    if(p){
        p->info = i;
        p->esq = NULL;
        p->dir = NULL;
        p->altura = 0;
    }
    else printf("Erro ao alocar memória");

    return p;
}
void insere_n_recursivo(Arv** raiz, int dado){
    
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
    if (a > b)
    {
        return a;
    }
    else if (b > a){
        return b;
    }
}

int arv_altura_alt(Arv* a){
    if(arv_vazia(a))
        return -1;
    else
        return a->altura;
}
int arv_altura(Arv* a){
    if(arv_vazia(a))
        return -1;
    else
        return 1 + max2(arv_altura(a->esq), arv_altura(a->dir));
}

short fatorBalanceamento(Arv* a){
    if(a) return(arv_altura(a->esq) - arv_altura(a->dir));
    else return 0;
}



int qtd_nos(Arv* raiz){
    if(raiz == NULL) return 0;
    else return 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);

    return(raiz == NULL) ? 0 : 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);
}

Arv* rotacao_esquerda(Arv* a){
    Arv* y, *f;

    y = a->dir;
    f = a->esq;

    y->esq = a;
    a->dir = f;

    a->altura = max2(arv_altura(a->esq), arv_altura(a->dir)) + 1;
    y->altura = max2(arv_altura(y->esq), arv_altura(y->dir)) + 1;

    return y;
}

Arv* rotacao_direita(Arv* a){
    Arv* y, *f;

    y = a->esq;
    f = a->dir;

    y->dir = a;
    a->esq = f;

    a->altura = max2(arv_altura(a->esq), arv_altura(a->dir)) + 1;
    y->altura = max2(arv_altura(y->esq), arv_altura(y->dir)) + 1;

    return y;
}

Arv* rotacao_direita_esquerda(Arv* a){
    a->dir = rotacao_direita(a->dir);
    return rotacao_esquerda(a);
}

Arv* rotacao_esquerda_direita(Arv* a){
    a->esq = rotacao_esquerda(a->esq);
    return rotacao_direita(a);
}

Arv* balancear(Arv* a){
    short fb = fatorBalanceamento(a);
    if(fb < -1 && fatorBalanceamento(a->dir) <= 0) a = rotacao_esquerda(a);
    else if(fb > 1 && fatorBalanceamento(a->esq) <= 0) a = rotacao_direita(a);
    else if(fb > 1 && fatorBalanceamento(a->esq) < 0) a = rotacao_esquerda_direita(a);
    else if(fb < -1 && fatorBalanceamento(a->dir) > 0) a = rotacao_direita_esquerda(a);

    return a;
}

Arv* inserir_balanceado(Arv* raiz, int x){
    // fazendo a inserção normalmente
    if(raiz == NULL) return arv_cria_no(x);
    else{
        if(x < raiz->info) raiz->esq = inserir_balanceado(raiz->esq, x);
        else if(x > raiz->info) raiz->dir = inserir_balanceado(raiz->dir, x);
        else printf("Inserção não realizada");   
    }
    // fazendo o balanceamento
    raiz->altura = max2(arv_altura(raiz->esq), arv_altura(raiz->dir)) + 1;
    raiz = balancear(raiz);
    return raiz;
}




void arv_mostra(Arv* a){ // mostrar infix
    printf("  ");
    if(!arv_vazia(a)){
        printf("%d", a->info);
        arv_mostra(a->esq);
        arv_mostra(a->dir);
    }
    printf("  ");
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
