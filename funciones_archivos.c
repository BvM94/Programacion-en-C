#include "funciones_archivos.h"

void crear_lote_prueba_productos_verduleria()
{
    FILE* pfb;

    pfb=fopen("productosVerduleria","wb");
    if(!pfb)
        return;

    t_prodVerduleria vec[]={{"1","papa",50,},
                {"4","tomate",20,5},
                {"7","manzana",10,3.5},
                {"11","lechuga",60,0.50}};

    fwrite(vec,sizeof(vec),1,pfb);
    fclose(pfb);
}

void crear_lote_prueba_productos_verduleriaMovimientos()
{
    FILE* pfb;

    pfb=fopen("MovimientosVerduleria","wb");
    if(!pfb)
        return;

    t_mov vec[]={{"1",-20},
                {"7",2},
                {"15",6},
                {"20",8}};

    fwrite(vec,sizeof(vec),1,pfb);
    fclose(pfb);
}

void mostrar_Archiv_prod_verduleria_binario(FILE* pfb)
{
    t_prodVerduleria prod;

    printf("Codigo\tDescripcion\tStock\tPrecio\n\n");

    fread(&prod,sizeof(t_prodVerduleria),1,pfb);

    while(!feof(pfb))
    {
        printf("%s\t - %s\t - %d\t - %0.2f\n",prod.cod,prod.descr,prod.cant,prod.precio);
        fread(&prod,sizeof(t_prodVerduleria),1,pfb);
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
