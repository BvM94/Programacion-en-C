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
    int nota1,nota2;

    crear_lista(&listaAct);


    pfalu=fopen(path_alus,"rb");
    pfnotas=fopen(path_notas,"rt");
    pfobs=fopen(path_obs,"wt");
    pfacta=fopen(path_acta,"wt");



    if(!pfalu|| !pfnotas|| !pfobs|| !pfacta)
        return;

    fread(&alu,sizeof(t_alumno),1,pfalu);
    retorno=fscanf(pfnotas,"%ld %[^ ] %d",&nota.dni,nota.tipo,&nota.nota);

    acta.p1=0;
    acta.p2=0;
    acta.r1=0;
    acta.r2=0;
    fputs("DNI      APELLIDO Y NOMBRES             P1 P2 R1 R2  NF  COND\n",pfacta);


    while( !feof(pfalu) && EOF != retorno)
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
        if(alu.dni-nota.dni == 0)
        {
            cargar_acta(&acta,&nota);
            retorno=fscanf(pfnotas,"%ld %[^ ] %d",&nota.dni,nota.tipo,&nota.nota);
        }

    }

    while(EOF != retorno)
    {
        fprintf(pfobs,"ERROR, DNI inixistente %ld\n",nota.dni);

        retorno=fscanf(pfnotas,"%ld %[^ ] %d",&nota.dni,nota.tipo,&nota.nota);
    }

    while(!feof(pfalu))
    {
        strcpy(acta.apyn,alu.apyn);
        acta.dni = alu.dni;

        insertar_lista(&listaAct,&acta,comparar_alumnos_dni);

        fread(&alu,sizeof(t_alumno),1,pfalu);

    }

    fclose(pfalu);
    fclose(pfnotas);

    while(sacar_menor_lista(&listaAct,&acta,comparar_alumnos_nombreYdni))
    {
        nota1 = acta.r1 !=0? acta.r1 : acta.p1;
        nota2 = acta.r2 !=0? acta.r2 : acta.p2;

        if(acta.p1 >=7 && acta.r1)
            fprintf(pfobs,"Advertencia,El alumno %s (%ld) Recupero 1 parcial con %d.\n",acta.apyn,acta.dni,acta.p1);

        if(acta.p2 >=7 && acta.r2)
            fprintf(pfobs,"Advertencia,El alumno %s (%ld) Recupero 2 parcial con %d.\n",acta.apyn,acta.dni,acta.p2);

        if(acta.r1 && acta.r2)
        {
            fprintf(pfobs,"Error, El alumno %s (%ld) rindió los 2 recuperatorios.\n",acta.apyn,acta.dni);
            strcpy(acta.cond,"Err");
            acta.nota=0;
        }
        else
        {

            if ((nota1 >= 7 && nota2>=7)||(nota1>=4 && nota2 <=6 && nota2>=4 && nota2>=4)
                    ||(nota1>=1 && nota2 <=3 && nota2>=1 && nota2>=3))
                acta.nota = (nota1+nota2)/2;
            else
                acta.nota = nota1<nota2? nota1:nota2;

            acta.nota>=7?
            strcpy(acta.cond,"Pro"):
            acta.nota>=4?
            strcpy(acta.cond,"Apr"):
            acta.nota>=1?
            strcpy(acta.cond,"Rep"):
            strcpy(acta.cond,"Aus");;
        }

        fprintf(pfacta,"%ld %s\t\t %d %d %d %d %d %s\n",acta.dni,acta.apyn,acta.p1,acta.p2,acta.r1,acta.r2,acta.nota,acta.cond);

    }
    fclose(pfacta);
    fclose(pfobs);

}
