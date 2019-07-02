#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <arbol.h>

void imprimir_mensaje(int res);
void op_alta(t_arbol * pa);
void op_baja(t_arbol * pa);
void op_mostrar_arbol(const t_arbol * pa);
void op_listar_alumnos(const t_arbol * pa);
void op_validar_arbol(const t_arbol * pa);

int comparar_dni(const t_info* info1,const t_info* info2);
int comparar_dni(const t_info* info1,const t_info* info2)
{
    return info1->dni - info2->dni;
}

int main()
{
///PRUEBA DE LAS FUNCION VALIDAR_ARBOL , JUNTO CON AVL, BALANCEADO, COMPLETO Y ALTURA
//    t_arbol prueba, comp,balan,avl,desba;
//    int vecCOMPLETO[]={20,10,11,5,25,22,30};
//    int vecBALANCEADO[]={20,10,25,30};
//    int vecAVL[]= {20,10,5,25,22,30,35};
//    int vecDESBALANCEADO[]={20,10,25,30,35};
//    int i;
//    t_alumno alu;
//
//    crear_arbol_res(&avl);
//    crear_arbol_res(&comp);
//    crear_arbol_res(&balan);
//    crear_arbol_res(&desba);
//
//    for(i=0;i<7;i++)
//    {
//        alu.dni=vecCOMPLETO[i];
//      insertar_en_arbol_bin_busq_res(&comp,&alu,comparar_dni);
//    }
//
//    for(i=0;i<4;i++)
//    {
//      alu.dni=vecBALANCEADO[i];
//      insertar_en_arbol_bin_busq_res(&balan,&alu,comparar_dni);
//    }
//
//    for(i=0;i<7;i++)
//    {
//        alu.dni=vecAVL[i];
//      insertar_en_arbol_bin_busq_res(&avl,&alu,comparar_dni);
//    }
//
//    for(i=0;i<5;i++)
//    {
//       alu.dni=vecDESBALANCEADO[i];
//      insertar_en_arbol_bin_busq_res(&desba,&alu,comparar_dni);
//    }
//
//    puts("\n\nes COMPLETO???\n\n");
//    validar_arbol(&comp);
//
//    puts("\n\nes BALACEADO???\n\n");
//    validar_arbol(&balan);
//
//    puts("\n\nes AVL???\n\n");
//    validar_arbol(&avl);
//
//    puts("\n\nes DESBALANCEADO???\n\n");
//    validar_arbol(&desba);
//
//
////    crear_arbol_res(&prueba);
////    validar_arbol(&prueba);
//
//    fflush(stdin);
//    getchar();

    const char opciones [][TAM_MENU] = {"ABILVS","Alta", "Baja", "Mostrar Arbol", "Listar Alumnos","Validar Arbol", "Salir"};
    char op;
    t_arbol arbol;
    crear_arbol_res(&arbol);
    cargar_arbol_de_archivo_ordenado_res(&arbol, "../archivos/alumnos.dat");
    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                op_alta(&arbol);
                break;
            case 'B':
                op_baja(&arbol);
                break;
            case 'I':
                op_mostrar_arbol(&arbol);
                break;
            case 'L':
                op_listar_alumnos(&arbol);

                break;
            case 'V':
                //op_validar_arbol(&arbol);
                validar_arbol(&arbol);
                break;
        }
    }while(op!='S');
    grabar_arbol_en_archivo_ordenado_res(&arbol,"../archivos/alumnos.dat");
    vaciar_arbol_res(&arbol);
    return 0;
}

void op_alta(t_arbol * pa)
{
    int res;
    t_alumno alu;
    ingresar_dni_alumno(&alu);
    res= alta_res(alu.dni, pa);
    ///res= alta_res(alu->dni, pa);
    imprimir_mensaje(res);
}

void op_baja(t_arbol * pa)
{
    int res;
    t_alumno alu;
    ingresar_dni_alumno(&alu);
    res= baja_res(alu.dni, pa);
    ///res= baja_res(&alu, pa);
    imprimir_mensaje(res);
}

void op_mostrar_arbol(const t_arbol * pa)
{
    printf("\n\n");
    arbol_grafico(pa, mostrar_dni);
    pausa("\n\n");
}

void op_listar_alumnos(const t_arbol * pa)
{
    printf("\n\n");
    //imprimir_listado_res(pa);
    imprimir_listado(pa);
    pausa("\n\n");
}

void op_validar_arbol(const t_arbol * pa)
{
    printf("\n\n");
    validar_arbol_res(pa);
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
