#include <stdio.h>
#include "database.h"

sqlite3 *db;

int main()
{
    open_database(&db);
    execute_migrations(db);
    sqlite3_close(db);
    return 0;
}
