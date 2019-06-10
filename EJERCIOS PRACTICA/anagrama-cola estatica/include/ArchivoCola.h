#ifndef ARCHIVOCOLA_H
#define ARCHIVOCOLA_H

#include <stdio.h>


typedef struct
{
	char cod_art[7];
	char cod_mat_pri[7];
	int cantidad;
	float costo_unit;
}
t_mat_prima_art;


void procesar_arch_productos(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000);
void procesar_arch_productos_res(FILE* arch_prod, FILE* arch_prod_mas_1000, FILE* arch_prod_menos_1000);
void generar_archivo_productos();


#endif // ARCHIVOCOLA_H
