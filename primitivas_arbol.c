#include "primitivas_arbol.h"

void crear_arbol(t_arbol * pa)
{
    *pa = NULL;
}

int insertar_en_arbol_bin(t_arbol * pa,const t_dato *pd,t_cmp cmp)
{
    if(!*pa)
    {
        *pa=(t_nodo_ar*) malloc(sizeof(t_nodo_ar));
        if(!*pa)
            return 0; //sin memoria

        (*pa)->info = *pd;
        (*pa)->hizq = (*pa)->hder = NULL;
        return 1; // todo_OK
    }
    int comp = cmp(pd,&(*pa)->info);

    if(comp == 0)
        return 2; //duplicado

    if(comp<0)
        return insertar_en_arbol_bin(&(*pa)->hizq,pd,cmp);

    return insertar_en_arbol_bin(&(*pa)->hder,pd,cmp);

}

void recorrer_arbol_preorden(const t_arbol * pa,t_accion accion)
{
    if(!*pa)
        return;

    accion(&(*pa)->info);

    recorrer_arbol_preorden(&(*pa)->hizq,accion);

    recorrer_arbol_preorden(&(*pa)->hder,accion);

}

void recorrer_arbol_enorden(const t_arbol * pa,t_accion accion)
{
    if(!*pa)
        return;

    recorrer_arbol_enorden(&(*pa)->hizq,accion);

    accion(&(*pa)->info);

    recorrer_arbol_enorden(&(*pa)->hder,accion);

}
void recorrer_arbol_posorden(const t_arbol * pa,t_accion accion)
{
    if(!*pa)
        return;

    recorrer_arbol_posorden(&(*pa)->hizq,accion);

    recorrer_arbol_posorden(&(*pa)->hder,accion);

    accion(&(*pa)->info);

}

void vaciar_arbol(t_arbol *pa)
{
    if(!*pa)
        return;

    vaciar_arbol(&(*pa)->hizq);
    vaciar_arbol(&(*pa)->hder);

    free(*pa);
    *pa=NULL;
}

int altura_arbol(const t_arbol *pa)
{
    if(!*pa)
        return 0;

    int hi = altura_arbol(&(*pa)->hizq);
    int hd = altura_arbol(&(*pa)->hder);

    return (hi>hd?hi:hd)+1;
}


void podar_arbol(t_arbol *pa,int nivel)
{
    if(!*pa)
        return;

    if(nivel == 0)
    {
        vaciar_arbol(pa);
        return;
    }

    podar_arbol(&(*pa)->hizq,nivel-1);

    podar_arbol(&(*pa)->hder,nivel-1);
}

int eliminar_de_arbol(t_arbol *pa , t_dato *pd, t_cmp cmp)
{
    t_nodo_ar ** pnae = buscar_nodo(pa,pd,cmp);

    if(!pnae)
        return 0;

    *pd = (*pnae)->info;
    eliminar_nodo_ar(pnae);
    return 1;
}

t_nodo_ar ** buscar_nodo(t_arbol * pa, t_dato *pd, t_cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp = cmp(pd,&(*pa)->info);

    if(comp == 0)
        return pa;

    if(comp < 0 )
        return buscar_nodo(&(*pa)->hizq,pd,cmp);
    else
        return buscar_nodo(&(*pa)->hder,pd,cmp);
}

void eliminar_nodo_ar(t_nodo_ar** pnae)
{
    if(!(*pnae)->hizq && !(*pnae)->hder)
    {
        free(*pnae);
        *pnae = NULL;
        return;
    }

    int hi = altura_arbol(&(*pnae)->hizq);
    int hd = altura_arbol(&(*pnae)->hder);

    t_nodo_ar ** pnreempl = hi>hd? mayor(&(*pnae)->hizq): menor(&(*pnae)->hder);
    (*pnae)->info = (*pnreempl)->info;

    eliminar_nodo_ar(pnreempl);
}

t_nodo_ar ** menor(t_arbol *pa)
{
    return NULL;
}

t_nodo_ar ** mayor(t_arbol *pa)
{
    return NULL;
}
