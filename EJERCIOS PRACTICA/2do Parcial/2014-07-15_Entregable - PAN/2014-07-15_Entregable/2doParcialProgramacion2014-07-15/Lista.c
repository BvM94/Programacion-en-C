#include "../include/Lista.h"

int insertar_en_lista_ord(t_lista* pl, const t_dato* pd, t_cmp cmp)
{
    t_nodod * sig,*ant;
    ant =(*pl);
    sig = ant? ant->psig: NULL;

    t_nodod * nue = (t_nodod*) malloc(sizeof(t_nodod));

    if(!nue)
        return 0; ///LISTA LLENA
    while(ant && cmp(pd,&(*pl)->info)<0)
    {
        sig=ant;
        ant=ant->pant;
    }

    while(sig && cmp(pd,&(*pl)->info)>0)
    {
        ant=sig;
        sig= sig->psig;
    }

    if(ant && cmp(pd,&(*pl)->info)==0)
        return 2; ///DUPLICADO
    if(sig && cmp(pd,&(*pl)->info)==0)
        return 2; ///DUPLICADO

    nue->info = *pd;
    nue->psig = sig;
    nue->pant = ant;
    *pl = nue;

    if(ant)
        ant->psig = nue;
    if(sig)
        sig->pant = nue;

    return 1; ///TODO_OK
}

void recorrer_lista(const t_lista* pl, t_accion accion, void* datos_accion)
{
    if(!*pl)
        return;

    t_nodod * mov = *pl;

    while(mov->pant)
        mov=mov->pant;

    while(mov)
    {
        accion(&(mov)->info,datos_accion);
        mov=mov->psig;
    }
}



//int insertar_en_lista_ord(t_lista* pl, const t_dato* pd, t_cmp cmp)
//{
//	///Inserte el código acá
//	if (pl==NULL)
//        return LISTA_VACIA;
//	t_lista *aux=NULL;
//    t_nodod *nuevo_elemento=(t_nodod*)malloc(sizeof(t_nodod));
//    if (nuevo_elemento==NULL)
//        return SIN_MEM;
//    aux=*pl;
//    nuevo_elemento->info=*pd;
//    if ((*aux)->psig==NULL && (*aux)->pant==NULL) //La lista tiene un solo elemento
//    {
//        nuevo_elemento->pant=(*aux)->pant;
//        nuevo_elemento->psig=(*aux)->psig;
//    }else{
//        while(aux!=NULL && cmp(&((*aux)->info),&pd)==1)
//        {
//                aux = (*aux)->psig;
//        }
//        if (aux==NULL) //Llegue al ultimo elemento
//        {
//            nuevo_elemento->pant=*aux;
//            nuevo_elemento->psig=(*aux)->psig; //Igual a NULL
//            return TODO_OK;
//        }else{
//
//            nuevo_elemento->pant=*aux;
//            nuevo_elemento->psig=(*aux)->pant;
//            *pl=aux;
//        }
//
//    }
//}
//
//
//void recorrer_lista(const t_lista* pl, t_accion accion, void* datos_accion)
//{
//
//	while(*pl!=NULL && accion(&pl,&datos_accion))
//    {
//         *pl=(*pl)->psig;
//    }
//}
