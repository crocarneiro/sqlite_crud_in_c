#ifndef DATABASE_H_
#define DATABASe_H_
#include<sqlite3.h>

void open_database(sqlite3 **ppdb);
void execute_migrations(sqlite3 *ppdb);

#endif
