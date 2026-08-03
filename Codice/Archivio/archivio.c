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
