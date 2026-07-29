#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "database.h"

sqlite3 *apri_database (const char *percorso) {
	sqlite3 *db = NULL;

    int risultato = sqlite3_open_v2(
        percorso,
        &db,
        SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
        NULL
    );

    if (risultato != SQLITE_OK) {
        fprintf(
            stderr,
            "Errore apertura database '%s': %s\n",
            percorso,
            db != NULL ? sqlite3_errmsg(db) : "errore sconosciuto"
        );

        if (db != NULL) {
            sqlite3_close(db);
        }

        return NULL;
    }

    printf(
        "File database effettivamente aperto: %s\n",
        sqlite3_db_filename(db, "main")
    );

    return db;
}

int create_table (const char *sql_statement, sqlite3 *file_db) {
	char *messaggio_errore = NULL;

    int risultato = sqlite3_exec(
        file_db,
        sql_statement,
        NULL,
        NULL,
        &messaggio_errore
    );

    if (risultato != SQLITE_OK) {
        fprintf(
            stderr,
            "Errore nella creazione della tabella: %s\n",
            messaggio_errore != NULL
                ? messaggio_errore
                : sqlite3_errmsg(file_db)
        );

        sqlite3_free(messaggio_errore);
        return 0;
    }

    printf("Tabella 'utenti' creata o già esistente.\n");

    return 1;
}

int stampa_tabella(sqlite3 *db, const char *sql) {
	if (db == NULL || sql == NULL) {
        fprintf(stderr, "Database o query non validi.\n");
        return 0;
    }

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
            "Errore nella preparazione della query: %s\n",
            sqlite3_errmsg(db)
        );

        return 0;
    }

    int numero_colonne = sqlite3_column_count(statement);

    /* Stampa i nomi delle colonne */
    for (int colonna = 0; colonna < numero_colonne; colonna++) {
        printf("%-20s", sqlite3_column_name(statement, colonna));
    }

    printf("\n");

    for (int colonna = 0; colonna < numero_colonne; colonna++) {
        printf("--------------------");
    }

    printf("\n");

    int numero_righe = 0;

    while ((risultato = sqlite3_step(statement)) == SQLITE_ROW) {

        numero_righe++;

        for (int colonna = 0; colonna < numero_colonne; colonna++) {

            int tipo = sqlite3_column_type(statement, colonna);

            switch (tipo) {

                case SQLITE_INTEGER:
                    printf(
                        "%-20lld",
                        (long long) sqlite3_column_int64(
                            statement,
                            colonna
                        )
                    );
                    break;

                case SQLITE_FLOAT:
                    printf(
                        "%-20.6f",
                        sqlite3_column_double(statement, colonna)
                    );
                    break;

                case SQLITE_TEXT: {
                    const unsigned char *testo =
                        sqlite3_column_text(statement, colonna);

                    printf(
                        "%-20s",
                        testo != NULL
                            ? (const char *) testo
                            : ""
                    );

                    break;
                }

                case SQLITE_NULL:
                    printf("%-20s", "NULL");
                    break;

                case SQLITE_BLOB: {
                    int dimensione =
                        sqlite3_column_bytes(statement, colonna);

                    printf("<BLOB: %d byte>    ", dimensione);
                    break;
                }

                default:
                    printf("%-20s", "?");
                    break;
            }
        }

        printf("\n");
    }

    if (risultato != SQLITE_DONE) {
        fprintf(
            stderr,
            "Errore durante la lettura: %s\n",
            sqlite3_errmsg(db)
        );

        sqlite3_finalize(statement);
        return 0;
    }

    if (numero_righe == 0) {
        printf("La query non ha restituito righe.\n");
    } else {
        printf("\nRighe trovate: %d\n", numero_righe);
    }

    sqlite3_finalize(statement);

    return 1;
}
