#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "database.h"

sqlite3 *apri_databse (const char *percorso) {
	sqlite3 *db = NULL;

    int risultato = sqlite3_open_v2(
        percorso,
        &db,
        SQLITE_OPEN_READWRITE,
        NULL
    );

    if (risultato != SQLITE_OK) {
        fprintf(
            stderr,
            "Errore nell'apertura del database '%s': %s\n",
            percorso,
            db != NULL ? sqlite3_errmsg(db) : "Errore sconosciuto"
        );

        if (db != NULL) {
            sqlite3_close(db);
        }

        return NULL;
    }

    return db;
}
