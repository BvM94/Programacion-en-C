#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define NO_ES_PALINDROMO 0
#define ES_PALINDROMO 1
#define A_MINUSCULA_SI_ES_MAYUSCULA(C) ((C>='A' && C<='Z')? C+('a'-'A'): C)
#define ES_LETRA(C) (C>='A' && C<='Z'? C: C>='a' && C<='z'? C : 0)

#include <stdio.h>
#include <stdlib.h>

typedef struct s_fecha
{
    int dia;
    int mes;
    int anio;

}t_fecha;

int es_palindromo (const char* pstring);

int es_biciesto(const int anio);

int dia_del_anio(const t_fecha *f);

int dias_entre_fechas(const t_fecha desde , const t_fecha hasta);

int dia_de_la_semana(const t_fecha f);



#endif // FUNCIONES_H_INCLUDED
