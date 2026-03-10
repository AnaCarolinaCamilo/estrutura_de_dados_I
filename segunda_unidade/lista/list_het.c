#include <stdlib.h>
#include <stdio.h>
#include "list_het.h"

int main(int argc, char const *argv[])
{
    Lista_het* p;
    Lista_het* t;
    Lista_het* r;
    Lista_het* c;

    t = cria_tri(3,3);
    r = cria_ret(10,5);
    c = cria_cir(3);

    lst_insere_começo(&p,c);
    lst_insere_começo(&p,t);
    lst_insere_começo(&p,r);


    max_area(p);
    
    return 0;
}
