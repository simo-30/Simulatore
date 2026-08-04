#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * definisco struttura dati per la gestione degli id
 **/

typedef struct {
	unsigned int number;
	char letter[5];
} ID;

typedef struct ID_Usato{
	ID id_used;
	struct ID_Usato *next_id;
} ID_Usato;

typedef struct {
	unsigned int count;
	ID_Usato *first_id_used;
} List_Used_ID;

List_Used_ID *init_list_used_id(); //inizializza lista degli id

int id_in_uso(ID try_new_id, List_Used_ID *list_id); //verifica se l'id è già presente nella lista
ID genera_nuovo_id(List_Used_ID *list_id); //genera un nuovo id disponibile
void stampa_id(ID id, char *buffer, size_t dimensione);
