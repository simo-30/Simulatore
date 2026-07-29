#include <stdio.h>
#include <stdlib.h>
#include "Database/sqlite3.h"
#include "Database/database.h"
#include "Punto/punto.h"

int main(){
	sqlite3 *db = apri_database("Database/archivio.db");

    if (db == NULL) {
        return EXIT_FAILURE;
    }

    printf("Database aperto correttamente.\n");
    
        const char *sql =
        "CREATE TABLE IF NOT EXISTS utenti ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome TEXT NOT NULL,"
        "cognome TEXT NOT NULL,"
        "eta INTEGER"
        ");";
        
        create_table(sql, db);

	stampa_tabella(db, "SELECT * FROM utenti");

    sqlite3_close(db);
    db = NULL;

    printf("Database chiuso correttamente.\n");
    
	
	return 0;
}

