#include<banco.h>
#include<lista.h>
#include<utilitarias.h>
#include<string.h>
#include<stdlib.h>

void actualizar_cuentas(FILE * arch_ctas, const char * path_movs)
{
    FILE * pf_mov;
    t_movimiento_banco movimiento;
    t_cuenta_banco cuenta;
    char Cadmov[100];
    t_lista listaMov;
    int retorno;


    crear_lista(&listaMov);
    fseek(arch_ctas,0,SEEK_SET);

    pf_mov =fopen(path_movs,"rt");

    if(!pf_mov)
        return;

    while(fgets(Cadmov,100,pf_mov))
    {
        texto_a_movimiento(Cadmov,&movimiento);

        instertar_lista(&listaMov,&movimiento,comparar_movimientos,acumular_movimiento);
    }
/////////////////////////////////////////////
//    retorno = sacar_primero_lista(&listaMov,&movimiento);
//    while(retorno)
//    {
//        printf("%s - %c - %f\n",movimiento.cod_cta,movimiento.tipo_mov,movimiento.importe);
//        retorno = sacar_primero_lista(&listaMov,&movimiento);
//    }
//    puts("---------------------------------------------------------------------------------------------");
//////////////////////////////////////////////////
    fread(&cuenta,sizeof(t_cuenta_banco),1,arch_ctas);
    retorno = sacar_primero_lista(&listaMov,&movimiento);

    while(!feof(arch_ctas) && retorno)
    {
        if(strcmp(cuenta.cod_cta,movimiento.cod_cta)<0)
        {
            //GRABAR cuenta
            fseek(arch_ctas,-sizeof(t_cuenta_banco),SEEK_CUR);
            fwrite(&cuenta,sizeof(t_cuenta_banco),1,arch_ctas);
            fseek(arch_ctas,0,SEEK_CUR);
            fread(&cuenta,sizeof(t_cuenta_banco),1,arch_ctas);
        }

        else if(strcmp(cuenta.cod_cta,movimiento.cod_cta)==0)
        {
            //ACTUALIZAR CUENTA ver si es D- o C+
            cuenta.saldo += (movimiento.tipo_mov== 'D'? (-movimiento.importe):movimiento.importe);

            retorno = sacar_primero_lista(&listaMov,&movimiento);
        }

        else
        {
            retorno = sacar_primero_lista(&listaMov,&movimiento);
        }
    }

    fclose(pf_mov);

}
