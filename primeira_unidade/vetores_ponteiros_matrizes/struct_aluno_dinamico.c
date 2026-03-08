#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno
    {
        int matricula;
        char nome[40];
        float nota1;
        float nota2;
        float nota3;
        float media;
    };
    typedef struct aluno Aluno;

int main(int argc, char const *argv[])
{   
    

    float calcular_media(int n1, int n2, int n3);

    // void nomes_ordem_alfabetica(Aluno *alunos, int n);
    
    int num_alunos;
    Aluno *alunos;
    printf("Professsor(a) quantos alunos existem em sua turma?");
    scanf("%d",&num_alunos);

    alunos = (Aluno*)malloc(num_alunos*sizeof(Aluno));
    if (alunos)
    {    
    
    // adicionar os dados dos alunos
    for (int i = 0; i < num_alunos; i++)
    {
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[i].nome);
       
        printf("\nDigite a matrícula do aluno: \n");
        scanf("%d", &alunos[i].matricula);

        printf("Digite a primeira nota do aluno: \n");
        scanf("%f", &alunos[i].nota1);
        
        printf("Digite a segunda nota do aluno: \n");
        scanf("%f",&alunos[i].nota2);
        
        printf("Digite a terceira nota do aluno: \n");
        scanf("%f", &alunos[i].nota3);

        alunos[i].media = calcular_media(alunos[i].nota1, alunos[i].nota2, alunos[i].nota3);



    }
    // mostrando os dados recolhidos 

    for (int j = 0; j < num_alunos; j++)
    {
        printf("Nome do aluno: \n");
        // nomes_ordem_alfabetica(alunos[j].nome, num_alunos);
        printf("%s\n", alunos[j].nome);
        printf("Matrícula dos aluno: \n");
        printf("%d\n", alunos[j].matricula);
        printf("Nota 1 dos aluno: \n");
        printf("%.2f\n", alunos[j].nota1);
        printf("Nota 2 dos aluno: \n");
        printf("%.2f\n", alunos[j].nota2);
        printf("Nota 3 dos aluno: \n");
        printf("%.2f\n", alunos[j].nota3);
        printf("Média do aluno: \n");
        printf("%.2f\n", alunos[j].media);


    }
    }
    else printf("Erro ao alocar memória");


    
    
    




    
    
    return 0;
}

    float calcular_media(int n1, int n2, int n3){
        float media;
        media = (n1+n2+n3)/3;
        return media;
    }
    // void nomes_ordem_alfabetica(Aluno *alunos, int n){
    //     char v[] = alunos->nome;
    //     int comp;
    //     char aux[n];
    //     for (int i = 0; i < n; i++)
    //     {
    //          for (int j = 0; j < n; j++)
    //          {
    //             comp = strcmp(v[i], v[j]);
    //             if(comp > 0){
    //                 strcpy(aux,v[i]);
    //                 strcpy(v[i], v[j]);
    //                 strcpy(v[j], aux);
    //             }
    //          }
             
    //     }
        
    // }

