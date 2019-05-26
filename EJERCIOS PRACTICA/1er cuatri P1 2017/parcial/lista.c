#include<lista.h>
#include<stdlib.h>

void crear_lista(t_lista * plista)
{
    (*plista) = NULL;
}

int lista_llena(const t_lista * plista)
{
    return OK;
}

int lista_vacia(const t_lista *plista)
{
    return OK;
}

int insertar_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*))
{
    t_nodo* nue = (t_nodo*) malloc(sizeof(t_nodo));

    if(!nue)
        return SIN_MEMO;

    while(comp(pinfo,&(*plista)->info)>0)
        plista=&(*plista)->psig;

    if(comp(pinfo,&(*plista)->info)==0)
        return DUPLICADO;

    nue->info = (*pinfo);
    nue->psig = *plista;
    *plista = nue;

    return OK;
}

int actualizar_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*), void(*act)(t_info *, const t_info*))
{
    t_nodo* nue = (t_nodo*) malloc(sizeof(t_nodo));

    if(!nue)
        return SIN_MEMO;

    while(comp(pinfo,&(*plista)->info)>0)
        plista=&(*plista)->psig;

    if(comp(pinfo,&(*plista)->info)==0)
    {
        act(&(*plista)->info,pinfo);
        return ACTUALIZADO;
    }

    nue->info = (*pinfo);
    nue->psig = *plista;
    *plista = nue;

    return OK;
}

int sacar_primero_lista(t_lista * plista, t_info * pinfo)
{
    t_nodo* nae = *plista;

    *pinfo = nae->info;
    *plista = nae->psig;
    free(nae);

    return OK;
}


void vaciar_lista(t_lista * plista)
{
    t_nodo* nae;
    while(*plista)
    {
        nae=(*plista);
        *plista = nae->psig;
        free(nae);
    }
}

void recorrer_lista(const t_lista * plista, void (*acc)(t_info*, void*), void* param)
{

}

int sacar_menor_lista (t_lista * plista, t_info* pinfo, int (*comp)(const t_info *, const t_info*) )
{

    t_nodo* nae = buscar_menor(plista,comp);

    if(!nae)
        return 0;

    *pinfo = nae->info;
    *plista = nae->psig;
    free(nae);

    return OK;

}

t_nodo* buscar_menor(t_lista* plista,int (*comp)(const t_info *, const t_info*))
{
    t_nodo* pmenor = *plista;
    while(*plista)
    {
        if(comp(&(*plista)->info,&pmenor->info)<0)
            pmenor = *plista;

        plista = &(*plista)->psig;
    }

    return pmenor;
}
