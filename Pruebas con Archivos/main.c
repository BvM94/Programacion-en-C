#include "main.h"

int main(int argc, char* argv[])
{
    FILE* pbverduleria;
    FILE* pbverduMovi;
    FILE* pbverduActualizado;

    crear_lote_prueba_productos_verduleria();
    crear_lote_prueba_productos_verduleriaMovimientos();

    pbverduleria=fopen("productosVerduleria","rb");
    pbverduMovi=fopen("MovimientosVerduleria","rb");
    pbverduActualizado=fopen("productosVerduActualizado","wb");

    if(!pbverduleria || !pbverduActualizado || !pbverduMovi)
        return 1;

    mostrar_Archiv_prod_verduleria_binario(pbverduleria);

    mostrar_Archiv_prodMovimiento_verduleria_binario(pbverduMovi);

    actualizar_Productos_verduleria(pbverduleria,pbverduMovi,pbverduActualizado);


    fclose(pbverduActualizado);
    pbverduActualizado= fopen("productosVerduActualizado","rb");

   if(!pbverduActualizado)
        return 1;

    mostrar_Archiv_prod_verduleria_binario(pbverduActualizado);

    fclose(pbverduActualizado);
    fclose(pbverduleria);
    fclose(pbverduMovi);





////    FILE* archProd = fopen(argv[1],"r+b");
////    if(!archProd)
////        return 1;
////
////    crear_lote_prueba_productos();
////
////    t_producto prod;
////
////    fread(&prod,sizeof(t_producto),1,archProd);
////    while(!feof(archProd))
////    {
////        prod.precio*=1.10;
////        fseek(archProd,sizeof(t_producto),SEEK_SET);
////        fwrite(&prod,sizeof(t_producto),1,archProd);
////        fseek(archProd,0L,SEEK_SET);
////        fread(&prod,sizeof(t_producto),1,archProd);
////    }
////
////    fclose(archProd);
//
////////////////////////////////////////////////////////////////////////////////////////
///** MERGE **/
//    FILE* archProd = fopen(argv[1],"rb");
//    FILE* archMov= fopen(argv[2],"rb");
//    FILE* archProdS= fopen(argv[3],"wb");
//
//    if(!archProd || !archMov || !archProdS)
//        return 1;
//
//    t_producto prod,prodS;
//    t_mov mov;
//    int comp;
//
//    fread(&prod,sizeof(t_producto),1,archProd);
//    fread(&mov,sizeof(t_mov),1,archMov);
//    while(!feof(archProd) && !feof(archMov))
//    {
//        comp=strcmp(prod.cod,mov.cod);
//
//        if(comp < 0)
//        {
//            fwrite(&prod,sizeof(t_producto),1,archProdS);
//            fread(&prod,sizeof(t_producto),1,archProd);
//        }
//        if(comp == 0)
//        {
//            prod.cant+=mov.cant;
//            fread(&mov,sizeof(t_mov),1,archMov);
//        }
//        if(comp > 0)
//        {
//            strcpy(prodS.cod,mov.cod);
//            prodS.cant=prod.cant;
//            fwrite(&prodS,sizeof(t_producto),1,archProdS);
//            fread(&mov,sizeof(t_mov),1,archMov);
//        }
//
//    }
//
//    while(!feof(archProd))
//    {
//        fwrite(&prod,sizeof(t_producto),1,archProdS);
//        fread(&prod,sizeof(t_producto),1,archProd);
//
//    }
//    while(!feof(archMov))
//    {
//        strcpy(prodS.cod,mov.cod);
//        prodS.cant=prod.cant;
//        fwrite(&prodS,sizeof(t_producto),1,archProdS);
//        fread(&mov,sizeof(t_mov),1,archMov);
//    }
//
//
//    fclose(archMov);
//    fclose(archProdS);
//    fclose(archProd);
//
//    //////////////////////////////////////////////////////////////////////////////////
//    /**
//    Archivos de texto
//
//    Campos de longitud variable
//    ej:
//    222222222222!Perez,Juan!m!19/1965!305000.30\n
//
//
//    Campos de longitud fija
//    040596....Perez,Juan......m19051965305000.30\n
//    **/
//
//    FILE* bin = fopen(argv[1],"rb");
//    FILE* txt = fopen(argv[2],"rb");
//
//
//    if(!bin || !txt )
//        return 1;
//
//    t_empleado emp;
//
//    fread(&emp,sizeof(t_empleado),1,bin);
//
//    /**De binario a texto  Para longitud  variable **/
//    while(!feof(bin))
//    {
//        fprintf(txt,"%d|%s|%c|%d|%d|%d|%2f\n",emp.dni,emp.apyn,emp.sexo,
//                emp.fNac.d,emp.fNac.m,emp.fNac.a,emp.sueldo);
//        fread(&emp,sizeof(t_empleado),1,bin);
//    }
//
//    /**De binario a texto  Para longitud  fija **/
//
//    while(!feof(bin))
//    {
//        fprintf(txt,"%08d|%-150s|%c|%02d|%02d|%02d|%09.2f\n",emp.dni,emp.apyn,emp.sexo,
//                emp.fNac.d,emp.fNac.m,emp.fNac.a,emp.sueldo);
//        fread(&emp,sizeof(t_empleado),1,bin);
//    }
//
//    /**De texto a binario**/
//
//    FILE* bin = fopen(argv[1],"wb");
//    FILE* txt = fopen(argv[2],"rt");
//    FILE* error = fopen(arf[3],"wt")
//
//
//    if(!bin || !txt || !error )
//        return 1;
//
//    t_empleado emp;
//
//    /**De texto a binario para longitud  variable **/
//    while(fscanf(&txt,"%d|%[^|]|%c|%d|%d|%d|%f",&emp.dni,&emp.apyn,&emp.sexo,
//                 emp.fNac.d,emp.fNac.m,emp.fNac.a,emp.sueldo) != EOF)
//    {
//            fwrite(&emp,sizeof(t_empleado),1,bin);
//    }
//
//    /**De texto a binario para longitud  fija **/
//    char linea[500];
//    int codRetorno;
//    int nrolinea = 0;
//    int fatal = FALSO;
//
//    fgets(linea,500,txt);
//
//    while(!feof(txt))
//    {
//        codRetorno = txtaBin(linea,&emp);
//        if(codRetorno != TODO_OK)
//        {
//            fprintf(error,"Error en Linea%d\n",nrolinea);
//            if(codRetorno == LINEA_LARGA)
//                fatal=VERDADERO;
//        }
//        else
//        {
//            fwrite(&emp,sizeof(t_empleado),1,bin);
//        }
//
//        gets(linea,500,txt);
//    }
//
//    fclose(error);
//    fclose(bin);
//    fclose(txt);
//    return codRetorno;
//
//    }

//||||
    return 0;
}
