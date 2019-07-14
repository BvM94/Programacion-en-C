#ifndef UTILITARIAS2DOPARCIALC4_H
#define UTILITARIAS2DOPARCIALC4_H

#include <stdio.h>
#include <Arbol.h>

void generar_archivo_compras_usuarios();
void generar_archivo_cuentas_usuarios();
void generar_arbol_indice(t_arbol* arb_indice, FILE* arch_cuentas);
void generar_lista_de_txt(FILE* arch_compras, t_lista* lista_compras);
void generar_lista_de_txt_res(FILE* arch_compras, t_lista* lista_compras);
void actualizar_cuentas_usuarios(t_lista* lista_compras, FILE* arch_cuentas, t_arbol* arb_indice);
void actualizar_cuentas_usuarios_res(t_lista* lista_compras, FILE* arch_cuentas, t_arbol* arb_indice);
int cmp_cuentas_res(const void* pv1, const void* pv2);
int cmp_ind_res(const void* pv1, const void* pv2);
void act_cuenta_res(void* pvactualizado, const void* pvactualizador);
int cmp_fechas(const t_fecha* f1, const t_fecha* f2);
void mostrar_archivo_compras(FILE* arch_compras);
void mostrar_cuenta(void* info, void* datos_accion);
void mostrar_archivo_cuentas(FILE* arch_cuentas);


#endif // UTILITARIAS2DOPARCIALC4_H
