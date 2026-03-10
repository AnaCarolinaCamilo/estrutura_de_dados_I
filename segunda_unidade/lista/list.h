// biblioteca com funções relacionadas a lista

# include <stdlib.h>
# include <stdio.h>

struct Lista
{
    int info;
    struct Lista* prox;
    
};
typedef struct Lista Lista;



# ifndef LIST_H
# define LIST_H

// cria uma lista vazia
Lista* lista_cria(void){
    return NULL;
}

// inserção no começo da lista (retorna a atualizada)

void lst_insere_começo(Lista **lista, int i)
{
    Lista *novo = (Lista*)malloc(sizeof(Lista)); 
    if( novo == NULL){
        printf("falha na alocação de memória");
    }
    else{
        novo->info = i;
        novo->prox = *lista;
        *lista = novo;
    }

}

// inserção no fim da lista 

void lst_insere_final(Lista **lista, int i){
    Lista *aux,*novo = (Lista*)malloc(sizeof(Lista));
    if(novo){
        novo->info = i;
        novo ->prox = NULL;

        // verificando se a lista está vazia
        if (*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->prox)
            {
                aux = aux -> prox;
            }
            aux ->prox = novo;
            

        }
        
    }
    else{
        printf("erro ao alocar memória");
    }
}

// inserção no meio da lista

void lst_insere_meio(Lista **lista, int i, int ant){
    Lista *novo, *aux = (Lista*)malloc(sizeof(Lista));
    if(novo){
        novo->info = i;
        // checando se a lista está vazia
        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->info != ant && aux->prox)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;

        }

    }
}

// função de imprimir a lista
void lst_imprime(Lista *lista){
    Lista* p;
    for(p=lista; p!=NULL; p=p->prox){
        printf("info= %d\n", p->info);
    }
}
// função que retorna o tamanho da lista

int tamanho_lista(Lista* l){
    int tam = 0;
    Lista* aux;
    for(aux=l; aux!=NULL; aux=aux->prox)
    {
        tam++;
    }  
    return tam;    
}
// função de busca: busca um elemento na lista

Lista* lst_busca(Lista* lista, int i){
    Lista *p;
    for(p=lista; p!=NULL; p=p->prox){
        if(p->info == i){
            return p;
        }
    }
    return NULL;
}

int lst_retira(Lista **lista, int i){
    Lista* aux = NULL;
    Lista* remover = NULL;

    if(*lista){
        if((*lista)->info == i){
            remover = *lista;
            *lista = remover->prox;
        }
        else{
            aux = *lista;
            while (aux->prox && aux->prox->info != i)
            {
                aux = aux->prox;
            }
            if(aux->prox){
                remover = aux->prox;
                aux->prox = remover->prox;
            }
            
        }
    }
    return remover->info;
}


// função para liberar lista

void lst_libera(Lista *lista){

    Lista *p = lista;
    while (p != NULL)
    {
        Lista *t = p->prox; // guarda referência pro próximo elemento
        free(p); // libera a memória apontada por p
        p=t; // faz o p apontar pro próximo
    }
}

int lst_igual(Lista *l1, Lista *l2){
    Lista *p1; // ponteiro para percorrer l1
    Lista *p2; // ponteiro para percorrer l2

    for (p1=l1, p2=l2; p1!=NULL&&p2!=NULL; p1=p1->prox, p2=p2->prox)
    {
        if(p1->info != p2->info){
            return 0;
        }
    }
    return p1==p2; 
}
int maiores(Lista* l, int n){
    int cont = 0;
    Lista* aux;
    for(aux=l; aux!= NULL; aux=aux->prox)
    {
        if(aux->info > n){
            cont++;
        }
    }  
    return cont; 
}

Lista* ultimo(Lista* l){
    Lista *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->prox == NULL){
            printf("%d\n", p->info);
            return p;
        }
    }
    return NULL;
    return 0;

}

int ultimo_n(Lista* l){
    Lista *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->prox == NULL){
            return p->info;
        }
    }
    return 0;

}
int lst_vazia(Lista* l){
    return(l == NULL);
}

int encontrar_inicio (Lista* l){
    return l->info;
}

Lista* concatena(Lista* l1, Lista* l2){
    while ((!lst_vazia(l2)))
    {
        lst_insere_final(&l1,(lst_retira(&l2,(encontrar_inicio(l2)))));
    }

    return l1;
    
}

Lista* retira_n (Lista* l, int n){
    Lista *p;
    for(p=l; p!=NULL; p=p->prox){
        lst_retira(&l, n);
    }
    return l;
}

Lista* separa(Lista* l, int n){
    Lista* p;
    Lista* nova = lista_cria();
    for(p=l; p!=NULL; p=p->prox){
        if(p->info == n){
            lst_insere_final(&nova, (lst_retira(&l,p->prox->info)));
        }
    }
    return nova;
}

Lista* merge (Lista* l1, Lista* l2){
    Lista* nova = lista_cria();
    while((!lst_vazia(l1) && !lst_vazia(l2))){
        lst_insere_final(&nova,(lst_retira(&l1,(encontrar_inicio(l1)))));
        lst_insere_final(&nova,(lst_retira(&l2,(encontrar_inicio(l2)))));
    }
    return nova;
    
}


Lista* inverte(Lista* l1){
    Lista* nova = lista_cria();
    while ((!lst_vazia(l1)))
    {
        lst_insere_final(&nova,(lst_retira(&l1,(ultimo_n(l1)))));
    }

    return nova;
    
}

void lst_insere_final_c(Lista **lista, char c){
    Lista *aux,*novo = (Lista*)malloc(sizeof(Lista));
    if(novo){
        novo->info = c;
        novo ->prox = NULL;

        // verificando se a lista está vazia
        if (*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->prox)
            {
                aux = aux -> prox;
            }
            aux ->prox = novo;
            

        }
        
    }
    else{
        printf("erro ao alocar memória");
    }
}

void lst_imprime_c(Lista *lista){
    Lista* p;
    for(p=lista; p!=NULL; p=p->prox){
        printf("info= %c\n", p->info);
    }
}



Lista* copia(Lista* l){
    Lista* p;
    Lista* copia = lista_cria();
    for(p=l; p!=NULL; p=p->prox){
        lst_insere_final_c(&copia,p->info);
    }
    return copia;
}
// função de imprimir a lista recursivamente
void lst_imprime_rec(Lista *lista){
    if(!lst_vazia(lista)){
        // imprime o primeiro elemento
        printf("%d\n", lista->info);
        // imprime sublista
        lst_imprime_rec(lista->prox);

    }
}



#endif