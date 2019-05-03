#ifndef FUNCIONES_VECTORES_H_INCLUDED
#define FUNCIONES_VECTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define ERROR 0

typedef int (*t_cmp)(const void*, const void*); // int tipo de retorno de la funcion, (*t_cmp) puntero a la funcion , ultimo estructura de la funcion que apunta

// ce: indica la primer posicion  libre del vector.

int vec_insertar_ordenado(int* vec,int* ce,const int* tam,const int *valor);
int vec_eliminar_primer_aparicion(int* vec, int* ce, const int* tam,const int* valor);
int vec_eliminar_ocurrencias(int* vec, int* ce, const int* tam,const int* valor);

//ordenamiento

void orden_por_Seleccion_Ascendente(int * vec, int* ce);
void intercambio_ints(int* a, int* b);
int* buscar_menor(int* d, int* h); // busca es menor entre dos direcciones de memoria

//ordenamiento generico

void orden_seleccion_asc_generico(void* v, int* ce,size_t tamElem); // ordenamiento generica
int intercambiar_elementos(void *a , void*b, size_t tamElem);
void* buscar_menor_generica(void* d, void* h, size_t tamElem,t_cmp comparar);



#endif // FUNCIONES_VECTORES_H_INCLUDED
