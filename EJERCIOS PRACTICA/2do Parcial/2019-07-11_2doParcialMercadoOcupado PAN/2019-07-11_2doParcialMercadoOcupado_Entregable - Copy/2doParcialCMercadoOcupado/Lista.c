#include <Defs.h>
#include <ListaD.h>
#include <stdlib.h>


int insertar_en_lista_ord_dup(t_lista* pl, const t_dato_lista* pd, t_cmp cmp)
{
    ///Inserte el código acá ...
    t_nodod *ant = *pl;
    t_nodod *sig  = ant? ant->psig : NULL;

    while(ant && cmp(pd,&ant->info) < 0)
    {
        sig = ant;
        ant = ant->pant;
    }

    while(sig && cmp(pd,&sig->info)>0)
    {
        ant = sig;
        sig = sig->psig;
    }

    t_nodod * nue = (t_nodod*)malloc(sizeof(t_nodod));
    if(!nue)
        return 0;

    if(ant)
        ant->psig = nue;
    if(sig)
        sig->pant = nue;
    nue->psig = sig;
    nue->pant = ant;
    nue->info = *pd;
    (*pl) = nue;

    return 1;
}


void lista_consolidar(t_lista* pl, t_cmp cmp, t_actualizar actualizar)
{
    ///Inserte el código acá ...

    t_nodod *nae,*mov = *pl;

    while(mov && mov->pant)
    {
        if(cmp(&mov->info,&mov->pant->info)== 0)
        {
            nae = mov->pant;
            actualizar(&mov->info,&nae->info);
            mov->pant = nae->pant;
            if(nae->pant)
                nae->pant->psig = nae->psig;

            free(nae);
        }
        else
            mov = mov->pant;
    }
    mov= *pl;

    while(mov && mov->psig)
    {
        if(cmp(&mov->info,&mov->psig->info)== 0)
        {
            nae = mov->psig;
            actualizar(&mov->info,&nae->info);
            mov->psig = nae->psig;
            if(nae->psig)
                nae->psig->pant = nae->pant;
            free(nae);
        }
        else
            mov = mov->psig;
    }
}


int lista_sacar_primero(t_lista* pl, t_dato_lista* pd)
{
    ///Inserte el código acá ...

    if(!*pl)
        return 0;

    t_nodod *nae  = *pl;

    *pd = nae->info;
    if(nae->pant)
        nae->pant->psig = nae->psig;
    if(nae->psig)
        nae->psig->pant = nae->pant;

    *pl = nae->pant ? nae->pant : nae->psig;
    free(nae);
    return  1;
}
