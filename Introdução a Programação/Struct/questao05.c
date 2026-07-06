/*Questão 05
Utilize a estrutura Aluno do exercício1 e implemente as funções:
void lerAluno(struct Aluno *a);
void mostrarAluno(struct Aluno a);
float calcularMedia(struct Aluno a);
No programa principal, leia um aluno, calcule sua média e mostre seus dados.
*/
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

void lerAluno(TAluno *a){
    int tam;
    printf("\nForneça a matrícula do aluno :\n");
    scanf("%d",&a->matricula);
    limpaBuffer();
    printf("\nForneça o nome do aluno:\n");
    fgets(a->nome,100,stdin);
    tam = strlen(a->nome);
    if(a->nome[tam-1]=='\n'){
        a->nome[tam-1]='\0';
    }else{
        limpaBuffer();
    }
    printf("\nForneça a primeira nota :\n");
    scanf("%f",&a->nota1);
    printf("\nForneça a segunda nota :\n");
    scanf("%f",&a->nota2);
}
void mostrarAluno(TAluno a){
    printf("\nDados do aluno :\n");
    printf("\nMatricula do aluno : %d\n",a.matricula);
    printf("\nNome do aluno: %s\n",a.nome);
}
float calcularMedia(TAluno a){
    return (a.nota1+a.nota2)/2;
}
int main(){
    TAluno a;
    lerAluno(&a);
    mostrarAluno(a);
    printf("\nMédia do aluno:%2.f\n"calcularMedia(a));
}