#include <stdio.h>
#include "menu.h"

void print_options(void)
{
    fprintf(stdout, "OPCÕES\n");
    fprintf(stdout, "1. Cadastrar aluno.\n");
    fprintf(stdout, "2. Editar aluno.\n");
    fprintf(stdout, "3. Listar alunos.\n");
    fprintf(stdout, "9. Sair.");
}

void menu(void)
{
    int opcao;
    char aux[100];

    do
    {
        print_options();
        fprintf(stdout, "Selecione uma opção: ");
        fgets(aux, 100, stdin);
    } while(1);
}