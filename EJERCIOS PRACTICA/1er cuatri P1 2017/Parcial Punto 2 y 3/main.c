#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int main()
{
    t_fecha fecha1= {28,05,2019};
    char dia[3];

    char cadena[]="Anita lava la tina.";

    printf("%s - %s es un palindromo\n",cadena,es_palindromo(cadena) == 1? "SI": "NO");




    switch (dia_de_la_semana(&fecha1))
    {
    case 0:
        strcpy(dia,"LU");
        break;
    case 1:
        strcpy(dia,"MA");
        break;
    case 2:
        strcpy(dia,"MI");
        break;
    case 3:
        strcpy(dia,"JU");
        break;
    case 4:
        strcpy(dia,"VI");
        break;
    case 5:
        strcpy(dia,"SA");
        break;
    case 6:
        strcpy(dia,"DO");
        break;
    }

    printf("El dia de la semana de la fecha: %d/%d/%d es %s \n",fecha1.dia,fecha1.mes,fecha1.anio,dia);
}
