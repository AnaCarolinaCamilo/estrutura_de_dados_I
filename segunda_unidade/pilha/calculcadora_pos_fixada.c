#include <stdlib.h>
#include <stdio.h>
#include "calculadora_pos_fixada.h"

int main(int argc, char const *argv[]){
    char c;
    int v;
    int op = 0;
    int num = 0;
    Calc* calc;
    calc = calc_cria("%d\n");
    printf("%c\n",mostrar_topo(calc->p));


    printf("Digite a expressão um elemento por vez e para encerrar digite 'q\n");

    do
    {
        scanf(" %c",&c); // lê o próximo caracter não branco
        if(c == '+' || c == '-'|| c == '*' || c == '/'){  //reconhecendo operandos 
            op++;
            calc_operador(calc,c);
            printf("%c\n",mostrar_topo(calc->p));
        }
        else{
            ungetc(c,stdin);
            if(scanf("%d",&v)==1){
                calc_numero(calc,v);
                num++;
            }
                printf("%c\n",mostrar_topo(calc->p));
        }
        if(op >= num){
        printf("expressao invalida!\n");
        exit(1);
    }
    } while (c!='q');
    // if(op >= num){
    //     printf("expressao invalida!\n");
    // }
    verifica_expressao(calc);
    calc_libera(calc);

    return 0;
}


    

