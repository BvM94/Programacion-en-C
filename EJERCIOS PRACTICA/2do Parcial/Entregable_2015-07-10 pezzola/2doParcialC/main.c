#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <arbol.h>

/*modifique algunas cosas para poder actualizar el
archivo de indices para que sirva para futuras ejecuciones y no quede desactualizado
*/

void imprimir_mensaje(int res);
void op_alta(FILE * arch, t_arbol * pindice);
void op_baja(FILE * arch, t_arbol * pindice);
void op_listar_indice(t_arbol * pindice);
void op_listar_alumnos(FILE * arch);
int main()
{
    ///AGREGADO POR MI

//    crear_archivo_indice();

    ///

    FILE * arch = fopen("../archivos/alumnos.dat", "r+b");
    const char opciones [][TAM_MENU] = {"ABILS","Alta", "Baja", "Listar Indice", "Listar Alumnos", "Salir"};
    char op;
    t_arbol indice;
    crear_arbol_res(&indice);


    //cargar_arbol_de_archivo_ordenado_res(&indice, "../archivos/alumnos.idx");
    cargar_arbol_de_archivo_ordenado(&indice, "../archivos/alumnos.idx");



    ///prueba de indice
//    recorrer_Enorden(&indice,imprimir_indice);

 /// prueba de funcion cargar balanceado

//    printf("Es balanceado: %s",es_arbol_balanceado(&indice)? "SI" : "NO");

    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                op_alta(arch, &indice);
                break;
            case 'B':
                op_baja(arch, &indice);
                break;
            case 'I':
                op_listar_indice(&indice);
                break;
            case 'L':
                op_listar_alumnos(arch);
                break;
        }
    }while(op!='S');
    grabar_arbol_en_archivo_ordenado_res(&indice,"../archivos/alumnos.idx");
    vaciar_arbol(&indice);
    fclose(arch);
    return 0;
}

void op_alta(FILE * arch, t_arbol * pindice)
{
    int res;
    t_alumno alu;
    ingresar_alumno(&alu);
    //res= alta_res(&alu, arch, pindice);
    res= alta(&alu, arch, pindice);
    imprimir_mensaje(res);
}

void op_baja(FILE * arch, t_arbol * pindice)
{
    int res;
    t_alumno alu;
    ingresar_dni_alumno(&alu);
    //res= baja_res(&alu, arch, pindice);
    res= baja(&alu, arch, pindice);
    imprimir_mensaje(res);
}

void op_listar_indice(t_arbol * pindice)
{
    printf("\n\n");
    arbol_grafico(pindice, mostrar_dni);
    //arbol_grafico(pindice, imprimir_indice);   ///para realizar una prueba
    pausa("\n\n");
}

void op_listar_alumnos(FILE * arch)
{
    printf("\n\n");
    imprimir_archivo(arch);
    pausa("\n\n");
}

void imprimir_mensaje(int res)
{
    switch(res)
    {
        case TODO_OK: pausa("Operacion realizada correctamente.");
                break;
        case SIN_MEM: pausa("Error de memoria.");
                break;
        case ERROR_ARCHIVO: pausa("Error en el archivo.");
                break;
        case DUPLICADO: pausa("Resgistro duplicado.");
                break;
        case NO_EXISTE: pausa("Resgistro inexistente.");
                break;
    }
}
