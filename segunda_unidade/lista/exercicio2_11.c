#include <stdlib.h>
#include <stdio.h>
#include "lista_duplamente_circular.h"

int main(int argc, char const *argv[])
{
    LISTA l_1;
    cria_lista(&l_1);
    No* removido;

    inserir(l_1, 4,1);
    inserir(l_1, 1,2);
    inserir(l_1, 7,3);
    inserir(l_1, 9,4);


    

    l2circ_imprime_rev(l_1);
    ret(l_1,1);
    printf("\n");
    l2circ_imprime_rev(l_1);
    // printf("Após a função:\n");
    // lst_imprime(inverte(l_1));
    // printf("\n");
    
    





    return 0;
}