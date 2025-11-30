#include <stdio.h>
#include <stdlib.h>
#define LINHAS 2
#define COLUNAS 2

// Objetivo: fazer exercícios para entender funcionamento de vetor e matrizes de ponteiros

int main(int argc, char const *argv[])
{
    // matriz representada por um vetor de ponteiros 
    int i;
    // declaração de variável ponteiro para ponteiro
    float **mat;
    mat = (float**) malloc(LINHAS*sizeof(float*));
    for (int i = 0; i < LINHAS; i++)
    {
        mat[i] = (float*) malloc(COLUNAS*sizeof(float));
    }

    int j;

    // preenchendo a matriz
    for(i = 0; i < LINHAS; i++)
	{
		for(j = 0; j < COLUNAS; j++)
			mat[i][j] = i + j;
	}

    // mostrando os elementos da matriz
	for(i = 0; i < LINHAS; i++)
	{
		for(j = 0; j < COLUNAS; j++)
			printf("%f\t", mat[i][j]);
		printf("\n");
	}

	// liberando o espaço de memória

	// libera cada linha
	for(i = 0; i < LINHAS; i++)
		free(mat[i]);

	// libera o vetor de ponteiros
	free(mat);
    
    return 0;
}
