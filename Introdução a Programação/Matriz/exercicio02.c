/*EXERCÍCIO 2 – MATRIZ (Mais difícil)
Mapa de Temperatura
Uma matriz representa temperaturas.
Cada posição contém uma temperatura.

Implemente:

float mediaTemperatura(...);
int linhaMaisQuente(...);
void colunasFrias(...);

Mostra todas as colunas cuja média seja menor que 10.

int pontosCriticos(...);

Um ponto crítico é maior que TODOS os seus vizinhos.

Esse exercício força você a aprender a trabalhar com vizinhos.
*/
#include <stdio.h>
#define TAM_MAX 2
float mediaTemperatura(int mp[TAM_MAX][TAM_MAX], int tamanho){
    int lin,col,soma=0;
    float media;
    for(lin=0;lin<tamanho;lin++){
        for(col=0;col<tamanho;col++){
            soma += mp[lin][col];
        }
    }
    media = soma / (float)(tamanho*tamanho);
    return media ;
}
int linhaMaisQuente(int mp[TAM_MAX][TAM_MAX],int tamanho){
    int lin,col,maior=-1,somaLinhas,linQuente;
    for(lin=0;lin<tamanho;lin++){
        somaLinhas=0;
        for(col=0;col<tamanho;col++){
            somaLinhas += mp[lin][col];
        }
        if(somaLinhas>maior){
            maior = somaLinhas;
            linQuente = lin;
        }
    }
    return linQuente;
}
void colunasFrias(int mp[TAM_MAX][TAM_MAX],int tamanho){
    int lin,col,soma;
    float media;
    for(col=0;col<tamanho;col++){
        soma=0;
        for(lin=0;lin<tamanho;lin++){
            soma += mp[lin][col];
        }
        media = soma / (float)tamanho;
        if(media < 10){
            printf("\nColunas cuja a média é menor que 10 : %d\n",col);
        }
    }
}
int pontosCriticos(int mp[TAM_MAX][TAM_MAX],int tamanho){
    int lin,col,critico,cont=0;
    for(lin=0;lin<tamanho;lin++){
        for(col=0;col<tamanho;col++){
            critico=1;
            if(lin>0 && mp[lin][col] <= mp[lin-1][col]){//cima
                critico = 0;
            }
            if(lin < tamanho -1 && mp[lin][col] <=mp[lin+1][col]){//baixo
                critico = 0;
            }
            if(col>0 && mp[lin][col] <= mp[lin][col-1]){
                critico =0;
            }
            if(col < tamanho -1 && mp[lin][col] <= mp[lin][col+1]){
                critico =0;
            }
             if(critico==1){
                cont++;
            }
        }
    }
   
    return cont;
}
int main(){
    int mapa[TAM_MAX][TAM_MAX]={0},lin,col,quente,criticos;
    float media ;
    for(lin=0;lin<TAM_MAX;lin++){
        for(col=0;col<TAM_MAX;col++){
            printf("\nForneça a temperatura da linha %d e coluna %d :\n",lin,col);
            scanf("%d",&mapa[lin][col]);
        }
    }
    media = mediaTemperatura(mapa,TAM_MAX);
    quente = linhaMaisQuente(mapa,TAM_MAX);
    colunasFrias(mapa,TAM_MAX);
    criticos = pontosCriticos(mapa,TAM_MAX);
    printf("\nMédia das Temperaturas : %.f\n",media);
    printf("\nLinha com a temperatura mais alta : %d\n",quente);
    printf("\nPontos criticos : %d\n",criticos);
    return 0;
}