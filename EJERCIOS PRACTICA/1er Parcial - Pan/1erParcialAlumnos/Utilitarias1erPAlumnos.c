#include "../include/Utilitarias1erPAlumnos.h"
#include "../include/Lista.h"

int comparar_nota(const void* dato1, const void* dato2)
{
    t_nota* n1 = (t_nota*) dato1;
    t_nota* n2 = (t_nota*) dato2;

    return n1->nota - n2->nota;
}

int comparar_dniYmateria(const void* dato1, const void* dato2)
{
    t_nota* n1 = (t_nota*) dato1;
    t_nota* n2 = (t_nota*) dato2;
    int cmp = (n1->dni - n2->dni);

    if(cmp == 0)
        return strcmp(n1->materia,n2->materia);
    if(cmp >0)
        return 1;

    return -1;
}

void actualizar_nota(t_nota* nota1,t_nota* nota2)
{
    if(nota1->nota == 0 || nota2->nota == 0)
    {
        nota1->nota = 0;
        strcpy(nota1->codigo_nota,"AU");
        return;
    }

    else if((nota1->nota >= 7 && nota2->nota >= 7 )
            ||(nota1->nota >=4 && nota1->nota <7 && nota2->nota >=4 && nota2->nota <7)
            ||(nota1->nota <4 && nota2->nota < 4))

            nota1->nota = (int)((float)(nota1->nota + nota2->nota)/2);

    else

        nota1->nota = nota1->nota > nota2->nota ? nota2->nota : nota1->nota;

    nota1->nota >= 7 ?strcpy(nota1->codigo_nota,"PR"):
        nota1->nota >= 4 ?strcpy(nota1->codigo_nota,"CU"): strcpy(nota1->codigo_nota,"RE");
}

//void procesar_lista(t_lista* pLAlu)
//{
//    t_lista* pl=pLAlu;
//    t_dato_lista dato;
//
//
//    while(*pl)
//    {
//        if(lista_sacar_por_clave(&(*pl)->psig,&(*pl)->info,&dato,comparar_dniYmateria))
//            actualizar_nota(&(*pl)->info,&dato);
//
//        pl=&(*pl)->psig;
//    }
//
//    lista_ordenar_asc(pl,comparar_nota);
//}

