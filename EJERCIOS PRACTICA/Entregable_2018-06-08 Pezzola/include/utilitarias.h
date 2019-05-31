#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<banco.h>
#define TAM_LINEA 50

void crear_archivo_cuentas(const char * path);
void crear_archivo_movimientos(const char * path);

void mostrar_archivo_cuentas(const char * path);
void mostrar_archivo_movimientos(const char * path);
void mostrar_archivo_errores(const char * path);

int comparar_movimientos(const t_info *, const t_info*);

void acumular_movimiento(t_info *, const t_info*);



void texto_a_movimiento_res(const char * cadena,t_movimiento_banco * pmov);
void texto_a_movimiento(const char * cadena,t_movimiento_banco * pmov);

#endif // UTILITARIAS_H_INCLUDED
