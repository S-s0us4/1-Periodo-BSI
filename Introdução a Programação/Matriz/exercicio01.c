/*EXERCÍCIO 1 – MATRIZ (Nível Prova)
Uma cidade possui um mapa representado por uma matriz N x M.
Cada posição pode conter:
0 -> Rua
1 -> Casa
2 -> Escola
3 -> Hospital
-Implemente as seguintes funções:
int contarCasas(int mapa[][100], int N, int M);

Retorna o número total de casas.

-int maiorLinhaCasas(int mapa[][100], int N, int M);

Retorna a linha que possui mais casas.

-void ruasSemCasas(int mapa[][100], int N, int M);

Mostra quais linhas não possuem nenhuma casa.

-int escolasIsoladas(int mapa[][100], int N, int M);

Uma escola é isolada quando NÃO existe nenhuma casa ao lado (cima, baixo, esquerda ou direita).
Retorne a quantidade.
*/
#include <stdio.h>
int contarCasas(int mp[][100],int N,int M){
    int lin,col,achou=0;
    for(lin=0;lin<N;lin++){
        for(col=0;col<M;col++){
            if(mp[lin][col]==1){
                achou++;
            }
        }
    }
    return achou;
}
int maiorLinhaCasas(int mp[][100],int N,int M){
    int lin,col,maior,achou,linhaMaior=0;
    maior=-1;
    for(lin=0;lin<N;lin++){
         achou=0;
        for(col=0;col<M;col++){
            if(mp[lin][col]==1){
                achou++;
            }
        }
        if(achou>maior){
            maior=achou;
            linhaMaior=lin;
        }
    } 
    for(lin=0;lin<N;lin++){
        for(col=0;col<M;col++){
            printf("\t%d\t",mp[lin][col]);
        }
        printf("\n");
    }
    return linhaMaior;
}
void ruasSemCasas(int mp[][100], int N, int M){
    int lin,col,achou;
    for(lin=0;lin<N;lin++){
        achou=0;
        for(col=0;col<M;col++){
           if(mp[lin][col]==1){
                achou=1;
           }
        }
        if(achou==0){
            printf("\nLinhas sem Casas %d\n",lin);
        }
    }
}
int escolasIsoladas(int mp[][100], int N, int M){
    int lin,col,achou=0,isolada=0;
    for(lin=0;lin<N;lin++){
        for(col=0;col<M;col++){
           if(mp[lin][col]==2){
            isolada = 1;
            if(lin>0 && mp[lin-1][col]==1){
                isolada = 0;
            }
            if(lin < N - 1 && mp[lin+1][col]==1){
                isolada = 0;
            }
            if(col>0 && mp[lin][col-1]==1){
                isolada = 0;
            }
            if(col < M -1 && mp[lin][col+1]==1){
                isolada = 0;
            }
            if(isolada == 1){
                achou++;
            }
           }
        }
    }
    return achou;
}
int main(){
    int n,m,mapa[100][100],numC,maior,lin,col,numE;

    printf("\nForneça o número de Linhas :\n");
    scanf("%d",&n);

    printf("\nForneça o número de Colunas :\n");
    scanf("%d",&m);

    for(lin=0;lin<n;lin++){
        for(col=0;col<m;col++){
            printf("\nForneça o valor do mapa na posição linha %d e coluna %d:\n0 -Rua\n1 -Casa\n2 -Escola\n3 -Hospital\n",lin,col);
            scanf("%d",&mapa[lin][col]);
        }
    }
    numC = contarCasas(mapa,n,m);
    maior = maiorLinhaCasas(mapa,n,m);
    numE = escolasIsoladas(mapa,n,m);
    printf("\nNúmero de casas encontradas : %d\n",numC);
    printf("\nLinha com o maior número de casas é : %d\n",maior);
    ruasSemCasas(mapa,n,m);
    printf("\nNúmero de escolas encontradas : %d\n",numE);


    return 0;
}