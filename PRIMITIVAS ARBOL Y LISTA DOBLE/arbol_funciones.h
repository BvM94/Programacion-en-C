#ifndef ARBOL_FUNCIONES_H_INCLUDED
#define ARBOL_FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef int t_dato;
typedef int(*t_cmp)(const void *d1, const void *d2);
typedef void(*t_accion)(const void *d1);

typedef struct s_nodo_ar
{
    t_dato info;
    struct s_nodo_ar *hizq ,*hder;
}t_nodo_ar;
typedef t_nodo_ar * t_arbol;

void crear_arbol(t_arbol * pa);
int insertar_en_arbol_ordenado(t_arbol * pa, t_dato *pd,t_cmp cmp);
int Cargar_arbolBalanceado_desdeArchOrden(t_arbol * pa , FILE * arch,t_cmp cmp);
int insertar_balanceado(t_arbol *pa , FILE* arch , int i,int d,t_cmp cmp);
int eliminar_de_arbol(t_arbol * pa , t_dato *pd , t_cmp cmp);
void eliminar_nodo(t_nodo_ar ** pnae);
t_nodo_ar** buscar_nae(t_arbol *pa,t_dato *pd,t_cmp cmp);
t_nodo_ar ** menor(t_arbol *pa);
t_nodo_ar ** mayor(t_arbol *pa);
int altura_del_arbol (const t_arbol * pa);
int arbol_completo (const t_arbol *pa);
int arbol_avl (const t_arbol *pa);
int arbol_balanceado (const t_arbol *pa);
int tipo_deArbol(const t_arbol *pa);
int arbol_completo_hasta_nivel(const t_arbol * pa, int nivel);
void podar_arbol_desde_nivel(t_arbol *pa, int nivel);
void podar_arbol_hasta_nivel(t_arbol *pa, int nivel);
void vaciar_arbol (t_arbol *pa);
void recorrer_preorden(t_arbol *pa, t_accion accion,t_dato dato_accion);
void recorrer_Enorden(t_arbol *pa, t_accion accion,t_dato dato_accion);
void recorrer_posorden(t_arbol *pa, t_accion accion,t_dato dato_accion);
void buscar_mayor_arbol_NO_clave(const t_arbol *pa,t_dato *pd ,t_cmp cmp);
void buscar_mayor_sin_clave(const t_arbol *pa,t_dato *pd,t_cmp cmp);
int cantidad_hojas_del_arbol(const t_arbol *pa);

#endif // ARBOL_FUNCIONES_H_INCLUDED
