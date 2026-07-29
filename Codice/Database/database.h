#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

sqlite3 *apri_database (const char *percorso);

int create_table (const char *sql_statement, sqlite3 *file_db);

int stampa_tabella (sqlite3 *db, const char *sql);
