#include <stdio.h>
#include <stdlib.h>
#include <ListaD.h>
#include <Defs.h>
#include <Utilitarias2doParcialC4.h>
#include <string.h>
#include "../include/Fecha.h"

int comparar_cuentas(const void* cuenta1, const void* cuenta2);
int comparar_cuentas_nombre(const void* cuenta1, const void* cuenta2);
int comparar_Fechas(const void* fecha1, const void* fecha2);
void  act_cuenta(void* actualizado, const void* actualizador);

int main()
{
    t_lista lista_compras;

    crear_lista_res(&lista_compras);

    generar_archivo_compras_usuarios();

    generar_archivo_cuentas_usuarios();

    FILE* arch_compras = fopen("ComprasUsuarios.txt", "rt");

    FILE* arch_cuentas = fopen("CuentasUsuarios.dat", "rb+");

    t_arbol arb_indice;

    crear_arbol_res(&arb_indice);

    generar_arbol_indice(&arb_indice, arch_cuentas);

    puts("Archivo de Compras");
    mostrar_archivo_compras(arch_compras);
    puts("");


    ///Genera la lista a partir de los registros del archivo de Compras.
    generar_lista_de_txt(arch_compras, &lista_compras);
    ///generar_lista_de_txt_res(arch_compras, &lista_compras);

    puts("Lista antes de consolidar");
    recorrer_lista_res(&lista_compras, mostrar_cuenta, NULL);
    puts("");


    ///Consolida la lista. Elimina los duplicados, de forma de que el elemento que queda en la lista sumariza el contenido de los elementos eliminados.
    ///Ejemplo: ConejoPepito tiene 3 compras(3 elementos en la lista), Tiene que quedar en la misma uno con la suma de todas las compras, y con la fecha de la última compra.
    lista_consolidar(&lista_compras, comparar_cuentas_nombre, act_cuenta);
    ///lista_consolidar_res(&lista_compras, cmp_cuentas_res, act_cuenta_res);

    puts("Lista despues de consolidar");
    recorrer_lista_res(&lista_compras, mostrar_cuenta, NULL);
    puts("");

    puts("Archivo de Cuentas antes de actualizar");
    mostrar_archivo_cuentas(arch_cuentas);
    puts("");

    int tipoBalance = determinarTipoBalanceArbol(&arb_indice);
    ///int tipoBalance = determinarTipoBalanceArbol_res(&arb_indice);

    switch(tipoBalance)
    {
    case DESBALANCEADO:
        puts("El arbol esta desbalanceado.");
        break;

    case AVL:
        puts("El arbol es AVL.");
        break;

    case BALANCEADO:
        puts("El arbol es balanceado.");
        break;

    case COMPLETO:
        puts("El arbol es completo.");
        break;
    }

    puts("");

    ///Actualiza el archivo de Cuentas con los elementos de la lista consolidada.
    ///El acceso al archivo se realiza en forma directa, utilizando un índice implementado en un árbol binario de búsqueda.
    actualizar_cuentas_usuarios(&lista_compras, arch_cuentas, &arb_indice);
    ///actualizar_cuentas_usuarios_res(&lista_compras, arch_cuentas, &arb_indice);

    puts("Archivo de Cuentas despues de actualizar");
    mostrar_archivo_cuentas(arch_cuentas);
    puts("");

    return 0;
}

void generar_lista_de_txt(FILE* arch_compras, t_lista* lista_compras)
{
    char prod[100];
    t_cuenta c;

    fseek(arch_compras,0l,SEEK_SET);
    while(EOF!=fscanf(arch_compras,"%s\t%s\t%lf\t%d/%d/%d",c.nombre,prod,&c.importe_saldo,
                      &c.fecha_ult_compra.d,&c.fecha_ult_compra.m,&c.fecha_ult_compra.a))
        insertar_en_lista_ord_dup(lista_compras,&c,comparar_cuentas);

}


void actualizar_cuentas_usuarios(t_lista* lista_compras, FILE* arch_cuentas, t_arbol* arb_indice)
{
    t_cuenta mov,cuenta;
    t_indice ind;
    while(lista_sacar_primero(lista_compras,&mov))
    {
        strcpy(ind.nombre,mov.nombre);
        buscar_en_arbol_bin_busq(arb_indice,&ind,comparar_cuentas_nombre);
        fseek(arch_cuentas,ind.nro_reg * sizeof(t_cuenta),SEEK_SET);
        fread(&cuenta,sizeof(t_cuenta),1,arch_cuentas);

        cuenta.importe_saldo -= mov.importe_saldo;
        cuenta.fecha_ult_compra =  mov.fecha_ult_compra;

        fseek(arch_cuentas,ind.nro_reg * sizeof(t_cuenta),SEEK_SET);
        fwrite(&cuenta,sizeof(t_cuenta),1,arch_cuentas);
    }
}

int comparar_cuentas(const void* cuenta1, const void* cuenta2)
{
    t_cuenta * c1 = (t_cuenta*)cuenta1;
    t_cuenta * c2 = (t_cuenta*)cuenta2;
    int comp =strcmp(c1->nombre,c2->nombre);
    if(comp==0)
        return cmp_fechas(&c1->fecha_ult_compra,&c2->fecha_ult_compra);

    return comp ;
}

int comparar_cuentas_nombre(const void* cuenta1, const void* cuenta2)
{
    t_cuenta * c1 = (t_cuenta*)cuenta1;
    t_cuenta * c2 = (t_cuenta*)cuenta2;
    return strcmp(c1->nombre,c2->nombre);
}


void  act_cuenta(void* actualizado, const void* actualizador)
{
    t_cuenta * c1 = (t_cuenta*)actualizado;
    t_cuenta * c2 = (t_cuenta*)actualizador;

    c1->importe_saldo += c2->importe_saldo;

    if(comparar_Fechas(&c2->fecha_ult_compra,&c1->fecha_ult_compra)>0)
        c1->fecha_ult_compra = c2->fecha_ult_compra;

}

int comparar_Fechas(const void* fecha1, const void* fecha2)
{
    t_fecha * f1 = (t_fecha*) fecha1;
    t_fecha * f2 = (t_fecha*) fecha2;

    if(f1->a != f2->a)
        return f1->a - f2->a;
    if(f1->m != f2->m)
        return f1->m - f2->m;
    if(f1->d != f2->d)
        return f1->d - f2->d;

    return 0;
}


