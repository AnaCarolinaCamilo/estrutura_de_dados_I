#include <stdlib.h>
#include <stdio.h>
#include "pilha_vetor_f.h"

int main(int argc, char const *argv[])
{
    Pilha* p;
    Pilha* p1;
    Pilha* p2;
    p = pilha_cria_vetor(p);
    p1 = pilha_cria_vetor(p1);
    p2 = pilha_cria_vetor(p2);

    pilha_push_vetor(p, 2.5);
    pilha_push_vetor(p,3.0);
    pilha_push_vetor(p,3.5);

    pilha_push_vetor(p1, 1.0);
    pilha_push_vetor(p1, 4.5);
    pilha_push_vetor(p1, 2.1);

    pilha_push_vetor(p2, 9.8);
    pilha_push_vetor(p2, 3.1);
    pilha_push_vetor(p2, 7.2);



    
    printf("%.2f\n",pilha_pop_vetor(p));
    printf("%.2f\n",checar_topo(p));
    concat_pilha(p1,p2);
    // pilha_imprime(p1);
    Pilha* copia = copia_pilha(p1);
    pilha_imprime(copia);
    pilha_imprime(p1);

    return 0;

}
