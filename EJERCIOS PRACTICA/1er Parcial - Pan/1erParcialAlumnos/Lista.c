#include "../include/Lista.h"
#include "../include/Defs.h"

#include <stdio.h>

//void crear_lista(t_lista* plista)
//{
//    *plista =NULL;
//}

int lista_sacar_por_clave(t_lista * pl,t_dato_lista* pdato,void* clave,t_cmp cmp)
{
    t_nodo * nae;
    while(*pl)
    {
        if(cmp(&(*pl)->info,clave)==0)
        {
            *pdato = (*pl)->info;
            nae = *pl;
            *pl = (*pl)->psig;
            free(nae);

            return TODO_OK;
        }
        pl= &(*pl)->psig;
    }
    return NO_EXISTE;
}

void lista_ordenar_asc(t_lista* plista, t_cmp cmp)
{
    t_nodo ** menor;
    t_nodo * mov;

    while(*plista)
    {
        menor = buscar_menor(plista, cmp);
        if(plista != menor)
        {
        mov = *menor;
        *menor = mov->psig;
         mov->psig = *plista;
        *plista = mov;

        }

        printf("%d\n", (*plista)->info.dni);
        plista=&(*plista)->psig;
    }

}

t_nodo** buscar_menor(t_lista * pl,t_cmp cmp)
{
    t_nodo ** menor = pl;

    if(*pl)
        pl=&(*pl)->psig;

    while(*pl)
    {
        if(cmp(&(*menor)->info,&(*pl)->info)>0)
            menor= pl;
        pl=&(*pl)->psig;
    }
    return menor;
}
