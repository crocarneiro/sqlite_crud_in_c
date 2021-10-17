#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alunos_dao.h"

void insert_aluno(sqlite3 *ppdb, Aluno aluno)
{
	char *err_msg = 0;
	char *template = "INSERT INTO ALUNOS (nome, "
		"sobrenome, "
		"data_nascimento, "
		"email, "
		"qtde_faltas) "
		"VALUES ('%s', "
		"'%s', "
		"'%s', "
		"'%s', "
		"%d);";
	char *sql = (char *) malloc(sizeof(Aluno) + strlen(template));
	sprintf(sql, template,
			aluno.nome,
			aluno.sobrenome,
			aluno.data_nascimento,
			aluno.email,
			aluno.qtde_faltas
	);
	int rc = sqlite3_exec(ppdb, sql, 0, 0, &err_msg);
	fprintf(stdout, "Query:\n");
	fprintf(stdout, "%s\n", sql);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "\nError inserting record: %s\n%s\n", err_msg, sqlite3_errmsg(ppdb));
		sqlite3_free(err_msg);
		sqlite3_close(ppdb);
		exit(1);
	}
}
