#include <stdio.h>
#include "fila.h"

int main(int argc, char const *argv[])
{
    FilaVetor* f = fila_vetor_cria();
    fila_insere_vetor(f,20.0);
    fila_insere_vetor(f,20.8);
    fila_insere_vetor(f,21.2);
    fila_insere_vetor(f,24.3);
    printf("Primeiro elemento: %f\n", fila_retira_vetor(f));
    printf("Segundo elemento: %f\n", fila_retira_vetor(f));
    printf("Configuração da lista:\n");
    fila_imprime(f);
    libera_fila_vetor(f);
    




    return 0;
}