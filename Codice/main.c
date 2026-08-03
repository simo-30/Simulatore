#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Punto/punto.h"
#include "Archivio/archivio.h"


int main(){
	srand(time(NULL));
	
	Header_List_Punto h = init_header_list_punto();
	Punto p1 =crea_punto_random(&h);
	Item_List_Punto lp = init_item_list_punto(p1);
	stampa_punto(p1);
	
	append_item_punto(&h, &lp);
	
	p1 = crea_punto_random(&h);
	lp = init_item_list_punto(p1);
	append_item_punto(&h, &lp);
	
	stampa_punto(p1);
	
	printf("%d\n", h.count);
		
	return 0;
}

