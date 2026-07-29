#include <stdio.h>
#include <stdlib.h>
#include "../Database/sqlite3.h"
#include "../Database/database.h"
#include "punto.h"

Punto crea_punto (sqlite3 *db, int x, int y, int z) {
	Punto p;
	
	p.x=x;
	p.y=y;
	p.z=z;
	
	return p;
}
