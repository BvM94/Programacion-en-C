#include "listaD_funciones.h"

void crear_lista(t_lista *pl)
{
    *pl = NULL;
}

int insertar_lista_desordenada(t_lista *pl,const t_dato *pd)
{
    t_nodoD *ant = *pl;
    t_nodoD *sig = ant? ant->psig:NULL;

    t_nodoD *nue =(t_nodoD*) malloc(sizeof(t_nodoD));
    if(!nue)
        return 0; ///lista llena
    if(ant)
        ant->psig = nue;
    if(sig)
        sig->pant = nue;

    nue->info= *pd;
    nue->pant= ant;
    nue->psig= sig;
    *pl = nue;


    return 1; ///todo ok
}

int insertar_lista_ordenadaASC(t_lista *pl,const t_dato *pd, t_cmp cmp)
{
    t_nodoD *ant = *pl;
    t_nodoD *sig = ant? ant->psig:NULL;

    while(ant && cmp(pd,&ant->info)<0)
    {
        sig = ant;
        ant = ant->pant;
    }
    while(sig && cmp(pd,&sig->info)>0)
    {
        ant = sig;
        sig = sig->psig;
    }

    if(ant && cmp(pd,&ant->info)==0)
        return 2; ///duplicado
    if(sig && cmp(pd,&sig->info)==0)
        return 2; ///duplicado

    t_nodoD *nue =(t_nodoD*) malloc(sizeof(t_nodoD));
    if(!nue)
        return 0; ///lista llena
    if(ant)
        ant->psig = nue;
    if(sig)
        sig->pant = nue;

    nue->info= *pd;
    nue->pant= ant;
    nue->psig= sig;
    *pl = nue;

    return 1; ///todo ok
}

int eliminar_lista_ordenadaASC(t_lista *pl,t_dato *pd, t_cmp cmp)
{
    t_nodoD *mov = *pl;

    while(mov && cmp(pd,&mov->info)<0)
        mov= mov->pant;

    while(mov && cmp(pd,&mov->info)>0)
        mov= mov->psig;

    if(!mov || cmp(pd,&mov->info)!=0)
        return 0; ///no existe

    if(mov->pant)
        mov->pant->psig = mov->psig;
    if(mov->psig)
        mov->psig->pant = mov->pant;

    *pl = mov->pant ? mov->pant : mov->psig;
    free(mov);
    return 1; ///todo ok
}

void vaciar_lista(t_lista *pl)
{
    if(!*pl)
        return; ///lista vacia

    t_nodoD *mov = (*pl)->pant,*nae;
    while(mov) ///eliminar de pl hacia la izquierda
    {
        nae = mov;
        mov=mov->pant;
        free(nae);
    }
    mov = *pl;

    while(mov) ///eliminar de pl hacia la derecha
    {
        nae = mov;
        mov=mov->psig;
        free(nae);
    }

    *pl = NULL;
}
void ordenar_lista_ASC(t_lista *pl,t_cmp cmp)
{
    t_lista listaOrd = NULL;
    t_dato info;

    while(*pl)
    {
        eliminar_apuntado_por_pl(pl,&info);
        insertar_lista_ordenadaASC(&listaOrd,&info,cmp);
    }

    *pl = listaOrd;
}

void eliminar_apuntado_por_pl(t_lista *pl,t_dato *pd)
{
    if(!*pl)
        return;

    t_nodoD * nae;
    nae=*pl;
    *pd = nae->info;
    if(nae->pant)
        nae->pant->psig = nae->psig;
    if(nae->psig)
        nae->psig->pant = nae->pant;

    *pl = nae->pant ? nae->pant : nae->psig;
}

int buscar_lista_ordenada(t_lista *pl,t_dato *pd,t_cmp cmp)
{
    t_nodoD *mov = *pl;
    while(mov && cmp(pd,&mov->info)<0)
        mov= mov->pant;

    while(mov && cmp(pd,&mov->info)>0)
        mov= mov->psig;

    if(!mov || cmp(pd,&mov->info)!=0)
        return 0; ///no existe

    *pd = mov->info;
    return 1;
}

void eliminar_duplicado(t_lista *pl, t_cmp cmp)
{
    if(!*pl)
        return; ///lista vacia

    t_nodoD *mov = *pl,*nae;
    while(mov && mov->pant) ///eliminar duplicados de pl hacia la izquierda
    {
        if(cmp(&mov->info,&(mov)->pant->info)==0)
        {
        nae = mov->pant;
        if(nae)
            mov->pant = nae->pant;
        if(nae && nae->pant)
            nae->pant->psig=mov;
        free(nae);
        }
        else
            mov = mov->pant;
    }
    mov = *pl;
    while(mov && mov->psig) ///eliminar duplicados de pl hacia la derecha
    {
        if(cmp(&mov->info,&(mov)->psig->info)==0)
        {
        nae = mov->psig;
        if(nae)
            mov->psig = nae->psig;
        if(nae && nae->psig)
            nae->psig->pant=mov;
        free(nae);
        }
        else
            mov = mov->pant;
    }
}

void mostrar_lista(const t_lista *pl)
{
    t_nodoD * mov = *pl;
    if(!mov)
        return;

    while(mov->pant)
        mov= mov->pant;

    while(mov)
    {
        printf("%d - ",mov->info);
        mov=mov->psig;
    }
}

