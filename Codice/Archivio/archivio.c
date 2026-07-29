#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "archivio.h"

bool esiste_file(const char *path_file) {
	FILE *file = fopen(path_file, "r");

    if (file == NULL) {
        return false;
    }

    fclose(file);
    return true;
}

int crea_file_archivio(const char *path_file) {
	FILE *file = fopen(path_file, "w");
	
    if (file == NULL) {
        printf("Errore durante la creazione del file %s\n", path_file);
        return 1;
    }

    printf("File %s creato correttamente\n", path_file);

    fclose(file);
    return 0;
}

int get_id_punto() {
	FILE *f = fopen(PATH_ARCHIVIO_PUNTI, "r");
    if (f == NULL) return 1;

    // 1. Vai alla fine del file
    fseek(f, 0, SEEK_END);
    
    // 2. Torna indietro di 256 byte (stima della lunghezza massima di una riga)
    // Nota: Se la riga è più lunga, aumenta questo valore
    fseek(f, -256, SEEK_CUR);

    char buffer[256];
    char ultima_riga[256] = "";

    // 3. Leggi la parte finale e conserva l'ultimo frammento
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        snprintf(ultima_riga, sizeof(ultima_riga), "%s", buffer);
    }

    fclose(f);
    printf("L'ultima riga estratta dal fondo e': %s", ultima_riga);
    return 0;
}
