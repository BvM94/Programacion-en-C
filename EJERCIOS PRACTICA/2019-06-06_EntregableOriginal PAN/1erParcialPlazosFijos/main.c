#include <stdio.h>
#include <stdlib.h>

#include <PlazoFijo.h>
#include <Lista.h>
#include <Solucion1erParcialPlazosFijos.h>


void cargarListaPF(FILE* plazosFijosTxt, t_lista* plazosFijosList);
float calcular_interes(t_fecha *f_proceso , t_plazo_fijo *p);


int main(int argc, char* argv[])
{
    generarArchivos(argv[1], argv[2]);

    if(argc != 4)
    {
        puts("Cantidad incorrecta de parámetros.");
        return 1;
    }

    puts("Cuentas antes de actualizar:");
    mostrarCuentas(argv[1]);

    FILE* cuentasDat = fopen(argv[1], "r+b");
    FILE* plazosFijosTxt = fopen(argv[2], "rt");

    if(!cuentasDat || !plazosFijosTxt)
        return 2;

    t_fecha fechaProceso;
    int fechaOk = txt_a_fecha(argv[3], &fechaProceso);

    if(!fechaOk)
        return 3;

    t_lista plazosFijosList;
    crear_lista_res(&plazosFijosList);

    cargarListaPF(plazosFijosTxt, &plazosFijosList);
    //cargarListaPF_res(plazosFijosTxt, &plazosFijosList);

    fclose(plazosFijosTxt);

    procesarPF(cuentasDat, &plazosFijosList, &fechaProceso);
    //procesarPF_res(cuentasDat, &plazosFijosList, &fechaProceso);

    fclose(cuentasDat);

    puts("\nCuentas despues de actualizar:");
    mostrarCuentas(argv[1]);

    return 0;
}



//typedef struct
//{
//    int nroPF;
//    int cuenta;
//    float monto;
//    float interesAnual;
//    t_fecha fechaConstitucion;
//    int dias;
//}
//t_plazo_fijo;

int comparar_cuenta(const void* plazo1, const void* plazo2)
{
    t_plazo_fijo* p1= (t_plazo_fijo*)plazo1;
    t_plazo_fijo* p2= (t_plazo_fijo*)plazo2;

    return p1->cuenta - p2->cuenta;
}

void cargarListaPF(FILE* plazosFijosTxt, t_lista* plazosFijosList)
{
    ///Inserte el código aquí.
    t_plazo_fijo plazo;


    while(EOF != fscanf(plazosFijosTxt,"%d|%d|%f|%f|%d/%d/%d|%d",
                  &plazo.nroPF,&plazo.cuenta,&plazo.monto,&plazo.interesAnual,
                  &plazo.fechaConstitucion.d,&plazo.fechaConstitucion.m,&plazo.fechaConstitucion.a,&plazo.dias))

        lista_insertar_en_orden_asc(plazosFijosList,&plazo,comparar_cuenta);
}



//
//    Monto  % Interés  Fecha constitución  Días | Fecha Venc.  Retorno a la cuenta
//    $2500  40%	        05/3/2019	     	 30     4/4/2019     $2500 +  30/365 * 40/100 * $2500 = $2582,19


float calcular_interes(t_fecha *f_proceso , t_plazo_fijo *p)
{
    float interes = 0;
    t_fecha f_venc;


    sumar_dias_a_fecha(&p->fechaConstitucion,p->dias,&f_venc);
    if(cmpFechas(&f_venc,f_proceso)< 0)
        interes = p->monto * ((float)p->dias)/365 * p->interesAnual/100;

    return interes;
}

void procesarPF(FILE* cuentasDat, t_lista* plazosFijosList, t_fecha* fechaProceso)
{
    ///Inserte el código aquí.
    t_cuenta cuenta;
    t_plazo_fijo plazo;
    int retorno;
    float sum=0;
    float interes=0;

    fread(&cuenta,sizeof(t_cuenta),1,cuentasDat);
    retorno = lista_sacar_primero(plazosFijosList,&plazo);


    while(!feof(cuentasDat) && retorno )
    {
        if(cuenta.cuenta == plazo.cuenta)
        {
            //acumulo plazo
            interes+=calcular_interes(fechaProceso,&plazo);
            sum += (plazo.monto + interes);
            interes = 0;
            retorno = lista_sacar_primero(plazosFijosList,&plazo);
        }
        if(cuenta.cuenta < plazo.cuenta)
        {
            cuenta.saldo += sum;
            sum=0;
            fseek(cuentasDat,-sizeof(t_cuenta),SEEK_CUR);
            fwrite(&cuenta,sizeof(t_cuenta),1,cuentasDat);
            fseek(cuentasDat,0L,SEEK_CUR);
            fread(&cuenta,sizeof(t_cuenta),1,cuentasDat);
        }
        else
        {
            retorno = lista_sacar_primero(plazosFijosList,&plazo);
        }

    }
}


