#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "id.h"

ID genera_nuovo_id(List_Used_ID *list_id) {
	ID new_id;
	ID_Usato *current_id;
	
	if (list_id == NULL) {
		//inizializzo la listo
	}
	else {
		current_id = list_id->first_id_used;
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
