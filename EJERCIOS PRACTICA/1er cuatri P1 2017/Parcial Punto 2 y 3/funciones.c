#include "funciones.h"

int es_palindromo (const char* pstring)
{
    const char * ps =pstring;
    char char1, char2;

    while(*ps != '\0')
        ps++;

    ps--;

    while(pstring < ps)
    {
        char1=A_MINUSCULA_SI_ES_MAYUSCULA(*pstring);
        char2=A_MINUSCULA_SI_ES_MAYUSCULA(*ps);

        if(!ES_LETRA(char1)|| !ES_LETRA(char2))
        {
            if(!ES_LETRA(char1))
                pstring++;
            if(!ES_LETRA(char2))
                ps--;
        }
        else if (char1 != char2)
            return NO_ES_PALINDROMO;
        else
        {
            pstring++;
            ps--;

        }
    }

    return ES_PALINDROMO;

}


int es_biciesto(const int anio)
{
    return ((anio%4 == 0 && anio%100 != 0  )|| anio%400 == 0 );
}

int dia_del_anio(const t_fecha *f)
{
           static const int vec [][12] ={{0,31,59,90,120,151,181,212,243,273,304,334},
                                         {0,31,60,91,121,152,182,213,244,274,305,335}};

                    return  (es_biciesto(f->anio)? vec[1][(f->mes)-1] : vec[0][(f->mes)-1])+f->dia;
}

int dias_del_mes(const int mes, const int anio)
{
      static  int vec [][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                    {31,29,31,30,31,30,31,31,30,31,30,31}};

        return(es_biciesto(anio)? vec[1][mes-1]:vec[0][mes-1]);
}

int dias_entre_fechas(const t_fecha* desde , const t_fecha* hasta)
{
    int SumaDias=0;
    int anio = desde->anio;

    for(anio=desde->anio;anio<hasta->anio;anio++)
    {
        SumaDias+=cant_dias_anio(anio);
    }

    return SumaDias - dia_del_anio(desde)+dia_del_anio(hasta);

}

int cant_dias_anio(const int anio)
{
    return es_biciesto(anio)?366:365;
}

int dia_de_la_semana(const t_fecha* f)
{
    t_fecha fechaBase = {1,1,1601};

    return dias_entre_fechas(&fechaBase,f)%7;
}
