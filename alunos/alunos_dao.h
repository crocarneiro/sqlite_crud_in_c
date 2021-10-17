#ifndef ALUNOS_DAO_H_
#define ALUNOS_DAO_H_
#include <sqlite3.h>
#include "aluno.h"

void insert_aluno(sqlite3 *ppdb, Aluno aluno);

#endif
