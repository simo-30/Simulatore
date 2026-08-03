#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Punto/punto.h"

//
//	struttura dei file in cui saranno salvati i dati:
//	<header1>|<header2>
//	<valore1>|<valore2>
//

#define PATH_ARCHIVIO_PUNTI "Archivio/punti.txt"
#define CHAR_SEPARATORE "|"

bool esiste_file(const char *path_file);

int crea_file_archivio(const char *path_file);

int insert_punto_into_archivio(Punto p);
