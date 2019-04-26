#include <stdio.h>
#include <stdlib.h>
#include "../funciones_matrices.h"


int main()
{
    int mat[MAX][MAX] = {{1,2,3},{4,5,6},{7,8,9}};
    int mat2[MAX][MAX] = {{00,01,02,03,04,05},{10,11,12,13,14,15},{20,21,22,23,24,25},{30,31,32,33,34,35}};


    print_matriz(mat,3,3);
    puts("\n\n");
    espejar_horizontal(3,3,mat);

    print_matriz(mat,3,3);
    puts("\n\n");
    print_matriz(mat2,4,5);
    puts("\n\n");
    espejar_horizontal(4,5,mat2);

    print_matriz(mat2,4,5);

    return 0;
}
