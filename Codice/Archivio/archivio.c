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

int write_file_archivio_punti(Header_List_Punto h) {
	const char *path_file=PATH_ARCHIVIO_PUNTI;
	FILE *file = fopen(path_file, "w");
	
	if (file == NULL) {
		printf("Errore nell'apertura del file %s\n", PATH_ARCHIVIO_PUNTI);
		return 1;
	}
	printf("File %s aperto correttamente\n", PATH_ARCHIVIO_PUNTI);
	
	fprintf(file, "id|x|y|z\n");
	
	Item_List_Punto *lp = h.first_p;
	int i;
	
	for (i=0; i<h.count; i++) {
		fprintf(file, "%d|%d|%d|%d\n", lp->p.id, lp->p.x, lp->p.y, lp->p.z);
		printf("%d\n", lp->p.id);
		lp = lp->next_p;
	}
	
	fclose(file);
	return 0;
}

Header_List_Punto leggi_file_archivio_punti() {
	Header_List_Punto hp = init_header_list_punto();
	
	FILE *file = fopen(PATH_ARCHIVIO_PUNTI, "r");
	if (file == NULL) {
		printf("Errore nell'apertura del file %s\n", PATH_ARCHIVIO_PUNTI);
		return hp;
	}
	
	char header_line[256];
	fgets(header_line, sizeof(header_line), file);
	
	Punto p;
	while (fscanf(file, "%d|%d|%d|%d\n", &p.id, &p.x, &p.y, &p.z) == 4) {
		Item_List_Punto *ip = init_item_list_punto(p);
		append_item_punto(&hp, ip);
	}
	
	fclose(file);
	return hp;
}
