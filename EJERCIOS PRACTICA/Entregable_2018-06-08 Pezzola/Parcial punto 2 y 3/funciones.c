#include "funciones.h"

int suma_matris_triangulo_der(int mat[MAX][MAX],int f, int col)
{
    int k,i,j, suma = 0;

// NO INCLUIDAS LAS DIAGONALES
    for(k=1,j=col-1;j>col/2;k++,j--)
        for(i=k;i<j;i++)
        {
            suma+=mat[i][j];
            printf("%d +",mat[i][j]);
        }


// INCLUIDAS LAS DIAGONALES
//    for(k=1,j=col-1;j>=col/2;k++,j--)
//        for(i=k;i<=j;i++)
//        {
//            suma+=mat[i][j];
//            printf("%d +",mat[i][j]);
//        }

    return suma;
}
