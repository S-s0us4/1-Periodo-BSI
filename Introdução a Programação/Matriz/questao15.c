/*Questão 15
Uma rede de lojas de cosméticos possui 15 revendedoras e monitora o volume de vendas de cada
uma delas em 4 categorias de produtos diferentes (Perfumaria, Maquiagem, Cuidados com a Pele e
Cabelos).
Faça um programa que receba:
• Os nomes(únicos) das 15 revendedoras e armazene-os em um vetor;
• O preço médio de cada uma das 4 categorias de produtos e armazene-os em um vetor;
• A quantidade de itens vendidos por cada revendedora em cada categoria, armazenando esses
dados em uma matriz 15x4 (onde as linhas representam as revendedoras e as colunas
representam as categorias).
O programa deve calcular e mostrar:
1. Faturamento por Revendedora: O valor total em Reais ($R\$$) vendido por cada
revendedora na semana (multiplicando a quantidade de itens vendidos pelo preço de sua
respectiva categoria).
2. Destaque por Categoria: Para cada uma das 4 categorias, o nome da revendedora que vendeu
a maior quantidade de itens.
3. Total de Itens por Categoria: A quantidade total de produtos vendidos na rede de lojas em
cada uma das 4 categorias (soma de todas as revendedoras).
4. Campeã de Vendas: O nome da revendedora que obteve o maior faturamento total em Reais
(R$).*/

#include <stdio.h>
#include <string.h>
#define TAM 15
#define CAT 4

void limpaBuffer(){
    int c;
    do{
        c=getchar();
    }while(c!='\n');
}
void lerRevendedoras(char vNomes[TAM][100],int tamanho){
    int i,k,achou=0;
    do{
        printf("\nForneça o nome da revendedora :\n");
        scanf("%s",&vNomes[i]);
            for(k=0;k<i;k++){
                if(strcmp(vNomes[k],vNomes[i])==0){
            printf("\nNome já cadastrado!\n");
            achou=1;
        }else{
            strcpy(vNomes[i],vNomes[k]);
        }
            }
        
    }while(achou);
}
void lerPreco(float vPreco[CAT],int cat,char vCategorias[CAT][100]){
    int i;
    for(i=0;i<CAT;i++){
        printf("\nForneça o preço médio da categoria %s :\n",vCategorias[i]);
        scanf("%f",&vPreco[i]);
    }
}
void lerVendas(float mat[TAM][CAT],int tamanho,int cat,char vNomes[TAM][100],float vPreco[CAT],char vCategorias[CAT][100]){
    int lin,col;
    for(lin=0;lin<TAM;lin++){
        printf("\nVendedora %s\n",vNomes[lin]);
            for(col=0;col<CAT;col++){
                printf("\nQuantidade vendida de %s :\n",vCategorias[col]);
                scanf("%f",&mat[lin][col]);
            }
    }
}
void faturamento(float mat[TAM][CAT],int tamanho,int cat,char vNomes[TAM][100],float vPreco[CAT]){
    int lin,col;
    float total;

    for(lin=0;lin<tamanho;lin++){
        total=0;
        for(col=0;col<CAT;col++){
            total+=mat[lin][col]*vPreco[col];
        }
        printf("\n%s - %2.f",vNomes[lin],total);
    }
}
int main(){

    char vNomes[TAM][100],
    vCategorias[CAT][100]={"Perfumaria","Maquiagem","Cuidados com a Pele","Cabelos"};

    float vPreco[CAT];
    float mat[TAM][CAT];

    
    lerRevendedoras(vNomes,TAM);
    lerPreco(vPreco,CAT,vCategorias);
    lerVendas(mat,TAM,CAT,vNomes,vPreco,vCategorias);

    return 0;
}