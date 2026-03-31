# include <stdlib.h>
# include <stdio.h>
# include "arvore_ordenada.h"

int main(int argc, char const *argv[])
{
    Arv* a = arv_cria(15,0,0);
    insere_ordenado(a,22);
    insere_ordenado(a,12);
    insere_ordenado(a,14);
    insere_ordenado(a,17);
    insere_ordenado(a,10);
    insere_ordenado(a,24);
    insere_ordenado(a,19);
    insere_ordenado(a,21);
    insere_ordenado(a,11);
    insere_ordenado(a,18);
    insere_ordenado(a,16);

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
