/*Faça um programa em linguagem C que apresente o seguinte menu de opções:
1 – Cadastro de Departamento
2 – Cadastro de Funcionários
3 – Consulta de Funcionários
4 – Funcionários de um Departamento
5 – Excluir Funcionário
6 – Excluir Departamento
7 – Fim
O programa deverá ser devidamente modularizado por meio de funções.
1 – Cadastro de Departamento
Permitir o cadastro de até 20 departamentos, contendo:
• código (único)
• nome (não pode ser vazio)
• sigla
2 – Cadastro de Funcionários
Permitir o cadastro de até 1000 funcionários, contendo:
• matrícula (única)
• nome (não pode ser vazio)
• salário
• código do departamento
Regras:
• A matrícula deve ser única;
• O nome não pode ser vazio;
• O salário deve ser maior que zero;
• O código do departamento informado deve existir previamente cadastrado.
3 – Consulta de Funcionários
Exibir a matrícula, nome e nome do departamento dos funcionários cujo nome inicie com um
determinado prefixo informado pelo usuário.
4 – Funcionários de um Departamento
Exibir todos os dados dos funcionários pertencentes a um departamento informado.
5 – Excluir Funcionário
Remover um funcionário a partir de sua matrícula.
6 – Excluir Departamento
Remover um departamento a partir de seu código, bem como todos os funcionários vinculados a
ele.
*/

#include <stdio.h>
#include <string.h>
#define NUMERO_MAXIMO_DEPARTAMENTOS 20
#define NUMERO_MAXIMO_FUNCIONARIOS 100
typedef struct{
    int codigo;
    char nome[50],sigla[5];
}TDepartamento;

typedef struct{
    int matricula;
    char nome[100];
    float salario;
    int codDep;
}TFuncionario;

void limpaBuffer(){
    int ch;
    do{
        ch = getchar();
    }while (ch!='\n');
}
int excluirDepartemento(TDepartamento vd[],int *ultimaPosD,TFuncionario vf[],int *ultimaPosF){
    int indice,i,cod;
    if(*ultimaPosD==-1)
        return 0;
    else{    
        printf("Forneça o código do departamento a ser excluído:");
        scanf("%d",&cod);
        indice =pesquisaDepartamento(vd,ultimaPosD,cod);
        if(indice!=-1){
            vd[indice]=vd[*ultimaPosD];
            *ultimaPosD=*ultimaPosD-1;
            //excluindo todos os funcionários associados ao departamento excluído
            i=0;
            while(i<=*ultimaPosF){
                if(vf[i].codDep==cod){
                    vf[i]=vf[*ultimaPosF];
                    *ultimaPosF = *ultimaPosF-1;
                }
                else
                    i++;
            }
            return 1;
        }
        else
            return 0;
    }
}

int pesquisaDepartamento(TDepartamento v[], int ultimaPosicao,int cod){
    int i;
    for(i=0;i<=ultimaPosicao;i++){
        if(v[i].codigo==cod)
            return i;
    }
    return -1;
}
int cadDepartamentos(TDepartamento v[],int tamanho,int *ultimaPos){
    int cod,i,achou,tam;
    //verificando se tem espaço no vetor de departamentos
    if(*ultimaPos==tamanho-1)
        return 0;
    else{
        printf("Forneça o código do departamento:");
        scanf("%d",&cod);
        //verificando se já existe um departamento com codigo igual a cod
        /*i=0;
        achou=0;
        while(i<=*ultimaPos && achou==0){
            if(v[i].codigo==cod)            
                achou=1;
            else
                i++;
        }

        if(achou==1)
            return 0;*/
        if(pesquisaDepartamento(v,*ultimaPos,cod)!=-1)
            return 0;
        else{
            (*ultimaPos)++;
            v[*ultimaPos].codigo = cod;
            limpaBuffer();
            printf("Forneça o nome do departamento:");
            fgets(v[*ultimaPos].nome,50,stdin);
            tam = strlen(v[*ultimaPos].nome);
            if(v[*ultimaPos].nome[tam-1]=='\n')
                v[*ultimaPos].nome[tam-1]='\0';
            else
                limpaBuffer();

            printf("Forneça a sigla do departamento:");
            fgets(v[*ultimaPos].sigla,5,stdin);
            tam = strlen(v[*ultimaPos].sigla);
            if(v[*ultimaPos].sigla[tam-1]=='\n')
                v[*ultimaPos].sigla[tam-1]='\0';
            else
                limpaBuffer();
            return 1;
        }
    }
}
int cadFuncionarios(TFuncionario v[],TDepartamento vd[],int tamanho,int *ultimaPos,int ultimaPosD){
    int i,mat,achou,tam,ncod;
    char name;
    if(*ultimaPos==tamanho-1){
        return 0;
    }else{
        printf("\nForneça a matrícula:\n");
        scanf("%d",&mat);
        //Verificando se já existe alguma matricula igual a mat
        i=0;
        achou=0;
        if(pesquisaDepartamento(vd,ultimaPosD,ncod)!=-1)
            return 0;
            else{
                while(i<=*ultimaPos && achou==0){
                    if(v[i].matricula==mat){
                        achou=1;
                    }else
                        i++;
                }
                if(achou==1){
                return 0;
                }
                else
                    (*ultimaPos)++;
                    v[*ultimaPos].matricula=mat;
                    limpaBuffer();
                    printf("\nForneça o nome do funcionário:\n");
                    fgets(v[*ultimaPos].nome,100,stdin);
                    tam = strlen(v[*ultimaPos].nome);
                    if(v[*ultimaPos].nome[tam-1]=='\n'){
                    v[*ultimaPos].nome[tam-1]='\0';
                    }else
                        limpaBuffer();
                        return 1;
            }
    }
}
int main(){
    TDepartamento vd[NUMERO_MAXIMO_DEPARTAMENTOS];
    TFuncionario vf[NUMERO_MAXIMO_FUNCIONARIOS];
    int opcao,
        ultimaPosDep = -1,
        ultimaPosFun = -1;
    
    do{
        printf("1-Cadastro de Departamento\n7-Fim");
        printf("\nForneça sua opção:");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                if (cadDepartamentos(vd,NUMERO_MAXIMO_DEPARTAMENTOS,&ultimaPosDep)==1)
                    printf("\nCadastro Realizado com sucesso!!!\n");
                else
                    printf("\nErro no cadastro!!!\n");
                break;
            case 2:
                if (cadFuncionarios(vf,NUMERO_MAXIMO_FUNCIONARIOS,&ultimaPosFun,vd,ultimaPosDep)==1)
                    printf("\nCadastro realizado com sucesso!!!\n");
                    else
                        printf("\nErro no cadastro!!!\n");
                        break;
                
        }

    }while(opcao !=7);
    return 0;
}
