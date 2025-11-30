// Objetivo: fazer atividade com leitura e escrita em um arquivo
// Funções importantes: fopen() fclose() fputc() ou putc() /fgetc our getc

#include <stdio.h>

int main()
{
    FILE *in, *out; // variável para armazenar os ponteiros de arquivo
    char ch; // variável para armazenar o texto já presente no texto
    if((in=fopen("/home/ana/test.txt", "rb"))== NULL){
        printf("Arquivo in não pode ser aberto");
        return 0;
    }
    else{
        printf("Arquivo in aberto com sucesso");
    }
    if((out=fopen("teste_escrita", "wb"))== NULL){
        printf("Arquivo out não pode ser aberto");
        return 0;
    }
    else{
        printf("Arquivo out aberto com sucesso");
    }

    printf("\n");
    while (!feof(in))// EOF significa o final do arquivo 
    {
        ch = getc(in);
        if(!feof(in)) putc(ch, out);
    }

    fclose(in);
    fclose(out);

    


    return 0;
}
