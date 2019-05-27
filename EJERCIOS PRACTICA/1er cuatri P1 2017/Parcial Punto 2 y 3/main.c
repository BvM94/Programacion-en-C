#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char cadena[]="Anita lava la tina.";

    printf("%s - %s es un palindromo\n",cadena,es_palindromo(cadena) == 1? "SI": "NO");
}
