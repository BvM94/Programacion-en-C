#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include<tipos.h>
#define SIN_MEMO 0
#define OK 1
#define LISTA_LLENA 2
#define LISTA_VACIA 3
#define NO_EXISTE 4
#define DUPLICADO 5
#define ACTUALIZADO 6

typedef struct s_nodo{
    t_info info;
    struct s_nodo * psig;
}t_nodo;



typedef t_nodo * t_lista;

int cmp_apyn(const t_info *v1,const t_info *v2);

void crear_lista_res(t_lista * plista);

void crear_lista(t_lista * plista);

int lista_llena_res(const t_lista * plista);

int lista_llena(const t_lista * plista);

int lista_vacia_res(const t_lista * plista);

int lista_vacia(const t_lista * plista);

int insertar_lista_res(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*));

int insertar_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*));

int actualizar_lista_res(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*), void(*act)(t_info *, const t_info*));

int actualizar_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*), void(*act)(t_info *, const t_info*));

int sacar_primero_lista_res(t_lista * plista, t_info * pinfo);

int sacar_primero_lista(t_lista * plista, t_info * pinfo);


void recorrer_lista_res(const t_lista * plista, void (*acc)(t_info*, void*), void* param);

void recorrer_lista(const t_lista * plista, void (*acc)(t_info*, void*), void* param);

void vaciar_lista_res(t_lista * plista);

void vaciar_lista(t_lista * plista);

int sacar_menor_lista (t_lista * plista, t_info* pinfo, int (*comp)(const t_info *, const t_info*) );

t_nodo* buscar_menor(t_lista* plista,int (*comp)(const t_info *, const t_info*));

#endif // LISTA_H_INCLUDED
