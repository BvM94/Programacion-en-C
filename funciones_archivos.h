#ifndef FUNCIONES_ARCHIVOS_H_INCLUDED
#define FUNCIONES_ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones_fechas.h"

#define FALLO 0

typedef struct
{
    char cod[7];
    char descr[51];
    int cant;
    float precio;
}t_producto;

typedef t_producto t_prodVerduleria;

typedef struct
{
    char cod[7];
    int cant;
}t_mov;

typedef struct
{
    int dni;
    char apyn[151];
    char sexo;
    t_fecha fNac;
    float sueldo;
} t_empleado;

void crear_lote_prueba_productos_verduleria();
void crear_lote_prueba_productos_verduleriaMovimientos();

void mostrar_Archiv_prod_verduleria_binario(FILE* pfb);
void mostrar_Archiv_prodMovimiento_verduleria_binario(FILE* pfb);

void actualizar_Productos_verduleria(FILE* pb1,FILE* pb2,FILE*pbfinal);

//int txtVariableABin (char* linea,t_empleado *emp);










#endif // FUNCIONES_ARCHIVOS_H_INCLUDED
