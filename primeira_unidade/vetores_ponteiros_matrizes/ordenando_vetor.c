// Objetivo: mostrar de forma ordenada crescente, a partir de outra função, um vetor declarado em main(), sem que o vetor original seja modificado.
// técnicas de ordenamento à serem utilizadas: bubble sort, insertion sort, selection sort.
// ideia: Fazer a cópia do Vetor original e realizar o sorting a partir dela, assim não afetando o original 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenamento_bubble(int *p){
    for (int i = 0; i < 10; i++)
    {
        int swaps = 0; // detectando se é necessário fazer a troca
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            { // quando um número é maior que o outro
                int temp;
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                swaps = 1; // estabelece que as trocas devem continuar acontecendo
            }
        }
        if (!swaps) // quando as trocas terminarem a variável swaps voltará a ser 0
            break; 
    }
}

void ordenamento_insertion(int *p){
    int key, j;
   for(int i = 1; i<10; i++) {
      key = p[i]; // captura o valor
      j = i;
      while(j > 0 && p[j-1]>key) {
         p[j] = p[j-1];
         j--;
      }
      p[j] = key; // coloca no lugar certo 
   }
    
}
void ordenamento_selection(int *p){
    int i, j, imin;
    for (i = 0; i < 10 - 1; i++)
    {
        imin = i; // pega o index do menor número
        for (j = i + 1; j < 10; j++)
            if (p[j] < p[imin])
                imin = j;

        // coloca na posição correta
        int temp;
        temp = p[i];
        p[i] = p[imin];
        p[imin] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int v[10];
    int copia_v[10]; 

    // leitura dos valores
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
    }
    // realizando a cópia dos valores originais
    memcpy(copia_v,v, 10 * sizeof(int));
    
   
    printf("Vetor antes do ordenamento: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
   
    ordenamento_bubble(copia_v);
    printf("Vetor depois do bubble sort: ");
        for (int i = 0; i < 10; i++){
            printf("%d ", copia_v[i]);
        }
        printf("\n");
    
    ordenamento_insertion(copia_v);
    printf("Vetor depois do insertion sort: ");
        for (int i = 0; i < 10; i++){
            printf("%d ", copia_v[i]);
        }
        printf("\n");
    
    ordenamento_selection(copia_v);
        printf("Vetor depois da selection sort");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", copia_v[i]);
        }
        printf("\n");

        printf("Vetor antes do ordenamento: ");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", v[i]);
        }
    return 0;
}



