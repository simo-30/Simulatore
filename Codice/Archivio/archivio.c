#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
    if (f == NULL) return -1;
	
	char riga[256];
	char c_id[256]="";

    while (fgets(riga, sizeof(riga), f) != NULL) {
        for (int i = 0; riga[i] != '\0'; i++) {
			if (riga[i] == '|') {
				c_id[i]='\0';
				break;
			}
			c_id[i]=riga[i];
        }
    }

    fclose(f);
    
    int id = atoi(c_id);
    printf("Trovato id = %d\n", id);

    return id;
}
