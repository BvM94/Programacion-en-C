#include<arbol.h>

int es_arbol_avl(const t_arbol* pa)
{
    ///Escriba aqui el codigo
    if(!*pa)
        return 1;
    if(abs(altura_arbol(&(*pa)->pizq) - altura_arbol_res(&(*pa)->pder))>1) ///reeemplazar altura arbol por la mia
       return 0;

    return  es_arbol_avl(&(*pa)->pizq) && es_arbol_avl(&(*pa)->pder);
}
int es_arbol_balanceado(const t_arbol* pa)
{
    ///Escriba aqui el codigo
    int h=altura_arbol(pa); ///reemplazar la mia
    if( h <= 2 )
        return 1;

    return es_completo_hasta_nivel(pa,h-2);
}
int es_arbol_completo(const t_arbol* pa)
{
    ///Escriba aqui el codigo
    int h=altura_arbol(pa); ///reemplazar altura_arbol
    if(h-1 <= 0)
        return 1;

    return es_completo_hasta_nivel(pa,h-1);
}

int es_completo_hasta_nivel(const t_arbol * pa,const int nivel)
{

    if(!*pa || nivel==0)
        return (int)*pa;

   return (es_completo_hasta_nivel(&(*pa)->pizq,nivel-1) &&
   es_completo_hasta_nivel(&(*pa)->pder,nivel-1) );
}

int altura_arbol(const t_arbol* pa)
{
    int hizq , hder;
    if(!*pa)
        return 0;
    hizq = altura_arbol(&(*pa)->pizq);
    hder = altura_arbol(&(*pa)->pder);

    return (hizq > hder? hizq : hder ) + 1;
}

void recorrer_arbol_enOrden(const t_arbol* pa, t_accion accion, void* datos_accion)
{
    if(!*pa)
        return;

    recorrer_arbol_enOrden(&(*pa)->pizq,accion,datos_accion);
    accion(&(*pa)->info,datos_accion);
    recorrer_arbol_enOrden(&(*pa)->pder,accion,datos_accion);
}
