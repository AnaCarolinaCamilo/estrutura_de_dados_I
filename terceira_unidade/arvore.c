# include <stdlib.h>
# include <stdio.h>
# include "arvore.h"

int main(int argc, char const *argv[])
{
    // sub arvore 2
    Arv* a2 = arv_cria(2,0,0);
    // sub arvore 3
    Arv* a3 = arv_cria(3,0,0);
    // sub arvore 1
    Arv* a1 = arv_cria(1,a2,a3);
    arv_mostra(a1);
    arv_libera(a1);
    return 0;
}
