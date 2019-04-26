#include <stdio.h>
#include <stdlib.h>
#include "../funciones_fechas.h"

int main()
{
////////////////////////////////////////////////////////////////////7//
    t_fecha fecha1={2019,4,25};
    int dia=1008;
    printf("%d/%d/%d\n\n",fecha1.d,fecha1.m,fecha1.a);
//
//    fecha1= sumar_dias(fecha1,dia);
//    printf("%d/%d/%d\n\n",fecha1.d,fecha1.m,fecha1.a);
//
    fecha1=restar_dias(fecha1,dia);

    printf("%d/%d/%d",fecha1.d,fecha1.m,fecha1.a);


//    fecha1=ingresar_fecha();
//
//    printf("%d/%d/%d",fecha1.d,fecha1.m,fecha1.a);
//


//////////////////////////////////////////////////////////////////////////
//t_fecha fecha={2018,1,1};
//t_fecha fecha1={2019,1,1};
//
//printf("%d",diferencia_entre_fechas(&fecha,&fecha1));

//t_fecha fecha2=ingresar_fecha();
//int ds = dia_de_la_semana(&fecha2);
//
//char vds[7][10]={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
//
//printf("La fecha %d/%d/%d corresponde al dia %s \n",fecha2.d,fecha2.m,fecha2.a,vds[ds]);

//return 0;
}
