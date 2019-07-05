#include <Arbol.h>



void recorrer_arbol_en(const t_arbol* pa, t_accion accion, void* datos_accion)
{
    if(!*pa)
        return;

    recorrer_arbol_en(&(*pa)->pizq,accion,datos_accion);
    accion(&(*pa)->info,datos_accion);
    recorrer_arbol_en(&(*pa)->pder,accion,datos_accion);
}

void recorrer_arbol_pre(const t_arbol* pa, t_accion accion, void* datos_accion)
{
    if(!*pa)
        return;

    accion(&(*pa)->info,datos_accion);
    recorrer_arbol_pre(&(*pa)->pizq,accion,datos_accion);
    recorrer_arbol_pre(&(*pa)->pder,accion,datos_accion);
}

int eliminar_de_arbol(t_arbol* pa, t_dato* pd, t_cmp cmp)
{
    t_nodo_arb ** pnae;

    pnae = buscar_nodoA(pa,pd,cmp);
    *pd= (*pnae)->info;

    if(!*pnae)
        return 0; ///NO EXISTE

    eliminar_nodoA(pnae,cmp);

    return 1; ///TODO_OK
}

void eliminar_nodoA(t_nodo_arb **pnae,t_cmp cmp)
{
    if(!(*pnae)->pder && !(*pnae)->pizq)
        free(*pnae);
    return;

    t_nodo_arb ** pnreempl = altura_arbol(&(*pnae)->pizq) > altura_arbol(&(*pnae)->pder) ?
                             mayor(&(*pnae)->pizq,cmp) : menor (&(*pnae)->pder,cmp);

    eliminar_nodoA(pnreempl,cmp);
}

int altura_arbol(const t_arbol* pa)
{
    if(!pa)
        return 0;

    int hi= altura_arbol(&(*pa)->pizq);
    int hd= altura_arbol(&(*pa)->pder);

    return (hi > hd? hi : hd)+1;
}

t_nodo_arb ** buscar_nodoA(t_arbol* pa,t_dato *pd,t_cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp = cmp(pd,&(*pa)->info);
    if(comp == 0)
        return pa;
    if(comp <0)
        return buscar_nodoA(&(*pa)->pizq,pd,cmp);
    else
        return buscar_nodoA(&(*pa)->pder,pd,cmp);
}

t_nodo_arb ** menor(t_arbol* pa,t_cmp cmp)
{
    while(*pa && (*pa)->pizq)
        pa = &(*pa)->pizq;
    return pa;
}

t_nodo_arb ** mayor(t_arbol* pa,t_cmp cmp)
{
    while(*pa && (*pa)->pder)
        pa = &(*pa)->pder;
    return pa;
}


