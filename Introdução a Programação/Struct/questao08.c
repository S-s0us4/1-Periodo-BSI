/*Questão 08
Crie um programa para controlar até 50 produtos.
Cada produto possui:
• código; 
• nome; 
• preço; 
• quantidade em estoque. 
O sistema deve possuir o menu:
1 - Cadastrar produto
2 - Listar produtos
3 - Buscar produto por código
4 - Registrar entrada no estoque
5 - Registrar venda
6 - Mostrar valor total do estoque
0 - Sair
A venda só pode ser realizada se houver quantidade suficiente em estoque*/

#include <stdio.h>
#include <string.h>
#define MAX_P 50

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
void cadastrarP(TProduto vp[MAX_P],int *quantidade){
    int tam;
    if(*quantidade == MAX_P){
        printf("\nMáximo de produtos já cadastrados\n");
        return;
    }
    printf("\nForneça o código do produto:\n");
    scanf("%d",&vp[*quantidade].codigo);
    printf("\nForneça o nome do produto:\n");
    fgets(vp[*quantidade].nome,100,stdin);
    tam = strlen(vp[*quantidade].nome);
    if(vp[*quantidade].nome[tam-1]=='\n'){
        vp[*quantidade].nome[tam-1]='\0';
    }else{
        limpaBuffer();
    }
    printf("\nForneça o preço do produto :\n");
    scanf("%f",&vp[*quantidade].preco);
    printf("\nForneça a quantidade em estoque:\n");
    scanf("%d",&vp[*quantidade].estoque);
    (*quantidade)++;
}
void listarP(TProduto vp[MAX_P],int quantidade){
    int i;
    for(i=0;i<quantidade;i++){
        printf("\nCódigo do produto :%d\n",vp[i].codigo);
        printf("\nNome do produto : %s\n",vp[i].nome);
        printf("\nPreço do produto: %f\n",vp[i].preco);
        printf("\nQuantidade em estoque do produto :%d\n",vp[i].estoque);
    }
}
void buscarP(TProduto vp[MAX_P],int quantidade){
    int achou=0,cod,i;
    print("\nForneça o código do produto :\n");
    scanf("%d",&cod);
    for(i=0;i<quantidade;i++){
        if(cod==vp[i].codigo){
            printf("\nNome do produto : %s\n",vp[i].nome);
            printf("\nPreço do produto: %f\n",vp[i].preco);
            printf("\nQuantidade em estoque do produto :%d\n",vp[i].estoque);
            achou=1;
        }
    }
    if(achou==0){
        printf("\nProduto não cadastrado\n");
        return;
    }
}
void entradaP(TProduto vp[MAX_P],int quantidade){
    int entrada,i,cod;
    printf("\nForneça o código do produto:\n");
    scanf("%d",&cod);
    for(i=0;i<quantidade;i++){
        if(cod==vp[i].codigo){
            printf("\nProduto encontrado\n");
            printf("\nQuantidade em estoque do produto :%d\n",vp[i].estoque);
            printf("\nForneça a quantidade a adicionar no estoque :\n");
            scanf("%d",&entrada);
            vp[i].codigo+=entrada;
            printf("\nEstoque atualizado com sucesso\n");
            printf("\nQuantidade atual em estoque do produto:%d\n",vp[i].estoque);
            return;
        }
    }
        printf("\nProduto não cadastrado\n");
        return;
}
void venda(TProduto vp[MAX_P],int quantidade){
    int venda,cod,i,achou=0;
    printf("\nForneça o código do produto a ser vendido:\n");
    scanf("%d",&cod);
    for(i=0;i<quantidade;i++){
        if(cod==vp[i].codigo){
            printf("\nForneça a quantidade a ser comprada:\n");
            scanf("%d",&venda);
            if(venda<=vp[i].estoque){
                printf("\nProduto vendido com sucesso\n");
                vp[i].estoque-=venda;
                printf("\nQuantidade atual em estoque do produto:%d\n",vp[i].estoque);
                return;
            }else
                printf("\nQuantidade excedida do produto\n");
                return;
        }else 
            printf("\nCódigo inválido\n");
            return;
    }

}
void estoque(TProduto vp[MAX_P],int quantidade){
    int i ;
    float total=0;
    for(i=0;i<quantidade;i++){
        total+=vp[i].preco*vp[i].estoque;
    }
    printf("\nValor total em estoque:%f\n",total);

}
int main(){
    TProduto vp[MAX_P];

    int quantidade=0,opcao;
    do{
    printf("\n1 - Cadastrar produto");
    printf("\n2 - Listar produtos");
    printf("\n3 - Buscar produto por código");
    printf("\n4 - Registrar entrada no estoque");
    printf("\n5 - Registrar venda");
    printf("\n6 - Mostrar valor total do estoque");
    printf("\n0 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    limpaBuffer();
    switch(opcao){
        case 1 :
            cadastrarP(vp,&quantidade);
            break;
        case 2:
            listarP(vp,quantidade);
            break;
        case 3:
            buscarP(vp,quantidade);
            break;
        case 4:
            entradaP(vp,quantidade);
            break;
        case 5:
            venda(vp,quantidade);
            break;
        case 6:
            estoque(vp,quantidade)
    }
    }while(opcao != 0);
   
    return 0;
}