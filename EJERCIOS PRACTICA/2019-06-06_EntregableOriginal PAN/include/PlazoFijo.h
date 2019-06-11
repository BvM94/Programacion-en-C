#ifndef PLAZOFIJO_H
#define PLAZOFIJO_H


#include <Fecha.h>


typedef struct
{
	int nroPF;
	int cuenta;
	float monto;
	float interesAnual;
	t_fecha fechaConstitucion;
	int dias;
}
t_plazo_fijo;


typedef struct
{
	int cuenta;
	char cliente[201];
	float saldo;
}
t_cuenta;


#endif // PLAZOFIJO_H
