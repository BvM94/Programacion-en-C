#include<lista.h>
#include<stdlib.h>
#include<stdio.h>


void crear_lista(t_lista * plista)
{
    *plista = NULL;
}

int instertar_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*), void(*acum)(t_info *, const t_info*))
{

    while(*plista && comp(pinfo, &(*plista)->info)>0 )
        plista = &(*plista)->psig;

    if(*plista && comp(pinfo, &(*plista)->info)==0 )
    {
        acum(&(*plista)->info,pinfo);
        return OK;

    }

     t_nodo* nue =(t_nodo*) malloc(sizeof(t_nodo));

     if(!nue)
        return LISTA_LLENA;

     nue->info = *pinfo;
     nue->psig = *plista;
     *plista = nue;

    return OK;
}

int sacar_primero_lista(t_lista * plista, t_info * pinfo)
{
    t_nodo* nae;

    if(! *plista)
        return 0;

    nae= *plista;
    *plista = nae->psig;
    *pinfo  = nae->info;

    free(nae);
    return 1;

}

