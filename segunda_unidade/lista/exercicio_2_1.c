#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    Lista* l = lista_cria();

    lst_insere_começo(&l, 6);
    lst_insere_começo(&l, 7);
    lst_insere_final(&l, 8);
    lst_imprime(l);
    printf("%d\n", tamanho_lista(l));



    return 0;
}
