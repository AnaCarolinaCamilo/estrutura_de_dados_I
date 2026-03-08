#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

int main(int argc, char const *argv[])
{
    FilaVetor* f_1 = fila_vetor_cria();
    FilaVetor* f_2 = fila_vetor_cria();
    
    fila_insere_vetor(f_1,2.1);
    fila_insere_vetor(f_1,4.5);
    fila_insere_vetor(f_1,1.0);
    fila_insere_vetor(f_2,7.2);
    fila_insere_vetor(f_2,3.1);
    fila_insere_vetor(f_2,9.8);

    fila_imprime(f_1);
    
    fila_imprime(f_2);
    
    combina_fila(f_1,f_2);

    libera_fila_vetor(f_1);
    libera_fila_vetor(f_2);
    return 0;
}
