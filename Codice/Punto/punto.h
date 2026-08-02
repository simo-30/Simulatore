#include <stdio.h>
#include <stdlib.h>

#pragma once

typedef struct {
	int id;
	int x;
	int y;
	int z;
} Punto;

typedef struct Item_List_Punto {
    Punto p;
    struct Item_List_Punto *next_p;
} Item_List_Punto;

typedef struct {
	int count;
	Item_List_Punto *first_p;
} Header_List_Punto;


Punto crea_punto (int x, int y, int z); /*crea una variabile punto con precisi valori di x,y,z ed usando un valore incrementale dell'id dalla relativa tabella a DB*/

Punto crea_punto_random (); /*crea una variabile punto con valori random di x,y,z ed usando un valore incrementale dell'id dalla relativa tabella a DB*/

void stampa_punto(Punto p);

Header_List_Punto init_header_list_punto(); //inizializza testa della lista

Item_List_Punto init_item_list_punto(Punto p);

Punto somma_punti (Punto p1, Punto p2);

void init_first_item(Header_List_Punto *h);
void add_first_punto(Header_List_Punto *h, Item_List_Punto *ip);
void append_item_punto(Header_List_Punto *h, Item_List_Punto *ip);

int scrivi_lista_punti_su_file(const Header_List_Punto *h, const char *nome_file);

int leggi_lista_punti_da_file(const char *nome_file, Header_List_Punto *h);

void libera_lista_punti(Header_List_Punto *h);
