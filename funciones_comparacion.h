#ifndef FUNCIONES_COMPARACION_H_INCLUDED
#define FUNCIONES_COMPARACION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char AyN[50];
    int dni;
}t_alumno;

int comparar_alumnos_apellidos(const void * alu1,const void* alu2);



#endif // FUNCIONES_COMPARACION_H_INCLUDED
