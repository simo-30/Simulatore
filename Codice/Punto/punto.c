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

void libera_lista_punti(Header_List_Punto *h) {
    Item_List_Punto *corrente;

    if (h == NULL) {
        return;
    }

    corrente = h->first_p;

    while (corrente != NULL) {
        Item_List_Punto *successivo = corrente->next_p;

        free(corrente);
        corrente = successivo;
    }

    h->first_p = NULL;
    h->count = 0;
}

int scrivi_lista_punti_su_file(const Header_List_Punto *h, const char *nome_file) {
    FILE *file;
    const Item_List_Punto *corrente;
    printf("scrivo lista sul file %s\n", nome_file);

    if (h == NULL || nome_file == NULL) {
        return 0;
    }
    
    printf("Apro il file %s\n", nome_file);

    file = fopen(nome_file, "w");

    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 0;
    }

    corrente = h->first_p;

    while (corrente != NULL) {
        int risultato = fprintf(
            file,
            "%d %d %d %d\n",
            corrente->p.id,
            corrente->p.x,
            corrente->p.y,
            corrente->p.z
        );

        if (risultato < 0) {
            perror("Errore durante la scrittura");

            fclose(file);
            return 0;
        }

        corrente = corrente->next_p;
    }

    if (fclose(file) == EOF) {
        perror("Errore durante la chiusura del file");
        return 0;
    }

    return 1;
}

int leggi_lista_punti_da_file(const char *nome_file, Header_List_Punto *h) {
    FILE *file;
    Header_List_Punto nuova_lista;
    int risultato_lettura;

    if (nome_file == NULL || h == NULL) {
        return 0;
    }

    file = fopen(nome_file, "r");

    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 0;
    }

    nuova_lista = init_header_list_punto();

    do {
        Punto p;

        risultato_lettura = fscanf(
            file,
            "%d %d %d %d",
            &p.id,
            &p.x,
            &p.y,
            &p.z
        );

        if (risultato_lettura == 4) {
            Item_List_Punto *nuovo_nodo;

            nuovo_nodo = malloc(sizeof *nuovo_nodo);

            if (nuovo_nodo == NULL) {
                perror("Errore di allocazione");

                fclose(file);
                libera_lista_punti(&nuova_lista);

                return 0;
            }

            *nuovo_nodo = init_item_list_punto(p);

            append_item_punto(
                &nuova_lista,
                nuovo_nodo
            );
        }

    } while (risultato_lettura == 4);

    /*
     * EOF indica che il file è terminato normalmente.
     * Un altro valore indica una riga incompleta o non valida.
     */
    if (risultato_lettura != EOF) {
        fprintf(
            stderr,
            "Errore: formato del file non valido.\n"
        );

        fclose(file);
        libera_lista_punti(&nuova_lista);

        return 0;
    }

    fclose(file);

    /*
     * La lista h deve essere stata inizializzata
     * con init_header_list_punto().
     */
    libera_lista_punti(h);
    *h = nuova_lista;

    return 1;
}
