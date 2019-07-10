#include "arbol_funciones.h"

void crear_arbol(t_arbol * pa)
{
    *pa = NULL;
}

int insertar_en_arbol_ordenado(t_arbol * pa, t_dato *pd,t_cmp cmp)
{
    if(!*pa)
    {
        *pa = (t_nodo_ar*) malloc(sizeof(t_nodo_ar));
        if(!*pa)
            return 0; ///arbol lleno
        (*pa)->info = *pd;
        (*pa)->hder = (*pa)->hizq = NULL;
        return 1; ///todo ok
    }
    int comp = cmp(pd,&(*pa)->info);

    if(comp == 0)
        return 2 ; ///DUPLICADO
    if(comp > 0)
        return insertar_en_arbol_ordenado(&(*pa)->hder,pd,cmp);
    else
        return insertar_en_arbol_ordenado(&(*pa)->hizq,pd,cmp);
}


int Cargar_arbolBalanceado_desdeArchOrden(t_arbol * pa, FILE * arch,t_cmp cmp)
{
    int i =0;
    fseek(arch,0L,SEEK_SET);
    int d = (ftell(arch)/sizeof(t_dato))-1;

    return insertar_balanceado(pa,arch,i,d,cmp);
}

int insertar_balanceado(t_arbol *pa, FILE* arch, int i,int d,t_cmp cmp)
{
    if(i>d)
        return 1; ///todo ok

    int m = (i+d)/2;
    t_dato info;

    fseek(arch,sizeof(t_dato)*m,SEEK_SET);
    fread(&info,sizeof(t_dato),1,arch);

    int ret=insertar_en_arbol_ordenado(pa,&info,cmp);

    if(ret != 1)
        return ret;

    ret = insertar_balanceado(pa,arch,i, m-1,cmp);
    if(ret!= 1)
        return ret;
    else
        return insertar_balanceado(pa,arch,m+1,d,cmp);
}

int eliminar_de_arbol(t_arbol * pa, t_dato *pd, t_cmp cmp)
{
    t_nodo_ar ** pnae = buscar_nae(pa,pd,cmp);

    if(!*pnae)
        return 0; /// no existe

    eliminar_nodo(pnae);
    return 1; /// todo ok
}

void eliminar_nodo(t_nodo_ar ** pnae)
{
    if(!(*pnae)->hizq &&  !(*pnae)->hder)
    {
        free(*pnae);
        *pnae =NULL;
        return;
    }

    t_nodo_ar ** pnreempl = altura_del_arbol(&(*pnae)->hizq ) > altura_del_arbol(&(*pnae)->hder) ? mayor(&(*pnae)->hizq) : menor(&(*pnae)->hder);

    (*pnae)->info = (*pnreempl)->info;

    eliminar_nodo(pnreempl);
}

t_nodo_ar ** mayor(t_arbol *pa)
{
    while(*pa && (*pa)->hder)
        pa = &(*pa)->hder;
    return pa;
}

t_nodo_ar ** menor(t_arbol *pa)
{
    while(*pa && (*pa)->hizq)
        pa = &(*pa)->hizq;
    return pa;
}

t_nodo_ar** buscar_nae(t_arbol *pa,t_dato *pd,t_cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp = cmp(pd,&(*pa)->info);
    if(comp == 0)
        return pa;
    if(comp < 0 )
        return buscar_nae(&(*pa)->hizq,pd,cmp);
    else
        return buscar_nae(&(*pa)->hder,pd,cmp);
}

int altura_del_arbol (const t_arbol * pa)
{
    if(!*pa)
        return 0;
    int hi = altura_del_arbol(&(*pa)->hizq);
    int hd = altura_del_arbol(&(*pa)->hder);

    return ( hi>hd ? hi : hd)+1;
}


int arbol_completo (const t_arbol *pa)
{
    int h=altura_del_arbol(pa);
    if(h<=1)
        return 1;

    return arbol_completo_hasta_nivel(pa,h-1);
}
int arbol_avl (const t_arbol *pa)
{
    if(!*pa)
        return 1;
    if(abs(altura_del_arbol(&(*pa)->hizq)- altura_del_arbol(&(*pa)->hizq)) > 1)
        return 0;

    return arbol_avl(&(*pa)->hizq) && arbol_avl(&(*pa)->hizq);
}

int arbol_balanceado (const t_arbol *pa)
{
    int h = altura_del_arbol(pa);
    if(h<=2)
        return 1;

    return arbol_completo_hasta_nivel(pa,h-2);
}

int tipo_deArbol(const t_arbol *pa)  ///retorna 1 = completo , 2 = balanceado , 3 = avl y 0 = desbalanceado;
{
    if(arbol_completo(pa))
        return 1;
    if(arbol_balanceado(pa))
        return 2;
    if(arbol_avl(pa))
        return 3;
    return 0;
}


int arbol_completo_hasta_nivel(const t_arbol * pa, int nivel)
{
    if(!*pa || nivel == 0)
        return (int)*pa;
    return arbol_completo_hasta_nivel(&(*pa)->hizq,nivel-1) && arbol_completo_hasta_nivel(&(*pa)->hizq,nivel-1);
}

void podar_arbol_desde_nivel(t_arbol *pa, int nivel)
{
    if(!*pa)
        return;
    if(nivel == 0)
    {
        vaciar_arbol(pa);
        return;
    }

    podar_arbol_desde_nivel(&(*pa)->hizq,nivel-1);
    podar_arbol_desde_nivel(&(*pa)->hder,nivel-1);
}

void podar_arbol_hasta_nivel(t_arbol *pa, int nivel)
{
    if(!*pa || nivel < 0)
        return;

    podar_arbol_hasta_nivel(pa,nivel-1);
    podar_arbol_hasta_nivel(pa,nivel-1);
    eliminar_nodo(pa);
}

void vaciar_arbol (t_arbol *pa)
{
    if(!*pa)
        return;

    vaciar_arbol(&(*pa)->hizq);
    vaciar_arbol(&(*pa)->hder);

    free(*pa);
    *pa =NULL;
}

void recorrer_preorden(t_arbol *pa, t_accion accion,t_dato dato_accion)
{
    if(!*pa)
        return;
    accion(&(*pa)->info);
    recorrer_preorden(&(*pa)->hizq,accion,dato_accion);
    recorrer_preorden(&(*pa)->hder,accion,dato_accion);
}
void recorrer_Enorden(t_arbol *pa, t_accion accion,t_dato dato_accion)
{
    if(!*pa)
        return;
    recorrer_Enorden(&(*pa)->hizq,accion,dato_accion);
    accion(&(*pa)->info);
    recorrer_Enorden(&(*pa)->hder,accion,dato_accion);
}
void recorrer_posorden(t_arbol *pa, t_accion accion,t_dato dato_accion)
{
    if(!*pa)
        return;
    recorrer_preorden(&(*pa)->hizq,accion,dato_accion);
    recorrer_preorden(&(*pa)->hder,accion,dato_accion);
    accion(&(*pa)->info);
}

void buscar_mayor_arbol_NO_clave(const t_arbol *pa,t_dato *pd,t_cmp cmp)
{
    if(!*pa)
        return;
    *pd  = (*pa)->info;
    buscar_mayor_sin_clave(&(*pa)->hder,pd,cmp);
    buscar_mayor_sin_clave(&(*pa)->hizq,pd,cmp);
}

void buscar_mayor_sin_clave(const t_arbol *pa,t_dato *pd,t_cmp cmp)
{
    if(!*pa)
        return;

    if(cmp(&(*pa)->info,pd) > 0)
       *pd = (*pa)->info;

    buscar_mayor_sin_clave(&(*pa)->hder,pd,cmp);
    buscar_mayor_sin_clave(&(*pa)->hizq,pd,cmp);
}

int cantidad_hojas_del_arbol(const t_arbol *pa)
{
    if(!*pa )
        return 0;
    if(!(*pa)->hder && !(*pa)->hizq)
        return 1;

    return cantidad_hojas_del_arbol(&(*pa)->hizq) + cantidad_hojas_del_arbol(&(*pa)->hder);
}

