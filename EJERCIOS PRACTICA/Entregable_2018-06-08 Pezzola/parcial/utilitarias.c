#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <utilitarias.h>
#include <banco.h>

int comparar_movimientos(const t_info * pinfo1, const t_info* pinfo2)
{
    return strcmp(pinfo1->cod_cta,pinfo2->cod_cta);
}

void acumular_movimiento(t_info * pinfo1, const t_info* pinfo2)
{
//   printf("%s - %c - %f\n",pinfo1->cod_cta,pinfo1->tipo_mov,pinfo1->importe);
//   printf("%s - %c - %f\n",pinfo2->cod_cta,pinfo2->tipo_mov,pinfo2->importe);


    if(pinfo1->tipo_mov == pinfo2->tipo_mov)
        pinfo1->importe += pinfo2->importe;
    else
    {
        if(pinfo1->importe >= pinfo2->importe )
        {
            (pinfo1->importe) -= pinfo2->importe;
        }
        else
        {
            pinfo1->importe = pinfo2->importe - pinfo1->importe;
            pinfo1->tipo_mov = pinfo2->tipo_mov;
        }
    }

//   printf("%s - %c - %f\n",pinfo1->cod_cta,pinfo1->tipo_mov,pinfo1->importe);
//puts("------------------------------------------------------------------\n");
}

void texto_a_movimiento(const char * cadena,t_movimiento_banco * pmov)
{
    char * pcad;
    char * pe;

    pcad=strchr(cadena,'\n');

    *pcad= '\0';
    pcad-= 9;

    pmov->importe = atoi(pcad);
    pcad--;

    pmov->tipo_mov = *pcad;

    *pcad= '\0';

    strcpy(pmov->cod_cta,cadena);

    pcad = strchr(pmov->cod_cta,'\0');

    pe = pcad +1;

    *pe = *pcad;
    pcad--;
    pe--;
    *pe = *pcad;
    *pcad='/';

}
