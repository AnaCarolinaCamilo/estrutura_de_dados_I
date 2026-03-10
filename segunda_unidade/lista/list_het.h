#include <stdio.h>
#include <stdalign.h>

#define RET '0'
#define TRI '1'
#define CIR  '2'
#define PI 3.14


// definindo os tipos 

typedef struct retangulo{
    float b;
    float h;
} Retangulo;

typedef struct triangulo{
    float b;
    float h;

}Triangulo;

typedef struct circulo
{
    float r;
}Circulo;

// definindo nó da estrutura

typedef struct list_het
{
    char tipo;
    void* info;
    struct list_het* prox;
}Lista_het;

// criar nó com um retângulo

Lista_het* cria_ret (float b, float h){
    Retangulo* r;
    Lista_het* p;
    // alocar retângulo
    r = (Retangulo*)malloc(sizeof(Retangulo));
    r->b = b;
    r->h = h;
    // aloca o nó

    p = (Lista_het*)malloc(sizeof(Lista_het));
    p->tipo = RET;
    p->info = r;
    p->prox = NULL;
    return p;
}

// criar nó de um triângulo

Lista_het* cria_tri (float b, float h){
    Triangulo* t;
    Lista_het* p;
    // alocar triângulo
    t = (Triangulo*)malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;
    // aloca o nó
    p = (Lista_het*)malloc(sizeof(Triangulo));
    p->tipo = TRI;
    p->info = t;
    p->prox = NULL;

    return p;
}

//criar nó de um círculo

Lista_het* cria_cir(float r){
    Circulo* c;
    Lista_het* p;
    // alocar o círculo
    c = (Circulo*)malloc(sizeof(Circulo));
    c->r = r;
    // alocar o nó
    p = (Lista_het*)malloc(sizeof(Lista_het));
    p->tipo = CIR;
    p->info = c;
    p->prox = NULL;

    return p;
}

// função de inserção

void lst_insere_começo(Lista_het** p, Lista_het* forma_geometrica)
{
    Lista_het *novo = (Lista_het*)malloc(sizeof(Lista_het)); 
    if (novo == NULL) {
        printf("falha na alocação de memória");
    }
    else{
        novo->info = forma_geometrica->info;
        novo->tipo = forma_geometrica->tipo;
        novo->prox = *p;
        *p = novo;
    }

}


// função auxiliar: calcula área correspondente ao nó 

static float area (Lista_het* p){
    float a; // area do elemento
    switch (p->tipo)
    {
    case RET:
        // converte para retângulo e calcula a área
        Retangulo *r = (Retangulo*) p->info;
        a = r->b * r->h;
        break;
    case TRI:
        // converte para retângulo e calcula a área
        Triangulo *t = (Triangulo*) p->info;
        a = (t->b * t->h) / 2;
        break;
    case CIR:
        // converte para retângulo e calcula a área
        Circulo *c = (Circulo*) p->info;
        a = PI * c->r * c->r;
        break;
    default:
        break;
    }
    return a;
}

// função de cálculo para a maior área 

float max_area(Lista_het* l){
    float amax = 0.0; // maior área
    Lista_het* p;
    for(p=l;p!=NULL; p = p->prox){
        float a = area(p);
        if(a > amax) amax = a;
    }
    printf("%.2f", amax);
    return amax;

}







