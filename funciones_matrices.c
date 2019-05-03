#include "funciones_matrices.h"


void print_matriz(int mat[MAX][MAX],int f,int c)
{
    int i,j;

    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d-",mat[i][j]);
        }
        puts("\n");
    }
}

int espejar_horizontal(int f,int c, int mat[MAX][MAX])
{
    int i,j;
    int f_max = f - 1;
    int aux;
    for(i=0; i<f_max; i++)
    {
        for(j=0; j<c; j++)
        {
            aux = mat[i][j];
            mat[i][j] = mat[f_max][j];
            mat[f_max][j] = aux;
        }
        f_max--;
    }
    return 0;
}


int suma_trig_sup_sinPrincipal(int fil,int col,int mat[MAX][MAX])
{
    int i,j;
    int suma=0;
    for (i=0; i<fil-1; i++)
        for(j=1; j<col; j++)
            suma+=mat[i][j];

    return suma;
}

void mostrar_diagonal_principal(int fil, int col, int mat[MAX][MAX])
{

    int i,k;

    for (i=0,k=1; i<fil; i++,k+=2)
        printf("%*d\n",k,mat[i][i]);

}

void mostrar_triag_sup_conDiagPrincipal(int fil, int col, int mat[MAX][MAX])
{

    int i,k=5,j;

    for (i=0; i<fil; i++)
    {
        for(j=i; j<col; j++)
            printf("%*d",k,mat[i][j]);
        printf("\n%*c",k+k*i,' ');
    }
}

void mostrar_triag_sup_SinDiagPrincipal(int fil, int col, int mat[MAX][MAX])
{

    int i,k=5,j;

    for (i=0; i<fil; i++)
    {
        for(j=i+1; j<col; j++)
            printf("%*d",k,mat[i][j]);
        printf("\n%*c",k+k*i,' ');
    }
}
