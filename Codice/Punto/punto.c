#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

Punto crea_punto (int x, int y, int z) {
	Punto p;
	
	p.x=x;
	p.y=y;
	p.z=z;
	
	
	return p;
}

/*
int crea_tabella_punti (sqlite3 *db) {
    
    create_table(SQL_CREATE_TABLE_PUNTI, db);
	
	return 0;
}

int insert_punto_intoDB(Punto p, sqlite3 *db)
{
    if (db == NULL) {
        fprintf(stderr, "Database non valido.\n");
        return 1;
    }

    const char *sql = SQL_INSERT_PUNTO;
    sqlite3_stmt *statement = NULL;

    int risultato = sqlite3_prepare_v2(
        db,
        sql,
        -1,
        &statement,
        NULL
    );

    if (risultato != SQLITE_OK) {
        fprintf(
            stderr,
            "Errore nella preparazione della INSERT: %s\n",
            sqlite3_errmsg(db)
        );

        return 1;
    }

    sqlite3_bind_int(statement, 1, p.x);
    sqlite3_bind_int(statement, 2, p.y);
    sqlite3_bind_int(statement, 3, p.z);

    risultato = sqlite3_step(statement);

    if (risultato != SQLITE_DONE) {
        fprintf(
            stderr,
            "Errore durante la INSERT: %s\n",
            sqlite3_errmsg(db)
        );

        sqlite3_finalize(statement);
        return 1;
    }

	risultato = sqlite3_step("COMMIT;");

    p.id = (int)sqlite3_last_insert_rowid(db);

    printf(
        "Punto inserito: id=%d, x=%d, y=%d, z=%d\n",
        p.id,
        p.x,
        p.y,
        p.z
    );

    printf(
        "Righe inserite: %d\n",
        sqlite3_changes(db)
    );

    sqlite3_finalize(statement);

    return 0;
}
*/
