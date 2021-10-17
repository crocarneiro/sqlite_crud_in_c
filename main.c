#include <stdio.h>
#include <string.h>
#include "database.h"
#include "alunos/alunos_dao.h"

sqlite3 *db;

int main()
{
	open_database(&db);
	execute_migrations(db);

	/*
	Aluno aluno;
	strcpy(aluno.nome, "Carlos Rafael");
	strcpy(aluno.sobrenome, "de Oliveira Carneiro");
	strcpy(aluno.data_nascimento, "1998-02-21");
	strcpy(aluno.email, "contato@carlos.carneiro.nom.br");
	aluno.qtde_faltas = 0;


	insert_aluno(db, aluno);
	*/
	sqlite3_close(db);
	return 0;
}
