#include "../include/Lista.h"
#include "../include/Defs.h"

#include <stdio.h>

//void crear_lista(t_lista* plista)
//{
//    *plista =NULL;
//}

//int lista_sacar_por_clave(t_lista * pl,t_dato_lista* pdato,void* clave,t_cmp cmp)
//{
//    t_nodo * nae;
//    while(*pl)
//    {
//        if(cmp(&(*pl)->info,clave)==0)
//        {
//            *pdato = (*pl)->info;
//            nae = *pl;
//            *pl = (*pl)->psig;
//            free(nae);
//
//            return TODO_OK;
//        }
//        pl= &(*pl)->psig;
//    }
//    return NO_EXISTE;
//}

int lista_sacar_primero(t_lista* plista, t_dato_lista* pd)
{
    if(!*plista)
        return 0;
    t_nodo * nae;

    *pd = (*plista)->info;
    nae = *plista;
    *plista = nae->psig;
    free(nae);

    return 1;
}

void eliminar_duplicados_de_lista_ord(t_lista* plista, t_cmp cmp, t_actualizar actualizar)
{
    t_dato_lista dato;

    while(*plista)
    {
        if(cmp(&(*plista)->info,&(*plista)->psig->info)==0)
            {
                lista_sacar_primero(plista,&dato);
                actualizar(&(*plista)->info,&dato);
            }

        plista=&(*plista)->psig;
    }
}

void lista_ordenar_asc(t_lista* plista, t_cmp cmp)
{
    t_nodo ** pmenor, ** pult;  //o t_lista *
    t_lista lord;
    pult = &lord;

    while(*plista)
    {
        pmenor = buscar_menor(plista, cmp);
        *pult= *pmenor;   //engancho a lista ordenada
        pult= &(*pult)->psig;
        *pmenor = (*pmenor)->psig; //desengancho nodo de la lista desordenada
    }
    *plista=lord;
}

t_nodo** buscar_menor(t_lista * pl,t_cmp cmp)
{
    t_nodo ** menor = pl;

    pl=&(*pl)->psig;

    while(*pl)
    {
        if(cmp(&(*pl)->info,&(*menor)->info)<0)
            menor= pl;
        pl=&(*pl)->psig;
    }
    return menor;
}
