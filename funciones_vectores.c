#include "funciones_vectores.h"


//inserta valor en el vector de manera ordenada y sin permitir duplicados

int vec_insertar_ordenado(int* vec,int* ce,const int* tam,const int *valor)
{
    int *pl,*pe;
    pl= vec + *ce-1;
    pe= vec + *ce;

    if( *ce==0 || *valor < *pl)
    {
        if(*ce == 0)
            *pe= *valor;

        else
        {
            if(*ce == *tam)
            {
                pe--;
                pl--;
            }
            while(*pl> *valor && pl >= vec )
            {
                *pe=*pl;
                pl--;
                pe--;
            }

            if(*pe == *valor) // contempla que no haya repetidos
                return ERROR;

            *pe = *valor;
        }
    }

    else if ( *ce < *tam )
        if(*pl == *valor)
            return ERROR;
        *pe = *valor;

    if (*ce < *tam)
        (*ce)++;

    return TODO_OK;
}

int vec_eliminar_primer_aparicion(int* vec, int* ce, const int* tam,const int* valor)
{
    int* finVec= vec +(*ce);
    int* pl;
    if(*ce == 0)
        return ERROR;

    while(*vec < *valor && vec < finVec )
        vec++;

    pl = vec+1;

    if(*vec == *valor)
    {
       while(vec<finVec)
       {
           *vec=*pl;
           vec++;
           pl++;
       }
       (*ce)--;
       return TODO_OK;
    }

    return ERROR;
}


int vec_eliminar_ocurrencias(int* vec, int* ce, const int* tam,const int* valor)
{
    int* vecFin = vec + (*ce);
    int* pl=vec;
    int ocurrencia=0;

    if(*ce == 0)
        return ERROR;

    while( pl < vecFin)
    {
        if(*pl == *valor)
        {
            pl++;
            ocurrencia++;
        }
        else
        {
         *vec = *pl;
         pl++;
         vec++;
        }
    }

    (*ce)-=ocurrencia;

    return ocurrencia>0?TODO_OK : ERROR;
}

void orden_por_Seleccion_Ascendente(int * vec, int* ce)
{
    int *i,*m;
    int* ultimo = v+*ce-1

    for(i=v,i< ultimo,i++)
    {

        m=buscar_menor(i,ult); //busca menor entre dos posiciones

        if(m!=i)
            intercambiar_ints(m,i);
    }
}

int* buscar_menor(int* d, int* h)
{
   int* m = d;
   int* j;

   for(j=d+1;j <= h , j++)
       if(*j < *m)
            m=j;
    return m;
}

void intercambio_ints(int* a, int* b)
{
    int aux = *a;
    (*a)=*b;
    (*b)=aux;
}

void orden_seleccion_asc_generico(void* v, int* ce,size_t tamElem,t_cmp comparar)
{
    void *i,*m;
    void* ultimo = v+(*ce-1)*tamElem;

    for(i=v,i< ultimo,i+=tamElem)
    {

        m=buscar_menor_generica(i,ult,tamElem,comparar); //busca menor entre dos posiciones de memoria

        if(m!=i)
            intercambiar_elementos(m,i,tamElem);
    }
}

void* buscar_menor_generica(void* d, void* h, size_t tamElem,t_cmp comparar)
{
   void* m = d;
   void* j;

   for(j=d+tamElem;j <= h , j+=tamElem)
       if(compara(j,m)<0)
            m=j;
    return m;
}

int intercambiar_elementos(void *a , void*b, size_t tamElem)
{
    void * aux = malloc(tamElem);

    if(aux == NULL )
        return 0;

    memcpy(aux,a,tamElem);
    memcpy(a,b,tamElem);
    memcpy(b,aux,tamElem);

    free(aux);
}
