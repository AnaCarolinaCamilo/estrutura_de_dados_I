# include <stdlib.h>
# include <stdio.h>
# include "arvore_AVL.h"

int main(int argc, char const *argv[])
{
    // sub arvore 2
    Arv* a2 = arv_cria(2,0,0);
    // sub arvore 3
    Arv* a3 = arv_cria(3,0,0);
    // sub arvore 1
    Arv* a1 = arv_cria(1,a2,a3);
    // insere_n_recursivo(&a1, 8);
    // insere_n_recursivo(&a1,4);
    
    inserir_balanceado(a1,8);
    inserir_balanceado(a1,4);
    arv_mostra(a1);
    printf("\n%d\n",arv_altura(a1));
    printf("%d\n",qtd_nos(a1));
    arv_libera(a1);
    return 0;
}
