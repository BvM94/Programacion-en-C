#include <Lista.h>


int lista_insertar_en_orden_asc(t_lista* plista, const t_dato_lista* pd, t_cmp cmp)
{
    while(*plista && cmp(pd,&(*plista)->info) > 0)
        plista=&(*plista)->psig;

    t_nodo *nue =(t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)
        return 0;

    nue->psig = *plista;
    nue->info = *pd;
    *plista = nue;

    return 1;
}

int lista_sacar_primero(t_lista* plista, t_dato_lista* pd)
{
    if(!*plista)
        return 0;

    t_nodo* nae = *plista;
    *pd = nae->info;
    *plista = nae->psig;

    free(nae);

    return 1;
}
