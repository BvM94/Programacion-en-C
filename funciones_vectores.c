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
