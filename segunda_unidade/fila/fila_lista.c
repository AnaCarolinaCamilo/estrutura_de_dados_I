#include <stdio.h>
#include "fila.h"

int main(int argc, char const *argv[])
{
    FilaLista* f = fila_lista_cria();
    fila_lista_insere(f,20.5);
    fila_lista_insere(f,23.8);
    fila_lista_insere(f,21.9);
    fila_lista_insere(f,24);
    printf("Primeiro elemento: %f\n", fila_lista_retira(f));
    printf("Segundo elemento: %f\n", fila_lista_retira(f));
    printf("Configuração da lista:\n");
    fila_imprime_lista_rec(f->ini);
    libera_fila_lista(f);
    




    return 0;
}