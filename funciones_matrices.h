#ifndef FUNCIONES_MATRICES_H_INCLUDED
#define FUNCIONES_MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int espejar_horizontal(int f,int c, int mat[MAX][MAX]);

void print_matriz(int mat[MAX][MAX],int f,int c);

int suma_trig_sup_sinPrincipal(int fil,int col,int mat[MAX][MAX]);

void mostrar_diagonal_principal(int fil, int col, int mat[MAX][MAX]);

void mostrar_triag_sup_conDiagPrincipal(int fil, int col, int mat[MAX][MAX]);


#endif // FUNCIONES_MATRICES_H_INCLUDED
