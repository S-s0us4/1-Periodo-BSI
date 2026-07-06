/*Questão 07
Crie uma estrutura Aluno com:
• matrícula; 
• nome; 
• três notas; 
• média; 
• situação. 
Cadastre até 30 alunos.
O programa deve apresentar um menu:
1 - Cadastrar aluno
2 - Listar alunos
3 - Consultar aluno por matrícula
4 - Exibir aprovados
5 - Exibir reprovados
0 - Sair
A média deve ser calculada automaticamente. Considere aprovação com média maior ou igual a 60.*/
#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 30

typedef struct{
    int matricula;
    char nome[100];
    float nota1,nota2,nota3;
    float media;
    char situacao[100];
}TAluno;

void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n');
}

void cadastrarAluno(TAluno va[MAX_ALUNOS],int *quantidade){
    int tam;

    if(*quantidade == MAX_ALUNOS){
        printf("\nNúmero máximo de cadastros preenchidos\n");
        return;
    }else{
        printf("\nForneça a matrícula:\n");
        scanf("%d",&va[*quantidade].matricula);
        limpaBuffer();
        printf("\nForneça o nome :\n");
        fgets(va[*quantidade].nome,100,stdin);
        tam = strlen(va[*quantidade].nome);
        if(va[*quantidade].nome[tam-1]=='\n'){
            va[*quantidade].nome[tam-1]='\0';
        }else{
            limpaBuffer();
        }
        printf("\nForneça a primeira nota :\n");
        scanf("%f",&va[*quantidade].nota1);
        printf("\nForneça a segunda nota :\n");
        scanf("%f",&va[*quantidade].nota1);
        printf("\nForneça a terceira nota :\n");
        scanf("%f",&va[*quantidade].nota3);

        va[*quantidade].media = (va[*quantidade].nota1+va[*quantidade].nota2+va[*quantidade].nota3)/3;

        if(va[*quantidade].media >= 60){
            strcpy(va[*quantidade].situacao,"Aprovado");
        }else
            strcpy(va[*quantidade].situacao,"Reprovado");
            (*quantidade)++;
    }
}
void listarAlunos(TAluno va[MAX_ALUNOS],int quantidade){
    int i;
    for(i=0;i<quantidade;i++){
        printf("\nMatrícula:%d\n",va[i].matricula);
        printf("\nNome:%s\n",va[i].nome);
        printf("\nNota 1:%2.f\n",va[i].nota1);
        printf("\nNota 2:%2.f\n",va[i].nota2);
        printf("\nNota 3:%2.f\n",va[i].nota2);
        printf("\nMédia :%2.f\n",va[i].media);
        printf("\nSituação :%s\n"va[i].situacao);
    }
}
void consultarAluno(TAluno va[MAX_ALUNOS],int quantidade){
    int mat,i,achou=0;
    printf("\nForneça a matrícula do aluno desejado :\n");
    scanf("%d",&mat);
    for(i=0;i<quantidade;i++){
        if(mat==va[i].matricula){
            printf("\nMatrícula encontrada !\n");
            printf("\nNome:%s\n",va[i].nome);
            printf("\nNota 1:%2.f\n",va[i].nota1);
            printf("\nNota 2:%2.f\n",va[i].nota2);
            printf("\nNota 3:%2.f\n",va[i].nota2);
            printf("\nMédia :%2.f\n",va[i].media);
            printf("\nSituação :%s\n"va[i].situacao);
            achou=1;
            break;
        }
    }
    if(achou==0){
        printf("\nMatrícula não encontrada\n");
        return;
    } 
}
void aprovados(TAluno va[MAX_ALUNOS],int quantidade){
    int i,achou=0;
    for(i=0;i<quantidade;i++){
        if(va[i].media >=60){
            printf("\nAluno(s) aprovado(s):\n");
            printf("\nMatrícula:%d\n",va[i].matricula);
            printf("\nNome:%s\n",va[i].nome);
            printf("\nMédia :%2.f\n",va[i].media);
            printf("\nSituação :%s\n"va[i].situacao);
            achou=1;
            break;
        }
    }
    if(achou==0){
        printf("\nNenhum aluno aprovado\n");
        return;
    }
}
void reprovados(TAluno va[MAX_ALUNOS],int quantidade){
    int i,achou=0;
    for(i=0;i<quantidade;i++){
        if(va[i].media <60){
            printf("\nAluno(s) reprovado(s):\n");
            printf("\nMatrícula:%d\n",va[i].matricula);
            printf("\nNome:%s\n",va[i].nome);
            printf("\nMédia :%2.f\n",va[i].media);
            printf("\nSituação :%s\n"va[i].situacao);
            achou=1;
            break;
        }
    }
    if(achou==0){
        printf("\nNenhum aluno reprovado\n");
        return;
    }
}
int main(){
    TAluno va[MAX_ALUNOS];
    int quantidade=0,opcao;
    do{
    printf("\n1 - Cadastrar aluno");
    printf("\n2 - Listar alunos");
    printf("\n3 - Consultar por matrícula");
    printf("\n4 - Exibir aprovados");
    printf("\n5 - Exibir reprovados");
    printf("\n0 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    limpaBuffer();
    switch(opcao){
        case 1 :
            cadastrarAluno(va,&quantidade);
            break;
        case 2:
            listarAlunos(va,quantidade);
            break;
        case 3:
            consultarAluno(va,quantidade);
            break;
        case 4:
            aprovados(va,quantidade);
            break;
        case 5:
            reprovados(va,quantidade);
            break;
    }
    }while(opcao != 0);
   
    return 0;
}