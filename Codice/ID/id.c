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
		if (strcmp(str_try_id, str_curr_id) != 0) {
			printf("ID disponibile\n");
			exist_id = 1;
			return exist_id;
		}		
		current_id = current_id ->next_id;
	}
	
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
	
	while (current_id != NULL) {
		/*
		 * in questo ciclo 
		 */
		current_id = current_id->next_id;
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
