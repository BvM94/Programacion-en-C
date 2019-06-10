#ifndef CADENA_H
#define CADENA_H
#include <Defs.h>

#

void normalizar(char* cad_ori, char* cad_dest);

void normalizar_res(char* cad_ori, char* cad_dest);

int son_anagramas(char* palabra1, char* palabra2);

int son_anagramas_res(char* palabra1, char* palabra2);

void invertir_cadena(char* vec, int ce);

int mistrslen(const char* pal);
int mistrcmpi(const char* pal1,const char* pal2);

#endif // CADENA_H
