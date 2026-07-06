/*Questão 10
Escreva um programa que leia valores inteiros para preencher uma matriz M de dimensões 10x20.
Após a leitura de todos os dados, o programa deve processar a matriz e exibir na tela: 
1. o maior elemento pertencente a cada uma das linhas; 
2. a média aritmética dos elementos de cada uma das colunas; 
3. o resultado do produto (multiplicação) de todos os elementos da matriz que sejam diferentes
de zero; 
4. a posição exata (linha e coluna) de todas as ocorrências de um valor específico, o qual deve
ser digitado pelo usuário ao final do programa. */
#include <stdio.h>

#define LIN 10
#define COL 20

void lerMatriz(int mat[LIN][COL]){
    int lin,col;

    for(lin=0;lin<LIN;lin++){
        for(col=0;col<COL;col++){
            printf("M[%d][%d]: ",lin,col);
            scanf("%d",&mat[lin][col]);
        }
    }
}
void maiorLinha(int mat[LIN][COL]){
    int lin,col,maior;
    printf("\nMaior elemento de cada linha:\n");
    for(lin=0;lin<LIN;lin++){
        maior=mat[lin][0];
        for(col=1;col<COL;col++){
            if(mat[lin][col]>maior){
                maior=mat[lin][col];
            }
        }
        printf("Linha %d: %d\n",lin,maior);
    }
}
void mediaColuna(int mat[LIN][COL]){
    int lin,col;
    float soma;
    printf("\nMedia de cada coluna:\n");
    for(col=0;col<COL;col++){
        soma=0;
        for(lin=0;lin<LIN;lin++){
            soma+=mat[lin][col];
        }
        printf("Coluna %d: %.2f\n",col,soma/LIN);
    }
}
void produtoElementos(int mat[LIN][COL]){
    int lin,col;
    long long produto=1;
    int achou=0;
    for(lin=0;lin<LIN;lin++){
        for(col=0;col<COL;col++){
            if(mat[lin][col]!=0){
                produto*=mat[lin][col];
                achou=1;
            }
        }
    }
    if(achou)
        printf("\nProduto dos elementos diferentes de zero: %lld\n",produto);
    else
        printf("\nNao existem elementos diferentes de zero.\n");
}
void procurarValor(int mat[LIN][COL]){
    int valor;
    int lin,col;
    int encontrou=0;
    printf("\nDigite um valor para procurar: ");
    scanf("%d",&valor);
    for(lin=0;lin<LIN;lin++){
        for(col=0;col<COL;col++){
            if(mat[lin][col]==valor){
                printf("Encontrado na linha %d coluna %d\n",lin,col);
                encontrou=1;
            }
        }
    }
    if(!encontrou){
        printf("Valor nao encontrado.\n");
    }
}
int main(){
    int mat[LIN][COL];
    lerMatriz(mat);
    maiorLinha(mat);
    mediaColuna(mat);
    produtoElementos(mat);
    procurarValor(mat);
    return 0;
}
