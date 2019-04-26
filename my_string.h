#ifndef MY_STRING_H_INCLUDED
#define MY_STRING_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FALSO 0
#define VERDADERO 1

void ingresar_num_txt(char* numStr);
int es_numero(char*  Str);
int mi_atoi(char* str);
//char* mi_itoa(int num, char* str);
char* mi_itoa(int num, char* str, const int base);
char* invertir_cadena(char* str);
void intercambiar_chars(char* izq,char* der);

//char* normalizar_AyN(char* strAyN);

char* normalizar(const char* orig, char* dest);
void iniciar_sec_pal(t_sec_pal * sec, const char* str);
void leer_palabra(t_sec_pal * sec, char* pal );
int fin_sec_pal(t_pal_sec * sec);
void escribir_caracter(t_sec_pal);


#endif // MY_STRING_H_INCLUDED
