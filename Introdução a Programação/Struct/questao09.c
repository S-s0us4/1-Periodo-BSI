/*Questão 09
Crie as estruturas:
struct Data {
    int dia,es,ano;
};
struct Livro {
    int codigo;
    char titulo[100];
    char autor[80];
    int quantidade;
};
struct Emprestimo {
    int codigoLivro;
    char nomeAluno[100];
    int matriculaAluno;
    struct Data dataEmprestimo;
};
O sistema deve permitir:
• cadastrar livros; 
• consultar livro por código; 
• realizar empréstimo apenas se houver exemplar disponível; 
• registrar os dados do empréstimo; 
• listar os empréstimos realizados.*/

#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct {
    int dia,mes,ano;
}TData;

typedef struct {
    int codigo;
    char titulo[100];
    char autor[80];
    int quantidade;
}TLivro;

typedef struct {
    int codigoLivro;
    char nomeAluno[100];
    int matriculaAluno;
}TEmprestimo;

void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n');
}
void cadastraL(TData vD[MAX],TLivro vL[MAX],int *quantidade){
    int tam;
    if(*quantidade == MAX){
        printf("\nNúmero de Cadastros encerrado\n");
        return 0;
    }else{
        printf("\nForneça o código do livro :\n");
        scanf("%d",&vL.codigo);
        limpaBuffer();
        printf("\nForneça o título do livro :\n");
        fgets(vL.titulo,100,stdin);
        tam = strlen(vL.titulo);
        if(vL.titulo[tam-1]=='\n'){
            vL.titulo[tam-1]='\0';
        }else{
            limpaBuffer();
        }printf("\nForneça o autor do livro :\n");
        fgets(vL.autor,80,stdin);
        tam = strlen(vL.autor);
        if(vL.autor[tam-1]=='\n'){
            vL.autor[tam-1]='\0';
        }else{
            limpaBuffer();
        }
        printf("\nForneça a quantidade de estoque do livro :\n");
        scanf("%d",&vL.quantidade);
        printf("\nForneça o dia de cadastro do livro :\n");
        scanf("%d",&vD.dia);
        printf("\nForneça o mês de cadastro do livro :\n");
        scanf("%d",&vD.mes);
        printf("\nForneça o ano de cadastro do livro :\n");
        scanf("%d",&vD.ano);
        limpaBuffer();
        (*quantidade)++;
        return 0;
    }
}
void consultarL(TLivro vL[MAX],int quantidade){
    int i,cod,achou=0;
    printf("\nForneça o código do livro que deseja encontrar:\n");
    scanf("%d",&cod);

    for(i=0;i<quantidade;i++){
        if(vL.codigo[i]==cod){
            printf("\nLivro encontrado !!\n");
            printf("\nTítulo do livro:\n",vL.titulo[i]);
            printf("\nAutor do Livro:\n",vL.autor[i]);
            printf("\nQuantidade em estoque do Livro:\n",vL.quantidade[i]);
            achou=1;
        }
    }
    if(achou==0){
        printf("\nLivro não encontrado !!\n");
        return 0;
    }
}

void realizarE(TData vD[MAX],TLivro vL[MAX],TEmprestimo vE[MAX],int *quantidade){
    int cod,achou=0,i,qtd;

    printf("\nForneça o código do livro :\n");
    scanf("%d",&cod);
    for(i=0;i<quantidade;i++){
        if(vL.codigo[i]==cod){
            printf("\nLivro encontrado !!\n");
            printf("\nTítulo do livro:\n",vL.titulo[i]);
            printf("\nQuantidade em estoque do Livro:\n",vL.quantidade[i]);
            printf("\nForneça a quantidade que deseja pegar:\n");
            scanf("%d",&qtd);
            if(qtd<=vL.quantidade[i]){
                printf("\nEmpréstimo realizado com sucesso !!\n");
                vL.quantidade[i]-=qtd;
                return 0;
            }else{
                printf("\nQuantidade de livros indisponíveis !!\n");
                return 0;
            }
            achou=1;
        }
    }
    if(achou==0){
        printf("\nLivro não encontrado !!\n");
        return 0;
    }
    
}


int main(){
    TData vD[MAX];
    TLivro vL[MAX];
    TEmprestimo vE[MAX];
    int quantidade,opcao;
    do{
        printf("1-Cadastrar Livros\n");
        printf("2-Consultar Livro por Código\n");
        printf("3-Realizar Empréstimo\n");
        printf("4-Registrar dados do Empréstimo\n");
        printf("5-Listar Empréstimos\n");
        printf("0-Sair\n");
        switch(opcao){
            case 1:
                cadastrarL(vD,vL,&quantidade);
                break;
            case 2:
                consultarL(vL,quantidade);
                break;
            case 3:
                realizarE(vD,vL,vE,&quantidade);
                break;
            case 4:
                registrarD(vE,vD,vL,quantidade);
                break;
            case 5:
                listarE(vE,vD,vL,quantidade);
                break;
        }
    }while(opcao!=0);
    return 0;
}