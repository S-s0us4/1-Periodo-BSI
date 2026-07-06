/*Questão 04
Cadastre 10 pessoas com:
• nome; 
• telefone; 
• idade. 
Leia um nome e procure essa pessoa no vetor. Se ela existir, exiba seu telefone e sua idade.
Considere que os nomes são únicos.*/
#include <stdio.h>
#include <string.h>
#define MAX_P 10

typedef struct{
    char nome[100];
    int telefone;
    int idade;
}TPessoas;

void limpaBuffer(){
    int ch;
    do{
        ch=getchar();
    }while(ch!='\n');
}
int main(){
    TPessoas vP[MAX_P];
    int i,tam,repetido,j,achou;
    char nomeTp[100],nomeA[100];
    for(i=0;i<MAX_P;i++){
        do{
            repetido=0;

            printf("\nForneça o nome:\n");
            fgets(nomeTp,100,stdin);

            tam = strlen (nomeTp);
            if(nomeTp[tam-1]=='\n'){
                nomeTp[tam-1]='\0';
            }else{
                limpaBuffer();
            }
            for(j=0;j<i;j++){
                if(strcmp(nomeTp,vP[j].nome)==0){
                    repetido=1;
                    printf("\nNome já cadastrado !\n");
                    break;
                }
            }
            }while(repetido);
            strcpy(vP[i].nome,nomeTp);
            printf("\nForneça o telefone:\n");
            scanf("%d",&vP[i].telefone);
            printf("\nForneça a idade:\n");
            scanf("%d",&vP[i].idade);
            limpaBuffer();
    }
    printf("\nDigite o nome a ser procurado:\n");
    fgets(nomeA,100,stdin);
    tam = strlen(nomeA);
    if(nomeA[tam-1]=='\n'){
        nomeA[tam-1]='\0';
    }else{
        limpaBuffer();
    }
    achou=0;
    for(i=0;i<MAX_P;i++){
        if(strcmp(nomeA,vP[i].nome)==0){
            achou=1;
            printf("\nEncontrado !!\n");
            printf("\nTelefone:%d\n",vP[i].telefone);
            printf("\nIdade:%d\n",vP[i].idade);
            break;
        }if(achou==0){
            printf("\nNome não cadastrado !!\n");
            break;
        }
    }
    return 0;
}