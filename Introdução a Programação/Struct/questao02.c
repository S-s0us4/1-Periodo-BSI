/*Questão 02
Utilize a estrutura Aluno e cadastre 5 alunos.
Ao final, exiba:
• os dados de todos os alunos; 
• a média da turma; 
• o nome do aluno com a maior média.*/
#include <stdio.h>
#include <string.h>
#define NUMERO_ALUNOS 5

typedef struct {
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
}TAluno;

void limpaBuffer(){
    int ch
    do{
        ch=getchar();
    }while(ch!='\n');
}

int main(){
    TAluno va[NUMERO_ALUNOS];
    int i,tam;
    float media[NUMERO_ALUNOS];
    float mediaT = 0, maiorMedia;
    for(i=0;i<NUMERO_ALUNOS;i++){
        printf("\nForneça a matrícula do(a) aluno(a):\n");
        scanf("%d",&va[i].matricula);
        limpaBuffer();
        printf("\nForneça o nome do(a) Aluno(a):\n");
        fgets(va[i].nome,100,stdin);
        tam = strlen(va[i].nome);
        if(va[i].nome[tam-1]=='\n'){
            va[i].nome[tam-1]='\0';
        }else
            limpaBuffer();
            printf("\nForneça a primeira nota :\n");
            scanf("%f",&va[i].nota1);
            printf("\nForneça a segunda nota :\n");
            scanf("%f",&va[i].nota2);

            media[i]=(va[i].nota1+va[i].nota2)/2;
    }
    for(i=0;i<NUMERO_ALUNOS;i++){
        mediaT=media[0];
        maiorMedia=media[0];
        if(media[i]>maiorMedia){
            maiorMedia=media[i];
        }
        mediaT = mediaT + media[i];
    }
    mediaT = mediaT / NUMERO_ALUNOS;
    printf("\nMédia da Turma : %f\n",mediaT);
    printf("\nMaior média da turma : %f\n",maiorMedia);
    printf("\nAlunos que obtiveram a maior média :\n");
    for(i=0;i<NUMERO_ALUNOS;i++){
        if(media[i]==maiorMedia){
            printf("%s",va[i].nome);
        }
    }
    return 0;
}