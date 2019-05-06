#include <stdio.h>
#include <stdlib.h>
#include "../my_string.h"

int main()
{
    char numStr[45]="-6666";
    int numInt=-4;
    int base= 2;
    char numStr2[45];
 //   ingresar_num_txt(numStr);

//    if(!es_numero(numStr))
//    {
//        puts("La cadena ingresada no es un numero");
//        return 1;
//    }

//    printf("%s\n\n",numStr);
//    printf("%d\n\n",mi_atoi(numStr));
//
//
//
//
////    int num=mi_atoi(numStr);
////    printf("El numero es %d\n,num");
//
//    printf("%d de base 10 a base %d = %s\n\n  ",numInt , base , mi_itoa(numInt,numStr2,base));
//
//    //printf("Entero: %d ---- String: %s",numInt, mi_itoa(numInt,numStr2));
//
//
//    ////////////////////////////////////////////////////////////////////////////////
//    //NORMALIZAR
//    char frase[]={"hOLA.-+*QUE/  tAl?.;-+/"};
//    char frasemodificada[50];
//
//    //sec->act = (char*)cadorig;
//
//    printf("frase orginal : %s\n\n",frase);
//
//    normalizar(frase,frasemodificada);
//
//    printf("frase modificada : %s\n\n",frasemodificada);

    //HOLA Que Tal\0
    /////////////////////////////////////////////////////////////////////////////

//    char cad[]="Hola";
//    int cant_chars;
//
//    cant_chars=mi_strlen(cad);
//
//    printf("%d",cant_chars);
//    printf("%d",mi_strlen(cad));
//    printf("%d",mi_strlen("Adios"));

    /////////////////////////////////////////////////////////////////////////////

    char cad1[]="hola como estas?";
    char cad2[20];

    mi_strcat(cad2,cad1);

    printf("%s\n\n",cad1);
    printf("%s\n\n",cad2);




    return 0;
}


