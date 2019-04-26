#ifndef FUNCIONES_FECHAS_H_INCLUDED
#define FUNCIONES_FECHAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    int m;
    int d;
}t_fecha;

int es_fecha_valida(t_fecha fecha);
int es_biciesto(int a);
int cant_dias_mes(int m,int a);
t_fecha sumar_dias(t_fecha fecha, int d);
t_fecha ingresar_fecha();
t_fecha restar_dias(t_fecha fecha, int d);
int diferencia_entre_fechas(t_fecha* desdef, t_fecha* hastaf);
int mes_menor(int m1,int a1, int m2,int a2);
int dias_anio(t_fecha* fecha);
int cant_dias_anio(int a);
int dia_de_la_semana(t_fecha* fecha);


#endif // FUNCIONES_FECHAS_H_INCLUDED
