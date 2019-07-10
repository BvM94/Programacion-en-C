#ifndef LISTAD_FUNCIONES_H_INCLUDED
#define LISTAD_FUNCIONES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "arbol_funciones.h"

typedef struct s_nodoD
{
    t_dato info;
    struct s_nodoD *psig,*pant;
}t_nodoD;

typedef t_nodoD * t_lista;

void crear_lista(t_lista *pl);
int insertar_lista_desordenada(t_lista *pl,const t_dato *pd);
int insertar_lista_ordenadaASC(t_lista *pl,const t_dato *pd, t_cmp cmp);
int eliminar_lista_ordenadaASC(t_lista *pl,t_dato *pd, t_cmp cmp);
void vaciar_lista(t_lista *pl);
void ordenar_lista_ASC(t_lista *pl,t_cmp cmp);
void eliminar_apuntado_por_pl(t_lista *pl,t_dato *pd);
int buscar_lista_ordenada(t_lista *pl,t_dato *pd,t_cmp cmp);
void eliminar_duplicado(t_lista *pl, t_cmp cmp);


void mostrar_lista(const t_lista *pl);

#endif // LISTAD_FUNCIONES_H_INCLUDED
