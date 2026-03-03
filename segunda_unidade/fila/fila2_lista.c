#include <stdio.h>
#include "fila2.h"

void imprimirFila(Fila2* dq) {
    if (dq->ini == NULL) {
        printf("Fila vazia\n");
        return;
    }

    No* temp = dq->ini;
    printf("Fila: ");
    while (temp != NULL) {
        printf("%f\n ", temp->info);
        temp = temp->prox;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Fila2* f = fila2_cria();
    fila2_insere_ini(f,20.5);
    fila2_insere_fim(f,24);
    printf("Primeiro elemento: %f\n", fila2_retira_ini(f));
    printf("Segundo elemento: %f\n", fila2_retira_fim(f)); // algum problema aqui
    fila2_insere_ini(f,23.8);
    fila2_insere_fim(f,21.9);
    printf("Configuração da lista:\n");
    imprimirFila(f);
    libera_fila2(f);
    




    return 0;
}