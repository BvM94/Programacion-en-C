#ifndef MY_STRING_H_INCLUDED
#define MY_STRING_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FALSO 0
#define VERDADERO 1

typedef struct
{
    char* ini;
    char* fin;
}t_palabra;

typedef struct
{
    char* act;
    char* inicad;
    int finSec;

}t_sec_pal;

void ingresar_num_txt(char* numStr);
int es_numero(char*  Str);
int mi_atoi(char* str);
//char* mi_itoa(int num, char* str);
char* mi_itoa(int num, char* str, const int base);
char* invertir_cadena(char* str);
void intercambiar_chars(char* izq,char* der);

//char* normalizar_AyN(char* strAyN);

char* normalizar(char* orig, char* dest);
void iniciar_sec_pal(t_sec_pal * sec, char* str);
void leer_palabra(t_sec_pal * sec, t_palabra* pal );
int fin_sec_pal(t_sec_pal * sec);
void escribir_caracter(t_sec_pal* sec, char caracter);
void escribir_palabra(t_sec_pal* sec, t_palabra * pal);
void formatear_palabra(t_palabra* pal);
void posicionamiento_sec_pal(t_sec_pal* sec,int pos);
int es_letra(const char caracter);
void a_mayuscula(char* caracter);
void a_minuscula(char* caracter);

size_t mi_strlen(const char *s);
char *mi_strcat(char*s1, const char *s2);


#endif // MY_STRING_H_INCLUDED
