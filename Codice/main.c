#include <stdio.h>
#include <stdlib.h>
#include "Punto/punto.h"
#include "Archivio/archivio.h"

int main(){
    if(esiste_file(PATH_ARCHIVIO_PUNTI)) {
		printf("Esiste il file %s\n", PATH_ARCHIVIO_PUNTI);
	}
	else {
		printf("NON esiste il file %s\n", PATH_ARCHIVIO_PUNTI);
		crea_file_archivio(PATH_ARCHIVIO_PUNTI);
	}
	
	get_id_punto();
	
	return 0;
}

