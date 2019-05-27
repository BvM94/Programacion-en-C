
#include "../include/utilitarias.h"

int comparar_alumnos_dni(const t_info* alumno1,const t_info* alumno2)
{
    if(alumno1->dni - alumno2->dni > 0)
        return 1;
    if(alumno1->dni - alumno2->dni < 0)
        return -1;
    return 0;
}

int comparar_alumnos_nombreYdni(const t_info* alumno1,const t_info* alumno2)
{
    if(strcmp(alumno1->apyn,alumno2->apyn)>0)
        return 1;

    if(strcmp(alumno1->apyn,alumno2->apyn)<0)
        return -1;

    return alumno1->dni - alumno2->dni;
}

void cargar_acta(t_acta* acta,const t_nota* nota)
{
    if(strcmp(nota->tipo,"P1")==0)
        acta->p1 = nota->nota;

    else if(strcmp(nota->tipo,"P2")==0)
                acta->p2 = nota->nota;

        else if(strcmp(nota->tipo,"R1")==0)
                    acta->r1 = nota->nota;

            else if(strcmp(nota->tipo,"R2")==0)
                        acta->r2 = nota->nota;
}
