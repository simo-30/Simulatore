#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "punto.h"
#include "../Archivio/archivio.h"

Punto crea_punto (int x, int y, int z) {
	Punto p;
	
	p.id=rand();
	p.x=x;
	p.y=y;
	p.z=z;
	
	return p;
}

Punto crea_punto_random() {
	Punto p;
	p.id=rand();
	p.x=rand();
	p.y=rand();
	p.z=rand();
	
	return p;
}

void stampa_punto(Punto p) {
	printf("Il punto ha le coordinate:\nx = %d\ny = %d\nz = %d\n", p.x, p.y, p.z);
	printf("L'id del punto e':\nid = %d\n", p.id);
}

Header_List_Punto init_header_list_punto() {
	Header_List_Punto h;
	
	h.count=0;
	h.first_p=NULL;
	
	return h;
}

Item_List_Punto init_item_list_punto(Punto p) {
	Item_List_Punto p_item;
	p_item.p= p;
	
	p_item.next_p = NULL;
	
	return p_item;
}

Punto somma_punti(Punto p1, Punto p2) {
	Punto somma;
	somma.id= (p1.id + p2.id)/2;
	somma.x = p1.x + p2.x;
	somma.y = p1.y + p2.y;
	somma.z = p1.z + p2.z;
	
	return somma;
}

void init_first_item(Header_List_Punto *h) {
	h->first_p = malloc(sizeof(Item_List_Punto));
	return;
}

void add_first_punto(Header_List_Punto *h, Item_List_Punto *ip) {
    if (h == NULL || ip == NULL) {
        return;
    }

    ip->next_p = NULL;
    h->first_p = ip;
    h->count = 1;
    
    return;
}

void append_item_punto(Header_List_Punto *h, Item_List_Punto *ip) {
    Item_List_Punto *corrente;

    if (h == NULL || ip == NULL) {
        return;
    }

    ip->next_p = NULL;

    if (h->first_p == NULL) {
        add_first_punto(h, ip);
        return;
    }

    corrente = h->first_p;

    while (corrente->next_p != NULL) {
        corrente = corrente->next_p;
    }

    corrente->next_p = ip;
    h->count++;
    
    return;
}
