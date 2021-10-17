#ifndef ALUNO_H_
#define ALUNO_H_

typedef struct Alunos {
	char nome[50];
	char sobrenome[50];
	char data_nascimento[12];
	char email[100];
	int qtde_faltas;
} Aluno;

#endif
