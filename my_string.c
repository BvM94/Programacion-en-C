#include "my_string.h"


int mi_atoi(char* str)
{
    int positivo=VERDADERO;
    int num=0;

    if(*str == '-')
    {
        positivo=FALSO;
        str++;
    }

    while(*str != '\0')
    {
       // printf("%c\n",*str);
        num*=10;
        num+=(*str)-'0';
        str++;
    }

    return positivo? num:-num;
}

void ingresar_num_txt(char* numStr)
{
    puts("Ingresar Numero:");
    fflush(stdin);
    scanf("%s",numStr);


    while(!es_numero(numStr))
        {
            puts("La cadena ingresada no es un numero, Ingresar Nuevamente:");
            fflush(stdin);
            scanf("%s",numStr);
        }
}

int es_numero(char*  Str)
{
    if(*Str == '-')
        Str++;

    while(*Str)
    {
        if(!(*Str >='0' && *Str <= '9'))
            return FALSO;
    }

    return VERDADERO;
}

//char* mi_itoa(int num, char* str)
//{
//
//    char* i= str;
//    int positivo = VERDADERO;
//    int dig;
//
//    if(num==0)
//    {
//        *i='0';
//        i++;
//        *i='\0';
//        return str;
//    }
//
//    if(num<0)
//    {
//        positivo = FALSO;
//        num =-num;
//    }
//
//    while(num>0)
//    {
//        dig=num%10;
//        num/=10;
//        *i=dig+'0';
//        i++;
//    }
//
//    if(!positivo)
//    {
//        *i='-';
//        i++;
//    }
//    *i='\n';
//
//    invertir_cadena(str);
//
//    return str;
//}

char* mi_itoa(int num, char* str, const int base)
{

    char* pchar= str;
    int positivo = VERDADERO;
    int dig;

    if(num==0)
    {
        *pchar='0';
        pchar++;
        *pchar='\0';
        return str;
    }

    if(num<0)
    {
        positivo = FALSO;
        num =-num;
    }

    while(num>0)
    {
        dig=num%base;
        num/=base;

        *pchar = (dig>9? dig-10 + 'A'  : dig+'0');
        pchar++;
    }

    if(!positivo)
    {
        *pchar='-';
        pchar++;
    }
    *pchar='\0';

    invertir_cadena(str);

    return str;
}

char* invertir_cadena(char* str)
{
    char* izq= str;
    char* der= str + strlen(str)-1;

    while(izq < der)
    {
        intercambiar_chars(izq,der);
        izq++;
        der--;
    }
    return str;
}

void intercambiar_chars(char* izq,char* der)
{
    char aux=*izq;

    *izq = *der;
    *der = aux;
}


