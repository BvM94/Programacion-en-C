#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int mat [MAX][MAX]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int fil=5;
    int col=5;
    int i,j;

    for(i=0;i<fil;i++)
    {
        for(j=0;j<col;j++)
            printf("%d  ",mat[i][j]);

        puts("\n");
    }

    printf("suma es: %d",suma_matris_triangulo_der(mat,i,j));





}
