#include <stdio.h>
#include <stdlib.h>
#include "../primitivas_arbol.h"

int comparar_enteros(const void * dato1,const void * dato2);
void imprimir_dato(const void*);


int main()
{
    int valores[]={50,40,20,1,25,45,43,60,55,51,90,80,105};
    int i,ce = 13;

    t_arbol arbol;
    crear_arbol(&arbol);

    for(i=0;i<ce;i++)
        insertar_en_arbol_bin(&arbol,&valores[i],comparar_enteros);

    puts("\n\n en orden: \n\n");

    recorrer_arbol_enorden(&arbol,imprimir_dato);

    puts("\n\n en posorden: \n\n");

    recorrer_arbol_posorden(&arbol,imprimir_dato);

    puts("\n\n en preorden: \n\n");

    recorrer_arbol_preorden(&arbol,imprimir_dato);

    ////////vaciar arbol/////////

//    puts("\n\n vaciar arbol\n\n");
//
//    vaciar_arbol(&arbol);
//
//    puts("\n\n en orden: \n\n");
//
//    recorrer_arbol_enorden(&arbol,imprimir_dato);

    //////////// altura del arbol ////////////

    printf("\n\nLa altura del arbol es: %d\n\n",altura_arbol(&arbol));

    ///////////podar arbol//////////

//    podar_arbol(&arbol,2);
//
//    recorrer_arbol_enorden(&arbol,imprimir_dato);





}


int comparar_enteros(const void * dato1,const void * dato2)
{
    int *e1 = (int*)dato1;
    int *e2 = (int*)dato2;

    return *e1 - *e2;
}

void imprimir_dato(const void* dato)
{
    int * entero = (int*)dato;

    printf("%d - ",*entero);
}
