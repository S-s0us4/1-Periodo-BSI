/*Uma empresa que possui 20 funcionários, guarda a quantidade 
vendida por cada um de seus funcionários em cada um dos 7 dias 
dasemana. Faça um programa que:
• Mostre a quantidade vendida por cada funcionário;
• Mostre em qual ou quais dias da semana cada funcionário 
vendeu mais;
• O nome do funcionário ou funcionários com maior valor de 
venda na semana;
• Para cada dia da semana, a quantidade vendida por cada 
funcionário.
*/

#include <stdio.h>
#include <string.h>

#define NUMERO_DIAS_SEMANA 7
#define NUMERO_FUNCIONARIOS 20
#define TAMANHO_NOME 100

void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n');
}

int main(){
    float vendas[NUMERO_DIAS_SEMANA][NUMERO_FUNCIONARIOS],soma,maiorVenda,
    vSomasVendas[NUMERO_FUNCIONARIOS]={0};//aramazena a soma das vendas na semana de cada funconário
    
    char vNomes[NUMERO_FUNCIONARIOS][TAMANHO_NOME],
         vDiasSemana[NUMERO_DIAS_SEMANA][20]={"Domingo","Segunda",
             "Terça","Quarta","Quinta","Sexta","Sábado" };
    int linha, coluna, tam;
    
    for(coluna=0;coluna<NUMERO_FUNCIONARIOS;coluna++){
        printf("Forneça o nome do(a) %do(a) Funcion[ario(a):",coluna+1);
        fgets(vNomes[coluna],TAMANHO_NOME,stdin);
        tam= strlen(vNomes[coluna]);
        if(vNomes[coluna][tam-1]=='\n')
            vNomes[coluna][tam-1]='\0';
        else
            limpaBuffer();
        /*lendo a quantidasde vendida em cada dia da semana
        pelo funcionário corrente*/
        printf("Qtde. Vendida pelo Funcionario %s em cada dia da semana\n",vNomes[coluna]);
        for(linha=0;linha<NUMERO_DIAS_SEMANA-5;linha++){
            printf("%s:",vDiasSemana[linha]);
            scanf("%f",&vendas[linha][coluna]);
            vSomasVendas[coluna]+=vendas[linha][coluna];
        }
        //retirando o enter deixado pelo último scanf do buffer de entrada
        limpaBuffer();
        
    }
    
    //Mostre a quantidade vendida por cada funcionário;
    printf("\nQuantidade Vendida por cada Funcionário:\n");
    for(coluna=0;coluna<NUMERO_FUNCIONARIOS;coluna++){
        soma=0;
        for(linha=0;linha<NUMERO_DIAS_SEMANA;linha++){
            soma = soma + vendas[linha][coluna]   ;
        }
        printf("%s = R$%.1f",vNomes[coluna],soma);
    }
    
    //Mostre em qual ou quais dias da semana cada funcionário vendeu mais
    
    for(coluna=0;coluna<NUMERO_FUNCIONARIOS;coluna++){
        maiorVenda = vendas[0][coluna];
        for(linha=0;linha<NUMERO_DIAS_SEMANA;linha++){
           if(vendas[linha][coluna]>maiorVenda){
               maiorVenda = vendas[linha][coluna];
           }
           
        }
        
        printf("\nFuncionário: %s\n",vNomes[coluna]);
        printf("Maior Valor de Venda = R$%.1f",maiorVenda);
        printf("Dias da Semana que obteve este valor de venda\n");
        for(linha=0;linha<NUMERO_DIAS_SEMANA;linha++){
            if(vendas[linha][coluna]==maiorVenda)
                printf("%s\n",vDiasSemana[linha]);
        }
    }
    //Para cada dia da semana, a quantidade vendida por cada funcionário.
    printf("\nRelatório qtde vendida em cada dia da semana por cada funcionário\n");
    for(linha=0;linha<NUMERO_DIAS_SEMANA;linha++){
        printf("\nDiama da Semana = %s\n",vDiasSemana[linha])
        for(coluna=0;coluna<NUMERO_FUNCIONARIOS;coluna++){
            ptintf("%s = %.1f\n",vNomes[coluna],vendas[linha][coluna]);
        
    }

    return 0;
}
