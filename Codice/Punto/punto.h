#include <stdio.h>
#include <stdlib.h>
#include "../Database/sqlite3.h"
#include "../Database/database.h"

typedef struct {
	int id;
	int x;
	int y;
	int z;
} Punto;

Punto crea_punto (sqlite3 *db, int x, int y, int z); /*crea una variabile punto con precisi valori di x,y,z ed usando un valore incrementale dell'id dalla relativa tabella a DB*/

Punto crea_punto_random (sqlite3 *db); /*crea una variabile punto con valori random di x,y,z ed usando un valore incrementale dell'id dalla relativa tabella a DB*/
