/*Questão 02
Faça um programa que:
1. Leia a dimensão N de uma matriz quadrada (1 ≤ N ≤ 10). Valide a entrada.
2. Preencha cada posição da matriz M com com valores fornecidos pelo usuário.
Calcule e imprima:
• A soma dos elementos da diagonal principal(onde i = j)
• A soma dos elementos da diagonal secundária (onde i + j = N - 1)
• Imprima a matriz em formato de tabela, destacando os elementos da diagonal principal (por
exemplo, colocando-os entre colchetes).
Exemplo:
Digite o valor de N (1 a 10): 4
MATRIZ GERADA LIDA
0
1
2
3
0 [0] 1 2 {-6}
1 1 [2] {-1} 4
2 2 {7} [4] 5
3 {-3} 4 5 [6]
Legenda: elementos entre [ ] são da diagonal principal e da diagonal secundária entre {}
DIAGONAL PRINCIPAL (i = j): elementos [0, 2, 4, 6]
Soma da diagonal principal = 12
DIAGONAL SECUNDÁRIA (i + j = 3): elementos (6, -1, 10, 3)
Soma da diagonal secundária = 18*/

#include <stdio.h>
int main(){

    int mat[100][100];
    int n,lin,col,somaP,somaS;

    printf("\nForneça o tamanho da matriz :\n");
    scanf("%d",&n);

    if(n<1 || n>10){
        printf("\nValor inválido!\n");
        return 1;
    }else{
        for(lin=0;lin<n;lin++){
            for(col=0;col<n;col++){
                printf("\nForneça o valor para a posição [%d][%d]:\n",lin,col);
                scanf("%d",&mat[lin][col]);
            }
        }
        if(lin==col){
            printf("\nDiagonal principal: %d\t",mat[lin][col]);
            somaP+=mat[lin][col];
        }
    }

    return 0;
}