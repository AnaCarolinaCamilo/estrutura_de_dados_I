// Objetivo: fazer atividade com leitura e escrita em um arquivo
// Funções importantes: fopen() fclose() fputc() ou putc() /fgetc our getc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char str[80];
    FILE *fp;
    if((fp = fopen("TESTE", "w+"))== NULL){    // o modo w+ significa a CRIAÇÃO de um arquivo para escrita e leitura
        printf("Arquivo não pode ser aberto");
        return 0;
    }
    else{
        printf("Arquivo aberto com sucesso");
    }

    do {
        printf("Digite uma string (CR para sair): \n");
        fgets(str, 80, stdin);
        strcat(str, "\n"); // acrescenta uma nova linha
        fputs(str, fp);
    } while (*str!='\n');
    
    // leitura e mostrar o arquivo na tela
    rewind(fp); // a função reinicia o indicador de posição do arquivo para o começo do arquivo
    while (!feof(fp))
    {
        fgets(str, 79, fp);
        printf(str);
    }
    
    fclose(fp);

    

    return 0;
}
