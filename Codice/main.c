#include <stdio.h>
#include <stdlib.h>
#include "Database/sqlite3.h"
#include "Database/database.h"

int main(){
	sqlite3 *db = apri_database("Database/archivio.db");

    if (db == NULL) {
        return EXIT_FAILURE;
    }

    printf("Database aperto correttamente.\n");

    /*
     * Qui puoi usare db per eseguire:
     * SELECT, INSERT, UPDATE, DELETE...
     */

    sqlite3_close(db);
    db = NULL;

    printf("Database chiuso correttamente.\n");
	
	return 0;
}

