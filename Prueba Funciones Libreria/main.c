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

//char s1[11] = "Hola ";
//char s2[6] = "amigos";
//printf( "s1=%s\t", s1 );
//printf( "s2=%s\n", s2 );
//mi_strcat( s1, s2 );
//printf( "s1=%s\n", s1 );

//////////////////////////////////////////////////////////////////////////////////

    char s2[8] = "abcdefg";
    char s1[8];
    mi_strcpy( s1, s2 );
   // strcpy( s1, s2 );
    printf( "s2=%s\n", s2 );
    printf( "s1=%s\n", s1 );



    return 0;
}


