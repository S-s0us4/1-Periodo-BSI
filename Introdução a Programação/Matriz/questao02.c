/*Faça um programa que:
1. Leia a dimensão N de uma matriz quadrada (1 ≤ N ≤ 10). Valide a entrada.
2. Preencha cada posição da matriz M com com valores fornecidos pelo usuário.
Calcule e imprima:
• A soma dos elementos da diagonal principal(onde i = j)
• A soma dos elementos da diagonal secundária (onde i + j = N - 1)
• Imprima a matriz em formato de tabela, destacando os elementos da diagonal principal 
(por exemplo, colocando-os entre colchetes).
Exemplo:
Digite o valor de N (1 a 10): 4
MATRIZ GERADA LIDA
   0  1 2  3
0 [0] 1 2 {-6}
1 1 [2] {-1} 4
2 2 {7} [4] 5
3 {-3} 4 5 [6]
Legenda: elementos entre [ ] são da diagonal principal 
e da diagonal secundária entre {}
DIAGONAL PRINCIPAL (i = j): elementos [0, 2, 4, 6]
Soma da diagonal principal = 12
DIAGONAL SECUNDÁRIA (i + j = 3): elementos (6, -1, 10, 3)
Soma da diagonal secundária = 18 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ORDEM 10

int main(){
    int mat[ORDEM][ORDEM],lin,col,
        n,somaPrincipal=0,somaSecundaria=0;
    do{
        printf("Forneça a oderm da matriz(1<=ordem<=10):");
        scanf("%d",&n);
        if(n<1 || n >ORDEM)
            printf("\nA ordem da matriz está errada!!!\n");
    }while(n<1 || n>ORDEM);
    srand(time(NULL));
    //preenchendo a matriz
    for(lin=0;lin<n;lin++){
        for(col=0;col<n;col++){
            mat[lin][col]=rand()%100;
            //verificando se é a diagonal secundária
            if(lin+col==n-1)
                somaSecundaria+=mat[lin][col];
        }
    }
    
    //imprimindo a matriz
    for(lin=0;lin<n;lin++){
        for(col=0;col<n;col++){
            //verificando se é uma posição da diagonal principal
            if(lin==col){
               printf("[%d]\t",mat[lin][col]);
               somaPrincipal+=mat[lin][col];
            }
            else
                if(lin+col==n-1)  {
                    printf("(%d)\t",mat[lin][col]);
                }
                else
                    printf("%d\t",mat[lin][col]);    
        }
        printf("\n");
    }
    printf("\nSoma da Diagonal Principal = %d\n",somaPrincipal);
    printf("\nSoma da Diagonal Secundaria = %d\n",somaSecundaria);
    return 0;
}
