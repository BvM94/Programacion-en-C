#include "funciones_archivos.h"

void crear_lote_prueba_productos_verduleria()
{
    FILE* pfb;

    pfb=fopen("productosVerduleria","wb");
    if(!pfb)
        return;

    t_prodVerduleria vec[]= {{"A1","papa",50,},
        {"A4","tomate",20,5},
        {"A7","manzana",10,3.5},
        {"A11","lechuga",60,0.50}
    };

    fwrite(vec,sizeof(vec),1,pfb);
    fclose(pfb);
}

void crear_lote_prueba_productos_verduleriaMovimientos()
{
    FILE* pfb;

    pfb=fopen("MovimientosVerduleria","wb");
    if(!pfb)
        return;

    t_mov vec[]= {{"A1",-20},
        {"A7",2},
        {"A77",6},
        {"A78",8}
    };

    fwrite(vec,sizeof(vec),1,pfb);
    fclose(pfb);
}

void mostrar_Archiv_prod_verduleria_binario(FILE* pfb)
{
    t_prodVerduleria prod;

    fseek(pfb,0L,SEEK_SET);

    printf("Codigo\tDescripcion\tStock\tPrecio\n\n");

    fread(&prod,sizeof(t_prodVerduleria),1,pfb);

    while(!feof(pfb))
    {
        printf("%-6s\t - %-6s\t - %d\t - %0.2f\n",prod.cod,prod.descr,prod.cant,prod.precio);
        fread(&prod,sizeof(t_prodVerduleria),1,pfb);
    }
}

void mostrar_Archiv_prodMovimiento_verduleria_binario(FILE* pfb)
{
    t_mov mov ;

    fseek(pfb,0L,SEEK_SET);

    printf("Codigo\tStock\n\n");

    fread(&mov,sizeof(t_mov),1,pfb);

    while(!feof(pfb))
    {
        printf("%-6s\t - %d\t\n",mov.cod,mov.cant);
        fread(&mov,sizeof(t_mov),1,pfb);
    }
}

void actualizar_Productos_verduleria(FILE* pbhistorico,FILE* pbmov,FILE*pbfinal)
{
    t_prodVerduleria prod,prodAUX;
    t_mov mov;

    fseek(pbhistorico,0L,SEEK_SET);
    fseek(pbmov,0L,SEEK_SET);

    fread(&prod,sizeof(t_prodVerduleria),1,pbhistorico);
    fread(&mov,sizeof(t_mov),1,pbmov);

    while(!feof(pbhistorico) && !feof(pbmov))
    {
        if(strcmp(prod.cod,mov.cod)<0)
        {
            fwrite(&prod,sizeof(t_prodVerduleria),1,pbfinal);
            fread(&prod,sizeof(t_prodVerduleria),1,pbhistorico);
        }
        if(strcmp(prod.cod,mov.cod)==0)
        {
            prod.cant += mov.cant;
            fread(&mov,sizeof(t_mov),1,pbmov);
        }
        if(strcmp(prod.cod,mov.cod)>0)
        {
            strcpy(prodAUX.cod,mov.cod);
            prodAUX.cant=mov.cant;

            fwrite(&prodAUX,sizeof(t_prodVerduleria),1,pbfinal);
            fread(&mov,sizeof(t_mov),1,pbmov);
        }
    }
    while(!feof(pbhistorico))
    {
        fwrite(&prod,sizeof(t_prodVerduleria),1,pbfinal);
        fread(&prod,sizeof(t_prodVerduleria),1,pbhistorico);
    }

    while(!feof(pbmov))
    {
        strcpy(prodAUX.cod,mov.cod);
        prodAUX.cant=mov.cant;

        fwrite(&prodAUX,sizeof(t_prodVerduleria),1,pbfinal);
        fread(&mov,sizeof(t_mov),1,pbmov);
    }


}




//int txtVariableABin (char* linea,t_empleado *emp)
//{
//    char* iniC=linea, * act;
//    int codRet;
//    act=strchr(linea,'\n');
//    if(!act)
//        return LINEA_LARGA;
//    *act = '\0';
//
//    act=strchr(linea,'|');
//
//    *act = '\0';
//
//    codRet= txtAentero(iniC,&emp->dni);
//    if(codRet != TODO_OK)
//        return codRet;
//    iniC = act+1;
//
//    act=strchr(linea,'|');
//    *act = '\0';
//
//    normalizarAyN(iniC,emp->apyn);
//    iniC = act+1;
//    emp->sexo = *inic;
//
//    iniC = act+2;
//
//    act= strchr(iniC,'|');
//    *act=txtAFecha(iniC,&emp->fNac);
//
//    if(codRet != TODO_OK)
//        return codRet;
//
//    iniC = act+1;
//    codRet=txtAReal(iniC,&emp->sueldo);
//
//
//    return TODO_OK;
//}
//
//
//int txtAReal (char * numstr,float*real)
//{
//    char* i = numstr;
//    while(*i !='\0' && es_digito (*i))
//        i++;
//    if(*i != '.')
//        return CAMPO_INVALIDO;
//    i++;
//    while(*i != '\0' && es_digito (*i))
//        i++;
//    if(*i != '\0')
//        return CAMPO_INVALIDO
//    sscanf(numstr,"%f",real);
//
//
//}
