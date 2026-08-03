#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Punto/punto.h"
#include "Archivio/archivio.h"


int main(){
	srand(time(NULL));
	
	Header_List_Punto h = init_header_list_punto();
	Punto p1 =crea_punto_random(&h);
	Item_List_Punto *lp = init_item_list_punto(p1);
	stampa_punto(p1);
	
	append_item_punto(&h, lp);
	
	Punto p2 = crea_punto_random(&h);
	Item_List_Punto *lp2 = init_item_list_punto(p2);
	append_item_punto(&h, lp2);
	
	stampa_punto(p2);
	
	
	if (esiste_file(PATH_ARCHIVIO_PUNTI)) {
		printf("Il file %s esiste\n", PATH_ARCHIVIO_PUNTI);
	}
	else {
		crea_file_archivio(PATH_ARCHIVIO_PUNTI);
	}
	
	Punto p3 = crea_punto_random(&h);
	Item_List_Punto *lp3 = init_item_list_punto(p3);
	append_item_punto(&h, lp3);
	
	write_file_archivio_punti(h);
	
	Header_List_Punto h2 = leggi_file_archivio_punti();
	return 0;
}

