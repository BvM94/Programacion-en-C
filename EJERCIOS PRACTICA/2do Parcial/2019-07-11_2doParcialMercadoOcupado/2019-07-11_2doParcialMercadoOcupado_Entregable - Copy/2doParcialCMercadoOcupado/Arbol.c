#include <Defs.h>
#include <Arbol.h>
#include <math.h>
#include <stdlib.h>

int buscar_en_arbol_bin_busq(const t_arbol* pa, t_dato_arbol* pd, t_cmp cmp)
{
    ///Inserte el código acá ...
    if(!*pa)
        return 0;

    int comp = cmp(pd,&(*pa)->info);

    if(comp == 0)
    {
        *pd = (*pa)->info;
        return 1;
    }

    if(comp < 0)
        return buscar_en_arbol_bin_busq(&(*pa)->pizq,pd,cmp);
    else
        return buscar_en_arbol_bin_busq(&(*pa)->pder,pd,cmp);
}

int determinarTipoBalanceArbol(const t_arbol* pa)
{
    if(es_arbol_completo(pa))
        return COMPLETO;
    if(es_arbol_balanceado(pa))
        return BALANCEADO;
    if(es_arbol_avl(pa))
        return AVL;
    return DESBALANCEADO;
}

int es_arbol_completo(const t_arbol* pa)
{
    if(!*pa)
        return 1;

    int h = altura_arbol(pa);

    if(h<= 1)
        return 1;
    return es_arbol_completo_hasta_nivel(pa,h-1);
}

int es_arbol_completo_hasta_nivel(const t_arbol *pa,const int nivel)
{
    if(!*pa || nivel == 0)
        return (int)*pa;

    return es_arbol_completo_hasta_nivel(&(*pa)->pizq,nivel-1) && es_arbol_completo_hasta_nivel(&(*pa)->pder,nivel-1);
}

int es_arbol_balanceado(const t_arbol* pa)
{
    if(!*pa)
        return 1;

    int h = altura_arbol(pa);

    if(h<= 2)
        return 1;
    return es_arbol_completo_hasta_nivel(pa,h-2);
}

int es_arbol_avl(const t_arbol* pa)
{
    if(!*pa)
        return 1;
    if(abs(altura_arbol(&(*pa)->pizq) - altura_arbol(&(*pa)->pder))>1)
        return 0;
    return es_arbol_avl(&(*pa)->pizq) && es_arbol_avl(&(*pa)->pder);
}

int altura_arbol(const t_arbol* pa)
{
    if(!*pa)
        return 0;

    int hi  = altura_arbol(&(*pa)->pizq);
    int hd  = altura_arbol(&(*pa)->pder);

    return (hi>hd ? hi : hd)+1;
}



