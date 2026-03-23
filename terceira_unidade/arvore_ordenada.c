# include <stdlib.h>
# include <stdio.h>
# include "arvore_ordenada.h"

int main(int argc, char const *argv[])
{
    Arv* a = arv_cria(8,0,0);
    insere_ordenado(a,4);
    insere_ordenado(a,12);
    insere_ordenado(a,2);
    insere_ordenado(a,14);
    insere_ordenado(a,5);
    insere_ordenado(a,15);

    arv_mostra(a);
    printf("\n");
    pre_ordem(a);
    printf("\n");
    em_ordem(a);
    printf("\n");
    pos_ordem(a);
    printf("\n");
    arv_libera(a);
    return 0;
}
