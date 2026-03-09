#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    Lista* l_1 = lista_cria();
    Lista* l_2 = lista_cria();

    lst_insere_começo(&l_1, 2);
    lst_insere_final(&l_1, 4);
    lst_insere_final(&l_1, 1);
    lst_insere_começo(&l_2, 7);
    lst_insere_final(&l_2, 3);
    lst_insere_final(&l_2, 9);


    

    lst_imprime(l_1);
    printf("\n");
    lst_imprime(l_2);
    printf("\n");
    printf("Após a função:\n");
    lst_imprime(merge(l_1,l_2));
    printf("\n");
    
    





    return 0;
}