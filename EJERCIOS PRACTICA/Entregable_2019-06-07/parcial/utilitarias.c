#include <stdio.h>
#include <string.h>
#include <utilitarias.h>
#include <biblioteca.h>

void texto_a_stock(const char * cad,t_libro_stock * pstock)
{
    sscanf(cad,"%[^|]|%d",pstock->isbn,&pstock->stock);
}

