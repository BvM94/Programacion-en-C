#include<lista.h>
#include<stdlib.h>

void crear_lista(t_lista * plista)
{
    *plista = NULL;
}

int instertar_prim5_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*))
{
    int cont=0;
    t_lista * plaux;

    while(*plista && comp(pinfo,&(*plista)->info)<=0 && cont < 5)
    {
        plista=&(*plista)->psig;
        cont++;
    }

    if(cont == 5)
        return LISTA_LLENA;

    plaux = plista;

    while(*plaux)
    {
        plaux=&(*plaux)->psig;
        cont++;
    }


    if(cont == 5)
        eliminar_ultimo_lista(plista);

    t_nodo * nue =(t_nodo*) malloc(sizeof(t_nodo));

    nue->psig = *plista;
    *plista = nue;
    nue->info = *pinfo;

    return OK;
}

int sacar_primero_lista(t_lista * plista, t_info * pinfo)
{
    if(!*plista)
        return LISTA_VACIA;

    t_nodo * nae;

    nae = *plista;
    *plista = nae->psig;
    *pinfo = nae->info;

    free(nae);

    return OK;

}

int eliminar_ultimo_lista(t_lista * plista)
{
    if(!*plista)
        return LISTA_VACIA;

    while((*plista)->psig != NULL)
        plista=&(*plista)->psig;

    t_nodo * nae;

    nae = *plista;
    *plista = NULL;

    free(nae);

    return OK;
}

