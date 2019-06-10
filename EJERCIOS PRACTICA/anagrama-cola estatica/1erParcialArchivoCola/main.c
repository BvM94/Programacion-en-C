#include <stdio.h>
#include <stdlib.h>
#include <Cola.h>
#include <ArchivoCola.h>
#include <Utilitarias.h>
#include <string.h>

int main(int argc,char* argv[])
{
    generar_archivo_productos();

    FILE* arch_prod = fopen("../ArchivosDeTest/Productos.dat", "rb");
    FILE* arch_prod_mas_1000 = fopen("../ArchivosDeTest/ProductosMas1000.dat", "wb");
    FILE* arch_prod_menos_1000 = fopen("../ArchivosDeTest/ProductosMenos1000.dat", "wb");

//    FILE* arch_prod = fopen(argv[1],"rb");
//    FILE* arch_prod_mas_1000 = fopen(argv[2],"wb");
//    FILE* arch_prod_menos_1000 = fopen(argv[3],"wb");

    if(!arch_prod || !arch_prod_mas_1000 || !arch_prod_menos_1000)
    {
        puts("Error en apertura archivos");
        return NO_EXISTE;
    }

    puts("Archivo de Productos");
    mostrar_archivo_prod(arch_prod);
    rewind(arch_prod);

    //procesar_arch_productos_res(arch_prod, arch_prod_mas_1000, arch_prod_menos_1000);
    procesar_arch_productos(arch_prod, arch_prod_mas_1000, arch_prod_menos_1000);

    fclose(arch_prod);
    fclose(arch_prod_mas_1000);
    fclose(arch_prod_menos_1000);

    arch_prod_mas_1000 = fopen("../ArchivosDeTest/ProductosMas1000.dat", "rb");
    arch_prod_menos_1000 = fopen("../ArchivosDeTest/ProductosMenos1000.dat", "rb");

    if(!arch_prod_mas_1000 || !arch_prod_menos_1000)
    {
        puts("Error en apertura archivos");
        return 1;
    }

    printf("Archivo de productos de costo mayor a $1000\n");
    mostrar_archivo_prod(arch_prod_mas_1000);

    printf("Archivo de productos de costo menor a $1000\n");
    mostrar_archivo_prod(arch_prod_menos_1000);

    fclose(arch_prod_mas_1000);
    fclose(arch_prod_menos_1000);

    return 0;
}


//typedef struct
//{
//    char cod_art[7];
//    char cod_mat_pri[7];
//    int cantidad;
//    float costo_unit;
//}
//t_mat_prima_art;

void procesar_arch_productos(FILE* arch_prod,FILE* arch_prod_mas_1000,FILE* arch_prod_menos_1000)
{
    t_cola cola;
    t_mat_prima_art producto, producto_anterior;
    float costo;

    crear_cola(&cola);

    fread(&producto,sizeof(t_mat_prima_art),1,arch_prod);

    while(!feof(arch_prod))
    {
        producto_anterior = producto;
        costo=0;
        while(!feof(arch_prod) && strcmp(producto.cod_art,producto_anterior.cod_art)== 0)
        {
            costo += producto.cantidad*producto.costo_unit;
            poner_en_cola(&cola,&producto);
            producto_anterior = producto;
            fread(&producto,sizeof(t_mat_prima_art),1,arch_prod);
        }
        if(costo > 1000)
            while(sacar_de_cola(&cola,&producto_anterior))
                fwrite(&producto_anterior,sizeof(t_mat_prima_art),1,arch_prod_mas_1000);

        else
            while(sacar_de_cola(&cola,&producto_anterior))
                fwrite(&producto_anterior,sizeof(t_mat_prima_art),1,arch_prod_menos_1000);

    }

}







