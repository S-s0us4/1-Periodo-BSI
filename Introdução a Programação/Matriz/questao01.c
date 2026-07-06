/*Questão 01
Faça um programa que leia as dimensões de uma matriz quadrada de ordem N, onde N é menor ou 
igual a 10. Preencha cada posição da matriz com a soma dos seus próprios índices (ou seja, M[i][j] =
i + j). Ao final, imprima a matriz na tela em formato de tabela.*/

#include <stdio.h>
int main(){
    int mat[100][100];
    int tam;
    int lin , col;
    printf("\nForneça o tamanho da matriz :\n");
    scanf("%d",&tam);

    for(lin=0;lin<tam;lin++){
        for(col=0;col<tam;col++){
            mat[lin][col]+=lin+col;
        }
    }
    printf("\t\tMatriz:\t\n");
    for(lin=0;lin<tam;lin++){
        for(col=0;col<tam;col++){
            printf("\t%d",mat[lin][col]);
        }
        printf("\n");
    }
    return 0;
}