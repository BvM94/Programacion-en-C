#include "../include/Utilitarias.h"

int cmp_alu(const void* pva1, const void* pva2)
{
    t_alumno * a1 = (t_alumno*) pva1;
    t_alumno * a2 = (t_alumno*) pva2;

    return a1->dni - a2->dni;
}

void imprimir_alumno(void* pvd, void* datos_accion)
{
    t_alumno* alu = (t_alumno*)pvd;

    printf("DNI: %d - Nom y Ape : %s - Nota1: %d - Nota2: %d - Nota TP: %c \n\n",
           alu->dni,alu->apyn,alu->nota_1p,alu->nota_2p,alu->nota_tp);
}

void acc_insertar_l(void* pvd, void* pvl)
{
    t_alumno* alu = (t_alumno*)pvd;
    t_lista * pl = (t_lista*)pvl;

    if(alu->nota_1p >=4 && alu->nota_2p>= 4 && alu->nota_tp == 'A')
        insertar_en_lista_ord(pl,alu,cmp_alu);
}

void acc_eliminar_de_arbol(void* pvd, void* pva)
{
    t_alumno* alu = (t_alumno*)pvd;
    t_arbol * pa = (t_arbol*)pva;

    eliminar_de_arbol_res(pa,alu,cmp_alu);
}
