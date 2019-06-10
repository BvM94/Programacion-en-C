#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include<stdio.h>
#include<tipos.h>
#include<stdlib.h>
#define ES_NUMERO(A) (A>= '0' && A <= '9'? 1: 0)

void actualizar_stock(FILE * arch_libros, FILE * arch_stock, FILE * arch_err);
void actualizar_stock_res(FILE * arch_libros, FILE * arch_stock, FILE * arch_err);

int isbn_valido_res(const char * isbn);
int isbn_valido(const char * isbn);

int cmp_stock_libro_res(const t_libro * l1, const t_libro * l2);
int cmp_stock_libro(const t_libro * l1, const t_libro * l2);

char *mi_strstr(const char *s1, const char *s2);




#endif // BANCO_H_INCLUDED
