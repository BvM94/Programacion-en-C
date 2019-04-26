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



#endif // FUNCIONES_VECTORES_H_INCLUDED
