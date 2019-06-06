#include <stdio.h>
#include <stdlib.h>
#include <Lista.h>
#include <Utilitarias1erPAlumnos.h>


int main()
{
    generarArchivo();

    FILE* archAlumnos = fopen("Notas.dat", "rb");

    if(!archAlumnos)
    {
        puts("No se pudo abrir el archivo.");
        return 1;
    }

    t_lista listaAlumnos;

    crear_lista_res(&listaAlumnos);

    cargarLista(&listaAlumnos, archAlumnos);

    puts("Lista antes de procesar:");
    recorrer_lista_res(&listaAlumnos, mostrar_nota, NULL);

    procesar_lista(&listaAlumnos);
    //procesar_lista_res(&listaAlumnos);

    puts("\nLista despues de procesar:");
    recorrer_lista_res(&listaAlumnos, mostrar_nota, NULL);


    return 0;
}


void procesar_lista(t_lista* pl)
{
    ///Inserte el código acá...

   // t_lista* pl=pLAlu;
    t_dato_lista dato;
    t_lista listaIni = *pl;

    while(*pl)
    {
        if(0==lista_sacar_por_clave(&(*pl)->psig,&dato,&(*pl)->info,comparar_dniYmateria))
            actualizar_nota(&(*pl)->info,&dato);

        pl=&(*pl)->psig;
    }

    //lista_ordenar_asc(&listaIni,comparar_nota);
}
