#include <Fecha.h>

int es_fecha_valida(const t_fecha* fecha)
{
    return(fecha->a > 1600 && fecha->m > 0 && fecha->m <=12 &&
           fecha->d >0 && fecha->d <=cant_dias_mes(fecha->m,fecha->a));

}

int cant_dias_mes(int mes, int anio)
{
    static char diaM[][12]= {{31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };

    return (es_bisiesto(anio)?diaM[1][mes-1]:diaM[0][mes-1]);
}

int es_bisiesto(int anio)
{
    return ((anio%4 == 0  && anio%100 == 0 )|| anio%400 == 0);
}

int txt_a_fecha(const char* txt, t_fecha* fecha)
{
    sscanf(txt,"%d/%d/%d",&fecha->d,&fecha->m,&fecha->a);
    return es_fecha_valida(fecha);
}


void sumar_dias_a_fecha(const t_fecha* fecha, int dias, t_fecha* fecha_suma)
{
    int cant_dias;
    *fecha_suma = *fecha;
    fecha_suma->d += dias;

    while(fecha_suma->d > (cant_dias=cant_dias_mes(fecha_suma->m,fecha_suma->a)))
    {
        fecha_suma->d -= cant_dias;
        fecha_suma->m++;

        if(fecha_suma->m > 12)
        {
            fecha_suma->m = 1;
            fecha_suma->a++;
        }
    }
}

int cmpFechas(const t_fecha* f1, const t_fecha* f2)
{
    if(f1->a == f2->a)
    {
        if(f1->m == f2->m)
        {
            if(f1->d == f2->d)
                return 0;
            else
                return f1->d - f2->d;
        }
        else
            return f1->m - f2->m;
    }
    return f1->a - f2->a;
}
