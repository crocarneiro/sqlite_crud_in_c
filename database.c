#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>

void open_database(sqlite3 **ppdb)
{
    //int rc = sqlite3_open_v2("database.db", &ppdb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, "unix-none");
    int rc = sqlite3_open("database.db", ppdb);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "Error opening database: %s.\n", sqlite3_errmsg(*ppdb));
        exit(1);
    }
}

void create_alunos_table(sqlite3 *ppdb)
{
    char *err_msg = 0;
    char *sql = "CREATE TABLE IF NOT EXISTS alunos(id INT AUTO_GENERATED PRIMARY KEY, "
                "nome VARCHAR(50), "
                "sobrenome VARCHAR(50), "
                "data_nascimento DATE, "
                "email VARCHAR(100), "
                "qtde_faltas INT, "
                "CONSTRAINT alunos_uk UNIQUE(nome, sobrenome));";
    fprintf(stdout, "Query: \n");
    fprintf(stdout, "%s\n", sql);
    int rc = sqlite3_exec(ppdb, sql, 0, 0, &err_msg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "\nError creating table 'alunos': %s\n%s\n", err_msg, sqlite3_errmsg(ppdb));
        sqlite3_free(err_msg);
        sqlite3_close(ppdb);
        exit(1);
    }
}

void create_tables(sqlite3 *ppdb)
{
    create_alunos_table(ppdb);
}

void execute_migrations(sqlite3 *ppdb)
{
    create_tables(ppdb);
}
