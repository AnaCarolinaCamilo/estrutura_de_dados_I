#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    Lista* l_1 = lista_cria();
    Lista* l_2 = lista_cria();

    lst_insere_final_c(&l_1, 'a');
    lst_insere_final_c(&l_1, 'b');
    lst_insere_final_c(&l_1, 'b');
    lst_insere_final_c(&l_1, 'a');

    lst_insere_final_c(&l_2, 'a');
    lst_insere_final_c(&l_2, 'b');
    lst_insere_final_c(&l_2, 'a');
    lst_insere_final_c(&l_2, 'a');


    

    printf("\n");
    printf("Após a função:\n");
    if(lst_igual(l_1,l_2)) printf("São iguais!");
    else printf("São diferentes!");
    printf("\n");
    
    





    return 0;
}