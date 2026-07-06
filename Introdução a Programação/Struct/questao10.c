/*Questão Única – Sistema de Gerenciamento de Projetos de Pesquisa
Uma universidade deseja desenvolver um sistema para gerenciar seus projetos de pesquisa.
Cada projeto pertence a um pesquisador, e cada pesquisador pertence a um departamento.
Cada data deve ser representada por uma estrutura composta por três números inteiros: dia, mês e ano.
O programa deverá permitir o cadastro de, no máximo:
20 departamentos;
100 pesquisadores;
100 projetos.
-Estruturas:

Departamento
código (único);
nome;
sigla.

Pesquisador
matrícula (gerada automaticamente pelo programa, iniciando em 1);
nome;
salário;
código do departamento ao qual pertence.

Projeto
código (gerado automaticamente pelo programa, iniciando em 1);
título;
valor do financiamento;
data de início;
data de término;
matrícula do pesquisador responsável.

O programa deverá ser modularizado por meio de funções e apresentar o seguinte menu:

1 – Cadastro de Departamento
Regras:
o código do departamento deve ser único;
o nome não pode ser vazio;
não permitir cadastrar mais de 20 departamentos.

2 – Cadastro de Pesquisador
Regras:
a matrícula deve ser gerada automaticamente;
o nome não pode ser vazio;
o salário deve ser maior que zero;
somente permitir o cadastro caso o departamento informado exista;
não permitir cadastrar mais de 100 pesquisadores.

3 – Cadastro de Projeto
Regras:
o código deve ser gerado automaticamente;
somente permitir o cadastro caso o pesquisador informado exista;
registrar a data de início e a data de término;
não permitir cadastrar mais de 100 projetos.

4 – Consultar Projeto
Exibir:
código;
título;
valor do financiamento;
data de início;
data de término;
nome do pesquisador responsável;
nome do departamento ao qual pertence o pesquisador.

5 – Pesquisar Pesquisadores

6 – Projetos de um Departamento
Informar o código de um departamento.
Exibir todos os projetos pertencentes aos pesquisadores daquele departamento.

7 – Valor Total dos Projetos
Informar um mês e um ano.
Calcular e exibir o valor total dos financiamentos dos projetos cuja data de início pertence ao mês e ano informados.

8 – Valor Médio dos Projetos
Calcular e exibir o valor médio do financiamento de todos os projetos cadastrados.

9 – Excluir Pesquisador
Excluir um pesquisador a partir de sua matrícula.
Todos os projetos pertencentes a esse pesquisador também deverão ser removidos.

10 – Excluir Departamento
Excluir um departamento a partir de seu código.
Todos os pesquisadores pertencentes ao departamento deverão ser removidos, bem como todos os projetos desses pesquisadores.

11 – Encerrar Programa
Finalizar a execução do programa.
Regras Gerais

12 – Pesquisador com Maior Valor em Projetos:
O programa deverá exibir o nome do pesquisador que possui a maior soma de financiamentos considerando todos os seus projetos. Em caso de empate, exibir todos os pesquisadores empatados.
Essa opção exige percorrer e relacionar diferentes vetores, sendo um excelente treino para consolidar o conteúdo da prova.*/