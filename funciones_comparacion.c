#include "funciones_comparacion.h"

int comparar_alumnos_apellidos(const void * alu1,const void* alu2)
{
    t_alumno* a1 = (t_alumno*)alu1;
    t_alumno* a2 = (t_alumno*)alu2;

    return strcmp((a1->AyN),(a2->AyN));
}
