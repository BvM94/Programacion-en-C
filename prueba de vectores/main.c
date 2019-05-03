#include <stdio.h>
#include <stdlib.h>
#include "../funciones_vectores.h"
#define TAM 20;
int main()
{
    int tam=5;
    int ce=0;
    int vInt[5]; //={3,6,8,11,13};
    int valor=10;

    int tam2=10;
    int vInt2[]={1,3,3,4,4,5,8,8,4,8};
    int ce2=0;
    int valor2=10;

    int i;
///////////////////////////////////////////////////////////////////////////////////////
//    puts("vector original\n\n");
//    printf("insertar valor %d\n\n",valor);
//    for(i=0;i<ce;i++)
//        printf("%d-",vInt[i]);
//
//    vec_insertar_ordenado(vInt,&ce,&tam,&valor) ? puts("\n\nSI"):puts("\n\nNO");
//
//    puts("\n\n vector modificado\n\n");
//
//    for(i=0;i<ce;i++)
//        printf("%d-",vInt[i]);
//
//    printf("\n\n %d control de overflow Y cantidad de elementos %d\n\n",vInt[tam],ce);
//
//        puts("vector original\n\n");
//    printf("insertar valor %d\n\n",valor);
//    for(i=0;i<ce;i++)
//        printf("%d-",vInt[i]);
//
//    vec_insertar_ordenado(vInt,&ce,&tam,&valor) ? puts("\n\nSI"):puts("\n\nNO");
//
//    puts("\n\n vector modificado\n\n");
//
//    for(i=0;i<ce;i++)
//        printf("%d-",vInt[i]);
//
//    printf("\n\n %d control de overflow Y cantidad de elementos %d\n\n",vInt[tam],ce);

/////////////////////////////////////////////////////////////////////////////////////////////////

    for(i=0;i<ce2;i++)
        printf("%d-",vInt2[i]);

    puts("\n\n");
    printf("%d\n\n",ce2);

    //vec_eliminar_primer_aparicion(vInt2,&ce2,&tam2,&valor2);

    vec_eliminar_ocurrencias(vInt2,&ce2,&tam2,&valor2);

    for(i=0;i<ce2;i++)
        printf("%d-",vInt2[i]);

    puts("\n\n");
    printf("%d\n\n",ce2);

}
