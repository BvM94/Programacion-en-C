#ifndef FUNCIONES_VECTORES_H_INCLUDED
#define FUNCIONES_VECTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TODO_OK 1
#define ERROR 0

// ce: indica la primer posicion  libre del vector.

int vec_insertar_ordenado(int* vec,int* ce,const int* tam,const int *valor);
int vec_eliminar_primer_aparicion(int* vec, int* ce, const int* tam,const int* valor);
int vec_eliminar_ocurrencias(int* vec, int* ce, const int* tam,const int* valor);

//ordenamiento

void orden_por_Seleccion_Ascendente(int * vec, int* ce);
void intercambio_ints(int* a, int* b);
int* buscar_menor(int* d, int* h);


#endif // FUNCIONES_VECTORES_H_INCLUDED
