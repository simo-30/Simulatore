#include <stdio.h>
#include <stddef.h>
#include "../Punto/punto.h"

typedef enum {
	TIPO_INT
} TipoCampo;

typedef struct {
    const char *nome;
    TipoCampo tipo;
    size_t offset;
} DescrizioneCampo;

#define DescrizioneCampo CampiPunto[] = {
	{"id", TIPO_INT, offsetof(Punto, id)},
	{"x", TIPO_INT, offsetof(Punto, x)},
	{"y", TIPO_INT, offsetof(Punto, y)},
	{"z", TIPO_INT, offsetof(Punto, z)}
};
