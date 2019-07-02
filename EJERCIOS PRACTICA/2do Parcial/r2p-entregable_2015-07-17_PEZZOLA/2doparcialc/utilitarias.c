#include<utilitarias.h>

void validar_arbol(const t_arbol *pa)
{
    ///Escriba aqui el código.

    if(es_arbol_completo(pa)) //reemplazar por la mia
    {
        printf("\n\nArbol Completo!\n\n");
    }
    else if(es_arbol_balanceado(pa))//reemplazar por la mia
            {
                printf("\n\nArbol Balanceado!\n\n");
            }
    else if(es_arbol_avl(pa))//reemplazar por la mia
            {
                printf("\n\nArbol AVL!\n\n");
            }
    else
    {
        printf("\n\nArbol Desbalanceado!\n\n");
    }

    puts("Precione ENTER para continuar...");
    fflush(stdin);
    getchar();

}

void imprimir_alumno(t_alumno* alu,void* datos)
{
    int i,sum = 0;
    printf("DNI: %d \nApellido y Nombre: %s \nNotas: ",alu->dni, alu->apyn);
    for(i=0;i<alu->cant_materias;i++)
    {
        sum+=alu->notas[i];
        printf("-%d ",alu->notas[i]);
    }
    printf("\n Promedio: %0.2f\n\n",(float)sum/alu->cant_materias);
}



void imprimir_listado(const t_arbol *pa)
{
    ///Escriba aqui el código.
    ///Puede Utilizar las funciones de recorrida de arbol provistas o desarrollar las suyas

    recorrer_arbol_enOrden(pa,imprimir_alumno," ");
}
