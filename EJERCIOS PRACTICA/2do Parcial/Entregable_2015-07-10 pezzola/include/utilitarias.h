#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<arbol.h>

typedef struct{
    int dni;
    char apyn[40];
    int cant_materias;
    float promedio;
    char estado; ///'A' Activo - 'B' Baja
}t_alumno;

int comparar_ind(const t_info* d1, const t_info* d2);
void imprimir_indice(const t_info* pinfo);
void crear_archivo_indice();

int alta_res (t_alumno * alu, FILE * arch, t_arbol* pa);
int alta (t_alumno * alu, FILE * arch, t_arbol* pa);

int baja_res (t_alumno * alu, FILE * arch, t_arbol* pa);
int baja (t_alumno * alu, FILE * arch, t_arbol* pa);

void ingresar_alumno(t_alumno* alu);
void ingresar_dni_alumno(t_alumno* alu);
void imprimir_alumno(const t_alumno* alu);
void mostrar_dni(const t_reg_ind* r);
void imprimir_archivo(FILE * arch);

#endif // UTILITARIAS_H_INCLUDED
