#ifndef PRIMITIVAS_ARBOL_H_INCLUDED
#define PRIMITIVAS_ARBOL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>


typedef int t_dato;

typedef  int(*t_cmp)(const void*, const void*);
typedef  void(*t_accion)(const void*);

typedef struct snodo_ar
{
    t_dato info;
    struct snodo_ar *hizq;
    struct snodo_ar *hder;
}t_nodo_ar;

typedef t_nodo_ar* t_arbol;

void crear_arbol(t_arbol * pa);

int insertar_en_arbol_bin(t_arbol * pa,const t_dato *pd,t_cmp cmp);
void recorrer_arbol_enorden(const t_arbol * pa,t_accion accion);
void recorrer_arbol_posorden(const t_arbol * pa,t_accion accion);
void recorrer_arbol_preorden(const t_arbol * pa,t_accion accion);
void vaciar_arbol(t_arbol *pa);
void podar_arbol_desde_nivel(t_arbol *pa,int nivel);
int altura_arbol(const t_arbol *pa);

int eliminar_de_arbol(t_arbol *pa , t_dato *pd, t_cmp cmp);
t_nodo_ar ** buscar_nodo(t_arbol * pa, t_dato *pd, t_cmp cmp);
void eliminar_nodo_ar(t_nodo_ar** pnae);
t_nodo_ar ** menor(t_arbol *pa);
t_nodo_ar ** mayor(t_arbol *pa);


///Desarrolar :

int tipo_arbol(const t_arbol *pa);
int es_arbol_avl(const t_arbol * pa);
int es_arbol_completo(const t_arbol * pa);
int es_arbol_completo_hasta_nivel(const t_arbol * pa,int nivel);
int es_arbol_balanceado(const t_arbol * pa);
int insertar_Arbol_Balanceado_desdeArchBin(t_arbol *pa,FILE * arch,t_cmp cmp);
int contar_nodo_arbol(const t_arbol *pa);







#endif // PRIMITIVAS_ARBOL_H_INCLUDED
