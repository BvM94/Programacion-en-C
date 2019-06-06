#ifndef UTILITARIAS2DOPALUMNOS_H
#define UTILITARIAS2DOPALUMNOS_H

#include <stdio.h>
#include <Lista.h>
#include <string.h>


void generarArchivo();
void cargarLista(t_lista* pLAlu, FILE* archAlumnos);
void procesar_lista(t_lista* pLAlu);
void procesar_lista_res(t_lista* pLAlu);
void mostrar_nota(void* pvd, void* datos);

int comparar_nota(const void*, const void*);
int comparar_dniYmateria(const void*, const void*);

void actualizar_nota(t_nota* nota1,t_nota* nota2);


#endif // UTILITARIAS2DOPALUMNOS_H
