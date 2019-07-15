#include<arbol.h>
#include <utilitarias.h>

int insertar_en_arbol_bin_busq(t_arbol* pa, const t_info* pd, t_cmp cmp) ///Retorna TODO_OK o DUPLICADO
{
    ///Escriba aqui el codigo...
    if(!*pa)
    {
        *pa  = (t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
        if(!*pa)
            return SIN_MEM; ///ARBOL LLENO
        (*pa)->info = *pd;
        (*pa)->pizq = (*pa)->pder = NULL;
        return TODO_OK;
    }

    int comp  = cmp(pd, &(*pa)->info);
    if(comp == 0)
        return DUPLICADO;

    if(comp < 0)
        return insertar_en_arbol_bin_busq(&(*pa)->pizq,pd,cmp);
    else
        return insertar_en_arbol_bin_busq(&(*pa)->pder,pd,cmp);
}

int insertar_arbol_balanceado(t_arbol *pa,FILE * arch, int i, int d, t_cmp cmp)
{
    if(i>d)
        return TODO_OK;

    int m = (i+d)/ 2;
    t_reg_ind dato;

    fseek(arch,sizeof(t_reg_ind)* m,SEEK_SET);
    fread(&dato,sizeof(t_reg_ind),1,arch);

    int ret   = insertar_en_arbol_bin_busq(pa,&dato,cmp);

    if(ret != TODO_OK)
        return ret;
    ret = insertar_arbol_balanceado(pa,arch,i,m-1,cmp);
    if(ret != TODO_OK)
        return ret;

    return insertar_arbol_balanceado(pa,arch,m+1,d,cmp);
}

int buscar_en_arbol_bin_busq(const t_arbol* pa, t_info* pd, t_cmp cmp) ///Retorna VERDADERO o FALSO
{
    ///Escriba aqui el codigo...
    return VERDADERO;
}

int eliminar_de_arbol(t_arbol* pa, t_info* pd, t_cmp cmp) ///Retorna TODO_OK o NO_EXISTE
{
    ///OPCIONAL: Debe elegir entre esta funcion y cargar_arbol_de_archivo_ordenado

    t_nodo_arbol ** pnae = buscar_nae(pa,pd,cmp);

    if(!(*pnae))
        return NO_EXISTE;
    *pd = (*pnae)->info;

    eliminar_nodo(pnae);
    return TODO_OK;
}

t_nodo_arbol ** buscar_nae(const t_arbol *pa,t_info *pd,t_cmp cmp)
{
    if(!*pa)
        return NULL;
    int comp = cmp(pd,&(*pa)->info);
    if(comp == 0)
        return (t_nodo_arbol**)pa;
    if(comp < 0)
        return buscar_nae(&(*pa)->pizq,pd,cmp);
    else
        return buscar_nae(&(*pa)->pder,pd,cmp);
}

void eliminar_nodo(t_nodo_arbol ** pnae)
{
    if(*pnae && !(*pnae)->pizq && !(*pnae)->pder)
    {
        free(*pnae);
        *pnae = NULL;
        return;
    }

    t_nodo_arbol ** pnreempl = altura_arbol(&(*pnae)->pizq) > altura_arbol(&(*pnae)->pder) ?
                               mayor(&(*pnae)->pizq) : menor(&(*pnae)->pder) ;

    (*pnae)->info = (*pnreempl)->info;

    eliminar_nodo(pnreempl);
}

t_nodo_arbol** menor_mia(t_arbol *pa)
{
    if(!*pa)
        return NULL;

    t_nodo_arbol ** menor = pa;

    while(*pa && (*pa)->pizq)
    {
        menor = pa;
        pa = &(*pa)->pizq;
    }
    return menor;
}

t_nodo_arbol** mayor_mia(t_arbol *pa)
{
    if(!*pa)
        return NULL;

    t_nodo_arbol ** mayor = pa;

    while(*pa && (*pa)->pizq)
    {
        mayor = pa;
        pa = &(*pa)->pizq;
    }
    return mayor;
}

int cargar_arbol_de_archivo_ordenado(t_arbol* pa, const char* path) ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
{
    ///OPCIONAL: Debe elegir entre esta funcion y eliminar_de_arbol
    FILE * arch = fopen(path,"rt");

    if(!arch)
        return ERROR_ARCHIVO;
    fseek(arch,0l,SEEK_END);
    int i = 0, d = ftell(arch)/sizeof(t_reg_ind) - 1 ;

    return insertar_arbol_balanceado(pa,arch,i, d, comparar_ind);
}



int es_arbol_balanceado(const t_arbol *pa)
{
    if(!*pa)
        return 1;
    int h = altura_arbol_mia(pa);
    if(h <= 2)
        return 1;

    return es_completo_hasta_nivel(pa,h-2);
}

int es_completo_hasta_nivel(const t_arbol *pa, int nivel)
{
    if(!*pa || nivel == 0)
        return (int)*pa;

    return es_completo_hasta_nivel(&(*pa)->pizq,nivel-1) && es_completo_hasta_nivel(&(*pa)->pder,nivel-1);
}

int altura_arbol_mia(const t_arbol* pa)
{
    if(!*pa)
        return 1;
    int hi = altura_arbol(&(*pa)->pizq);
    int hd = altura_arbol(&(*pa)->pder);

    return (hi > hd ? hi : hd)+1;
}

void recorrer_Enorden(const t_arbol *pa,t_mostrar_clave acc)
{
    if(!*pa)
        return;

    recorrer_Enorden(&(*pa)->pizq,acc);
    acc(&(*pa)->info);
    recorrer_Enorden(&(*pa)->pder,acc);
}
