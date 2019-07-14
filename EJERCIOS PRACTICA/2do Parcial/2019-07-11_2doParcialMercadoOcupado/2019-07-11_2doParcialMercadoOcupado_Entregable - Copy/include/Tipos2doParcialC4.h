#ifndef TIPOS2DOPARCIALC4_H
#define TIPOS2DOPARCIALC4_H

#include <Fecha.h>


typedef struct
{
	char nombre[31];
	double importe_saldo; ///Importe de las compras en la lista. Saldo en el archivo de cuentas.
	t_fecha fecha_ult_compra;
}
t_cuenta;


typedef struct
{
	char nombre[31];
	int nro_reg; ///El primer registro es el 0.
}
t_indice;


#endif // TIPOS2DOPARCIALC4_H
