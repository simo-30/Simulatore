#include <stdio.h>
#include <stdlib.h>

#pragma once

typedef struct {
	int id;
	int x;
	int y;
	int z;
} Punto;

Punto crea_punto (int x, int y, int z); /*crea una variabile punto con precisi valori di x,y,z ed usando un valore incrementale dell'id dalla relativa tabella a DB*/

Punto crea_punto_random (); /*crea una variabile punto con valori random di x,y,z ed usando un valore incrementale dell'id dalla relativa tabella a DB*/
