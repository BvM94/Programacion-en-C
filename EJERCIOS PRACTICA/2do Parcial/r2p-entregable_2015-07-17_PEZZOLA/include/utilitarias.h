#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<arbol.h>

int alta_res (int dni, t_arbol* pa);
int alta (int dni, t_arbol* pa);

int baja_res (int dni, t_arbol* pa);
int baja (int dni, t_arbol* pa);

void ingresar_alumno(t_alumno* alu, int dni); ///Completa la carga del alumno (debe estar ya seteado el dni)
void ingresar_dni_alumno(t_alumno* alu); ///Ingresa el dni para el alumno

void imprimir_alumno(t_alumno* alu,void* datos);
void imprimir_alumno_res(t_alumno* alu,void* datos);

void mostrar_dni(const t_alumno* r);

void imprimir_listado_res(const t_arbol *pa);
void imprimir_listado(const t_arbol *pa);

void validar_arbol_res(const t_arbol *pa);///Imprime si el arbol es completo, balanceado, AVL o ninguna
void validar_arbol(const t_arbol *pa);
#endif // UTILITARIAS_H_INCLUDED
