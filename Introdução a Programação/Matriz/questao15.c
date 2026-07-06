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

void lerRevendedoras(char vNomes[TAM][100]){
    int i, j, existe;

    for(i=0; i<TAM; i++){

        do{
            existe = 0;

            printf("Nome da revendedora %d: ", i+1);
            scanf("%s", vNomes[i]);

            for(j=0; j<i; j++){
                if(strcmp(vNomes[i], vNomes[j]) == 0){
                    printf("Nome ja cadastrado! Digite outro.\n");
                    existe = 1;
                    break;
                }
            }

        }while(existe);
    }
}

void lerPreco(float vPreco[CAT], char vCategorias[CAT][100]){
    int i;

    for(i=0; i<CAT; i++){
        printf("Preco medio da categoria %s: ", vCategorias[i]);
        scanf("%f", &vPreco[i]);
    }
}

void lerVendas(float mat[TAM][CAT],
               char vNomes[TAM][100],
               char vCategorias[CAT][100]){

    int lin, col;

    for(lin=0; lin<TAM; lin++){

        printf("\nRevendedora: %s\n", vNomes[lin]);

        for(col=0; col<CAT; col++){

            printf("Quantidade vendida de %s: ", vCategorias[col]);
            scanf("%f", &mat[lin][col]);

        }
    }
}

void faturamentoRevendedora(float mat[TAM][CAT],
                            float vPreco[CAT],
                            char vNomes[TAM][100]){

    int lin, col;
    float total;

    printf("\n========== FATURAMENTO POR REVENDEDORA ==========\n");

    for(lin=0; lin<TAM; lin++){

        total = 0;

        for(col=0; col<CAT; col++){

            total += mat[lin][col] * vPreco[col];

        }

        printf("%s -> R$ %.2f\n", vNomes[lin], total);

    }

}

void destaqueCategoria(float mat[TAM][CAT],
                       char vNomes[TAM][100],
                       char vCategorias[CAT][100]){

    int lin, col;
    int maior;

    printf("\n========== DESTAQUE POR CATEGORIA ==========\n");

    for(col=0; col<CAT; col++){

        maior = 0;

        for(lin=1; lin<TAM; lin++){

            if(mat[lin][col] > mat[maior][col]){

                maior = lin;

            }

        }

        printf("%s -> %s (%.0f itens)\n",
               vCategorias[col],
               vNomes[maior],
               mat[maior][col]);

    }

}

void totalCategoria(float mat[TAM][CAT],
                    char vCategorias[CAT][100]){

    int lin, col;
    float soma;

    printf("\n========== TOTAL DE ITENS POR CATEGORIA ==========\n");

    for(col=0; col<CAT; col++){

        soma = 0;

        for(lin=0; lin<TAM; lin++){

            soma += mat[lin][col];

        }

        printf("%s -> %.0f itens\n",
               vCategorias[col],
               soma);

    }

}

void campeaVendas(float mat[TAM][CAT],
                  float vPreco[CAT],
                  char vNomes[TAM][100]){

    int lin, col;
    int campea = 0;

    float maior = 0;
    float total;

    for(lin=0; lin<TAM; lin++){

        total = 0;

        for(col=0; col<CAT; col++){

            total += mat[lin][col] * vPreco[col];

        }

        if(total > maior){

            maior = total;
            campea = lin;

        }

    }

    printf("\n========== CAMPEA DE VENDAS ==========\n");
    printf("Revendedora: %s\n", vNomes[campea]);
    printf("Faturamento: R$ %.2f\n", maior);

}

int main(){

    char vNomes[TAM][100];

    char vCategorias[CAT][100] = {
        "Perfumaria",
        "Maquiagem",
        "Cuidados com a Pele",
        "Cabelos"
    };

    float vPreco[CAT];
    float mat[TAM][CAT];

    lerRevendedoras(vNomes);

    lerPreco(vPreco, vCategorias);

    lerVendas(mat, vNomes, vCategorias);

    faturamentoRevendedora(mat, vPreco, vNomes);

    destaqueCategoria(mat, vNomes, vCategorias);

    totalCategoria(mat, vCategorias);

    campeaVendas(mat, vPreco, vNomes);

    return 0;
}
