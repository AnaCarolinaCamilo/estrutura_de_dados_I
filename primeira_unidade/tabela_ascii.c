// Objetivo gerar a tabela ASCII

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    for ( i = 0; i < 255; i++)
    {
        printf("Valor da tabela ASCII %c: %d \n",i,i);
    }
    

    return 0;
    
}