#include <stdio.h>
#include <stdlib.h>
#include <biblioteca.h>
#include <utilitarias.h>
#include <string.h>

int main(int argc , char* argv[])
{
//    ../Archivos/libros.dat
//    ../Archivos/nuevo_stock.txt
//    ../Archivos/errores.txt

    FILE* arch_libros, * arch_stock, * arch_err;
    ///-----------------------------EJERCICIO 1-----------------------------///
    printf("\n-----------------------------EJERCICIO 1-----------------------------\n\n");
    crear_archivo_libros();
    crear_archivo_stock();
    printf("\n\n*********LIBROS***********\n");
    mostrar_archivo_libros();
    printf("\n*********FIN LIBROS***********\n\n");
    printf("\n\n*********MOVIMIENTOS STOCK***********\n");
    mostrar_archivo_stock();
    printf("\n*********FIN MOVIMIENTOS STOCK***********\n\n");

    arch_libros = fopen(argv[1], "r+b");
    arch_stock = fopen(argv[2], "rt");
    arch_err = fopen(argv[3], "wb");

    if (!arch_libros || !arch_err || !arch_stock)
    {
        exit(1);
    }

    //actualizar_stock_res(arch_libros,arch_stock, arch_err);
    actualizar_stock(arch_libros,arch_stock, arch_err);

    fclose(arch_libros);
    fclose(arch_stock);
    fclose(arch_err);

    printf("\n\n*********LIBROS ACT***********\n");
    mostrar_archivo_libros();
    printf("\n*********FIN LIBROS ACT***********\n\n");

    printf("\n\n*********ERROR***********\n");
    mostrar_archivo_errores();
    printf("\n*********FIN ERROR***********\n\n");

    ///-----------------------------EJERCICIO 2-----------------------------///
    printf("\n-----------------------------EJERCICIO 2-----------------------------\n\n");

    char s1[13] = "Hola a todos";
    char s2[3] ="to";
    char c = 't';

    printf( "s1=%s\n", s1 );
    printf( "s2=%s\n", s2 );
    printf( "strstr(s1,s2) = %s\n", mi_strstr( s1, s2 ) );


    return 0;
}
