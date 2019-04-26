#include "funciones_fechas.h"


int es_fecha_valida(t_fecha fecha)
{
    if(fecha.a>1600)
        if(fecha.m>=1 && fecha.m<=12)
            if(fecha.d>=1 && fecha.d<= cant_dias_mes(fecha.m,fecha.a))
                return 1;
    return 0;
}

int es_biciesto(int a)
{
   return ((a%4==0 && a%100!=0)|| a%400==0);
}

int cant_dias_mes(int m,int a)
{
    int vec_dias[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(m==2 && es_biciesto(a))
        return 29;
    return vec_dias[m-1];
}

t_fecha sumar_dias(t_fecha fecha, int d)
{
    fecha.d+=d;
    int cant_dias;
    while(fecha.d > (cant_dias = cant_dias_mes(fecha.m,fecha.a)))
    {
        fecha.d-=cant_dias;
        fecha.m++;
        if(fecha.m>12)
        {
        fecha.a++;
        fecha.m=1;
        }
    }
    return fecha;
}

t_fecha ingresar_fecha()
{
    t_fecha f;
    puts("Ingresar una fecha(D/M/A):");
    fflush(stdin);
    scanf("%d/%d/%d", &f.d,&f.m,&f.a);
    while(!es_fecha_valida(f))
    {
        puts("Error: Fecha Invalida. Reingresela(D/M/A)");
        fflush(stdin);
        scanf("%d/%d/%d", &f.d,&f.m,&f.a);
    }
    return f;
}

t_fecha restar_dias(t_fecha fecha, int d)
{
    fecha.d-=d;

    while(fecha.d <1 )
    {
            if(fecha.m == 1)
            {
                fecha.m=12;
                fecha.a--;
            }
            else
            {
                fecha.m--;
            }
            fecha.d+=cant_dias_mes(fecha.m,fecha.a);
    }

    return fecha;
}


int diferencia_entre_fechas(t_fecha* desdef, t_fecha* hastaf)
{
    int dif=0;
    int aAct;

            for(aAct=desdef->a;aAct < hastaf->a;aAct++)
                dif+=cant_dias_anio(aAct);

            dif+=dias_anio(hastaf)-dias_anio(desdef);

    return dif;
}




int mes_menor(int m1,int a1, int m2,int a2)
{
    return (a1*100+m1)<(a2*100+m2);
}

int dias_anio(t_fecha* fecha)
{
    static int mdanio[2][12]={{0,31,59,90,120,151,181,212,243,273,304,334},
                              {0,31,60,91,121,152,182,213,244,274,305,335}};
    return ( (mdanio[es_biciesto(fecha->a)?1:0][fecha->m-1])+fecha->d);
}

int cant_dias_anio(int a)
{
    return es_biciesto(a)?366:365;
}

int dia_de_la_semana(t_fecha* fecha)
{
    t_fecha fechaBase = {1601,1,1};

    int dif = diferencia_entre_fechas(&fechaBase,fecha);
    return dif%7;
}
