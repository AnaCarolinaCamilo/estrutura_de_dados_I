#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    Lista* l_1 = lista_cria();

    lst_insere_final_c(&l_1, 'a');
    lst_insere_final_c(&l_1, 'b');
    lst_insere_final_c(&l_1, 'b');
    lst_insere_final_c(&l_1, 'a');

    

    lst_imprime_c(l_1);
    printf("\n");
    printf("Após a função:\n");
    lst_imprime_c(copia(l_1));
    printf("\n");
    
    





    return 0;
}