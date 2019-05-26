#include<actas.h>
#include<lista.h>
#include<utilitarias.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void generar_acta(const char * path_alus, const char * path_notas, const char * path_acta, const char * path_obs)
{
    FILE* pfalu;
    FILE* pfnotas;
    FILE* pfobs;
    FILE* pfacta;

    t_alumno alu;
    t_nota nota;
    int retorno;
    t_lista listaAct;
    t_acta acta;


    pfalu=fopen(path_alus,"rb");
    pfnotas=fopen(path_notas,"rt");
    pfobs=fopen(path_obs,"wt");
    pfacta=fopen(path_acta,"wt");



    if(pfalu|| pfnotas|| pfobs||pfacta)
        return;

    fread(&alu,sizeof(t_alumno),1,pfalu);
    retorno=fscanf(pfnotas,"%ld %[^ ] %d",&nota.dni,nota.tipo,&nota.nota);

    acta.p1=0;
    acta.p2=0;
    acta.r1=0;
    acta.r2=0;

    while( feof(pfalu) && EOF != retorno)
    {
        if(alu.dni-nota.dni>0)
        {
            fprintf(pfobs,"ERROR, DNI inixistente %ld\n",nota.dni);

            retorno=fscanf(pfnotas,"%ld %[^ ] %d",&nota.dni,nota.tipo,&nota.nota);
        }
        if(alu.dni-nota.dni<0)
        {

            strcpy(acta.apyn,alu.apyn);
            acta.dni = alu.dni;

            insertar_lista(&listaAct,&acta,comparar_alumnos_dni);

            acta.p1=0;
            acta.p2=0;
            acta.r1=0;
            acta.r2=0;

            fread(&alu,sizeof(t_alumno),1,pfalu);
        }

        cargar_acta(&acta,&nota);

        retorno=fscanf(pfnotas,"%ld %[^ ] %d",&nota.dni,nota.tipo,&nota.nota);
    }

    while(EOF != retorno)
    {
        fprintf(pfobs,"ERROR, DNI inixistente %ld\n",nota.dni);

        retorno=fscanf(pfnotas,"%ld %[^ ] %d",&nota.dni,nota.tipo,&nota.nota);
    }

    while(feof(pfalu))
    {
        strcpy(acta.apyn,alu.apyn);
        acta.dni = alu.dni;

        insertar_lista(&listaAct,&acta,comparar_alumnos_dni);

        fread(&alu,sizeof(t_alumno),1,pfalu);

    }

    fclose(pfalu);
    fclose(pfnotas);

    while(sacar_menor_lista(&lista,&acta,comparar_alumnos_nombreYdni))
    {

    }








}
