/*Questão 06
Crie uma estrutura Produto com código, nome, preço e estoque.
Implemente uma função:
int realizarVenda(struct Produto *p, int quantidade);
A função deve:
• verificar se há estoque suficiente; 
• diminuir a quantidade em estoque, caso a venda seja possível; 
• retornar 1 se a venda foi realizada; 
• retornar 0 caso contrário.*/
#include <stdio.h>
#include <string.h>
typedef struct{
    int codigo;
    char nome[100];
    float preco;
    int estoque;
}TProduto;

void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n');
}
int realizarVenda(TProduto *p,int quantidade){
    if(p->estoque >= quantidade){
        p->estoque -= quantidade;
        return 1;
    }else
        return 0;
}
int main(){
    TProduto p;
    int tam,quantidade;
    printf("\nForneça o código do produto :\n");
    scanf("%d",&p.codigo);
    limpaBuffer();
    printf("\nForneça o nome do produto :\n");
    fgets(p.nome,100,stdin);
    tam = strlen (p.nome);
    if(p.nome[tam-1]=='\n'){
        p.nome[tam-1]='\0';
    }else{
        limpaBuffer();
    }
    printf("\nForneça o preço do produto :\n");
    scanf("%f",&p.preco);
    printf("\nForneça a quantidade em estoque :\n");
    scanf("%d",&p.estoque);
    printf("\nForneça a quantidade da venda :\n");
    scanf("%d",&quantidade);

    if(realizarVendas(&p,quantidade)){
        printf("\nVenda realiza com sucesso\n");
        printf("\nEstoque restante : %d\n",p.estoque);
    }else{
        printf("\nEstoque insuficiente\n");
        printf("\nEstoque atual : %d\n",n.estoque);
    }
    return 0;
}