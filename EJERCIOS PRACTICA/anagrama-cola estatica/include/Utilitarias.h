#ifndef UTILITARIAS_H
#define UTILITARIAS_H

#include <ArchivoCola.h>


int cmp_int_res(const void* pv1, const void* pv2);
void mostrar_clave_int(const void* pv);
void mostrar_info_int(void* pvinfo, void*);
void generar_archivo_productos();
void mostrar_archivo_prod(FILE* arch_prod);
void mostrar_mat_prima_art(t_mat_prima_art* pmat_prima_art);


#endif // UTILITARIAS_H
