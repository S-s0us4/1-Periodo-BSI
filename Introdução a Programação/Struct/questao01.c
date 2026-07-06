/*Questão 01
Crie uma estrutura Aluno com os campos:
• matrícula; 
• nome; 
• nota1; 
• nota2. 
Leia os dados de um aluno e exiba:
• nome; 
• matrícula; 
• média das duas notas; 
• situação: Aprovado se a média for maior ou igual a 60 e Reprovado caso contrário.*/

#include <stdio.h>
#include <string.h>
typedef struct {
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
}TAluno;
void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n');
}
int main(){
    TAluno al;
    float media;
    int tam;

    printf("\nForneça a matrícula do aluno :\n");
    scanf("%d",&al.matricula);
    limpaBuffer();
    printf("\nForneça o nome do aluno :\n");
    fgets(al.nome,100,stdin);
    tam = strlen(al.nome);
    if(al.nome[tam-1]=='\n'){
        al.nome[tam-1]='\0';
    }else{
        limpaBuffer();
    }
    printf("\nForneça a primeira nota :\n");
    scanf("%f",&al.nota1);

    printf("\nForneça a segunda nota :\n");
    scanf("%f",&al.nota2);
    media = (al.nota1 + al.nota2)/2;

    printf("\nDados do Aluno :\n");
    printf("\nMatrícula : %d\n",al.matricula);
    printf("\nNome : %s\n",al.nome);
    printf("\nSituação final :\n");
    if(media>=60){
        printf("\nAPROVADO\n");
    }else
        printf("\nREPROVADO\n");

    return 0;
}