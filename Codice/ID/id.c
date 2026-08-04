#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "id.h"

int id_in_uso(ID try_new_id, List_Used_ID *list_id) {
	int exist_id = 0; // 0 = esiste ; 1 = non esiste, quindi disponibile ; 2 = lista non inizializzata ; 3 = lista con zero elementi
	ID_Usato *current_id;
	
	if (list_id == NULL) {
		printf("Lista non inizializzata\n");
		exist_id = 2;
		return exist_id;
	}
	if (list_id->count == 0) {
		printf("Lista con 0 elementi\n");
		exist_id = 3;
		return exist_id;
	}
	
	current_id = list_id->first_id_used;
	char str_try_id[30];
	stampa_id(try_new_id, str_try_id, sizeof(str_try_id));
	
	while (current_id != NULL) {
		char str_curr_id[30];
		stampa_id(current_id->id_used, str_curr_id, sizeof(str_curr_id));
		if (strcmp(str_try_id, str_curr_id) == 0) {
			exist_id = 0;
			printf("ID non disponibile\n");
			return exist_id;
		}		
		current_id = current_id ->next_id;
	}
	printf("ID disponibile\n");
	exist_id = 1;
	
	return exist_id;
}

ID genera_nuovo_id(List_Used_ID *list_id) {
	ID new_id;
	ID_Usato *current_id;
	
	if (list_id == NULL) {
		//inizializzo la lista
	}
	else {
		current_id = list_id->first_id_used;
	}
	
	unsigned int i;
	int used_id;
	
	for (i=0; i<=UINT_MAX; i++) {
		new_id.number=i;
		char new_lett[5];
		int l1, l2, l3, l4, l5;
		for (l1=65; l1<=90; l1++) {
			new_lett[0] = (char)l1;
			for (l2=65; l2<=90; l2++) {
				new_lett[1] = (char)l2;
				for (l3=65; l3<=90; l3++) {
					new_lett[2] = (char)l3;
					for (l4=65; l4<=90; l4++) {
						new_lett[3] = (char)l4;
						for (l5=65; l5<=90; l5++) {
							new_lett[4] = (char)l5;
							strcpy(new_id.letter, new_lett);
							used_id = id_in_uso(new_id, list_id);
							switch (used_id) {
								case 0:
									//id già in uso
									break;
								case 1:
									//id libero
									break;
								case 2:
									//lista non inizializzata
									break;
								case 3:
									//lista con zero elementi
									break;
								default :
									printf("caso %d non previsto\n", used_id);
							}
						}
					}
				}
			}
		}
	}
	
	return new_id;
}

void stampa_id(ID id, char *buffer, size_t dimensione) {
    if (buffer == NULL || dimensione == 0) {
        return;
    }

    snprintf(
        buffer,
        dimensione,
        "%s%u",
        id.letter,
        id.number
    );
    return;
}
