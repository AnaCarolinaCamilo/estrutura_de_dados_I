// Objetivo: fazer atividade com leitura e escrita em um arquivo
// Funções importantes: fopen() fclose() fputc() ou putc() /fgetc our getc

#include <stdio.h>

int main()
{
    FILE *fp; // variável para armazenar o ponteiro de arquivo
    char ch; // variável para armazenar o texto já presente no texto
    if((fp = fopen("/home/ana/test.txt", "r"))== NULL){
        printf("Arquivo não pode ser aberto");
        return 0;
    }
    else{
        printf("Arquivo aberto com sucesso");
    }

    ch =  getc(fp); // faz a leitura do caracter
    printf("\n");
    while (ch != EOF) // EOF significa o final do arquivo 
    {
        putchar(ch); // imprime na tela 
        ch = getc(fp);
    }

    fclose(fp);
    


    return 0;
}
