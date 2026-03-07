#include <stdio.h>
#include <stdlib.h>
#include "pilha_vetor.h"
#include <string.h>
#include <stdbool.h>

bool par_parenteses (char c1, char c2){
    if (c1 == '(' && c2 == ')')
        return 1;
    else if (c1 == '{' && c2 == '}')
        return 1;
    else if (c1 == '[' && c2 == ']')
        return 1;
    else
        return 0;
}

int balanceamento_de_parenteses(char *str){
    Pilha p;
    int tamanho = strlen(str);
    int i;
    pilha_cria_vetor(&p);
    for(i = 0; i < tamanho; i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            pilha_push_vetor(&p, str[i]); // empilhar 
        }
        else if(str[i] == '}'|| str[i] == ']' || str[i] == ')') {
            if(pilha_vazia_vetor(&p)) return 0;
            else if(!par_parenteses(pilha_pop_vetor(&p), str[i])) return 0;
            }
    }
    return pilha_vazia_vetor(&p);
    pilha_libera(&p);
} 



int main()
{
    char expressao[] = "{}( )";
    printf("%d", balanceamento_de_parenteses(expressao));
    if(balanceamento_de_parenteses(expressao)){
        printf("A expressão eh balanceada!");
    }
    else{
        printf("A expressão nao eh balanceada!\n");
    }
    return 0;
}
