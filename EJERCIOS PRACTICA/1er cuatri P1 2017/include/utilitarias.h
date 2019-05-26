#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<tipos.h>
#define TAM_LINEA 50
#include <string.h>


void crear_archivo_alumnos(const char * path);

void mostrar_archivo_alumnos(const char * path);
void mostrar_archivo_notas(const char * path);
void mostrar_archivo_acta(const char * path);
void mostrar_archivo_errores(const char * path);


int comparar_alumnos_nombreYdni(const t_info* alumno1,const t_info* alumno2);
int comparar_alumnos_dni(const t_info* alumno1,const t_info* alumno2);

int actualizar_acta(void* ac1, const void * ac2);

void cargar_acta(t_acta* acta,const t_nota* nota);



void texto_a_nota_res(const char * cadena,t_nota * pnota);
void texto_a_nota(const char * cadena,t_nota * pnota);
#endif // UTILITARIAS_H_INCLUDED
