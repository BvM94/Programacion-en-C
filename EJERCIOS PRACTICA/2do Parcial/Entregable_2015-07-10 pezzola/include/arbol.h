#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <Tipos.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_nodo
{
	t_info info; /** El tipo definido en Dato.h **/
	struct s_nodo* pizq;
	struct s_nodo* pder;
}
t_nodo_arbol;


typedef t_nodo_arbol* t_arbol;

typedef int (*t_cmp)(const t_info*, const t_info*);

typedef void (*t_accion)(t_info* pinfo, void* datos_accion);

typedef void (*t_mostrar_clave)(const t_info *);


int insertar_arbol_balanceado(t_arbol *pa,FILE * arch, int i , int d , t_cmp cmp);
int es_arbol_balanceado(const t_arbol *pa);
int es_completo_hasta_nivel(const t_arbol *pa , int nivel);
int altura_arbol_mia(const t_arbol* pa);
t_nodo_arbol ** buscar_nae(const t_arbol *pa,t_info *pd,t_cmp cmp);
void eliminar_nodo(t_nodo_arbol ** pnae);
t_nodo_arbol** menor_mia(t_arbol *pa);
t_nodo_arbol** mayor_mia(t_arbol *pa);
void recorrer_Enorden(const t_arbol *pa,t_accion acc, void * dato_accion);


void crear_arbol(t_arbol* pa);
void crear_arbol_res(t_arbol* pa);
int insertar_en_arbol_bin_busq(t_arbol* pa, const t_info* pd, t_cmp cmp); ///Retorna TODO_OK o DUPLICADO
int insertar_en_arbol_bin_busq_res(t_arbol* pa, const t_info* pd, t_cmp cmp); ///Retorna TODO_OK o DUPLICADO
int buscar_en_arbol_bin_busq(const t_arbol* pa, t_info* pd, t_cmp cmp); ///Retorna VERDADERO o FALSO
int buscar_en_arbol_bin_busq_res(const t_arbol* pa, t_info* pd, t_cmp cmp); ///Retorna VERDADERO o FALSO
int eliminar_de_arbol(t_arbol* pa, t_info* pd, t_cmp cmp); ///Retorna TODO_OK o NO_EXISTE
int eliminar_de_arbol_res(t_arbol* pa, t_info* pd, t_cmp cmp); ///Retorna TODO_OK o NO_EXISTE
void recorrer_arbol_pre(const t_arbol* pa, t_accion accion, void* datos_accion);
void recorrer_arbol_en(const t_arbol* pa, t_accion accion, void* datos_accion);
void recorrer_arbol_pos(const t_arbol* pa, t_accion accion, void* datos_accion);
int cargar_arbol_de_archivo_ordenado(t_arbol* pa, const char* path); ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
int cargar_arbol_de_archivo_ordenado_res(t_arbol* pa, const char* path); ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
int grabar_arbol_en_archivo_ordenado(t_arbol* pa, const char* path);
int grabar_arbol_en_archivo_ordenado_res(t_arbol* pa, const char* path);
int altura_arbol(const t_arbol* pa);
void vaciar_arbol(t_arbol* pa);
t_nodo_arbol** menor(t_arbol* pa);
t_nodo_arbol** mayor(t_arbol* pa);
void arbol_grafico(const t_arbol*, t_mostrar_clave);
void arbol_grafico_mia(const t_arbol*, t_accion);
void mostrar_arbol_grafico(const t_arbol *pa, int despl, t_mostrar_clave);
void mostrar_clave(const t_info* pinfo);


#endif // ARBOL_H_INCLUDED
