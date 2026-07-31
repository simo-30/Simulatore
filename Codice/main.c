#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Punto/punto.h"
#include "Archivio/archivio.h"


int main(){
	/*
    if(esiste_file(PATH_ARCHIVIO_PUNTI)) {
		printf("Esiste il file %s\n", PATH_ARCHIVIO_PUNTI);
	}
	else {
		printf("NON esiste il file %s\n", PATH_ARCHIVIO_PUNTI);
		crea_file_archivio(PATH_ARCHIVIO_PUNTI);
	}
	*/
	srand(time(NULL));
	
	Punto p = crea_punto(1,2,3);
	Punto p1 = crea_punto_random();
	
	stampa_punto(p);
	stampa_punto(p1);
	
	Header_List_Punto h = init_header_list_punto();
	printf("%d\n", h.count);
	
	Item_List_Punto item_p = init_item_list_punto(p1);
	stampa_punto(item_p.p);
	
	stampa_punto(init_item_list_punto(crea_punto_random()).p);
	printf("\n\n");
	stampa_punto(somma_punti(crea_punto_random(), p1));
	
	init_first_item(&h);
	append_item_punto(&h, &item_p);
	
	stampa_punto(h.first_p->p);
	printf("%d\n", h.count);
	
	return 0;
}

