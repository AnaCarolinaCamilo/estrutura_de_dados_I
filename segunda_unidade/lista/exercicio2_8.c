#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    Lista* l_1 = lista_cria();

    lst_insere_começo(&l_1, 2);
    lst_insere_final(&l_1, 4);
    lst_insere_final(&l_1, 1);
    lst_insere_final(&l_1, 7);
    lst_insere_final(&l_1, 9);


    

    lst_imprime(l_1);
    printf("\n");
    printf("Após a função:\n");
    lst_imprime(inverte(l_1));
    printf("\n");
    
    





    return 0;
}