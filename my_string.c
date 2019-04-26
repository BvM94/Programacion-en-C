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

char* normalizar(char* orig, char* dest)
{
    t_palabra pal;
    t_sec_pal sorig,sdest;

    iniciar_sec_pal(&sorig,orig);
    iniciar_sec_pal(&sdest,dest);

    leer_palabra(&sorig,&pal);

    while(!fin_sec_pal(&sorig))
    {
        escribir_palabra(&sdest, &pal);
        formatear_palabra(&pal);
        escribir_caracter(&sdest,' ');
        leer_palabra(&sorig,&pal);
    }

    posicionamiento_sec_pal(&sdest,-1);
    escribir_caracter(&sdest, '\0');

    return dest;
}

void iniciar_sec_pal(t_sec_pal * sec, char* str)
{
    sec->act = sec->inicad = str;
    sec->finSec = 0;
}

void leer_palabra(t_sec_pal * sec, t_palabra* pal )
{
    while(*sec->act != '\0' && !es_letra(*sec->act))
        sec->act++;
    if(!(*sec->act))
    {
        sec->finSec=1;
        return;
    }
    pal->ini=sec->act;

    while(*sec->act != '\0' && es_letra(*sec->act))
        sec->act++;
    pal->fin = sec->act - 1 ;
}

int es_letra(const char caracter)
{
    return ((caracter >= 'a' && caracter<= 'z' ) || (caracter >= 'A' && caracter<= 'Z' ));
}

int fin_sec_pal(t_sec_pal * sec)
{
    return sec->finSec;
}

void escribir_caracter(t_sec_pal* sec, char caracter)
{
  *sec->act = caracter;
   sec->act++;
}

void escribir_palabra(t_sec_pal* sec, t_palabra * pal)
{
    char* inipal = pal->ini;
    char* finpal = pal->fin;

    pal->ini = sec->act;

    while(inipal <= finpal)
    {
            *sec->act = *inipal;
            inipal++;
            sec->act++;
    }
    pal->fin = sec->act -1;
}

void formatear_palabra(t_palabra* pal)
{
    char* inipal = pal->ini;

    a_mayuscula(inipal);
    inipal++;

    while(inipal <= pal->fin )
    {
        a_minuscula(inipal);
        inipal++;
    }
}


void posicionamiento_sec_pal(t_sec_pal* sec,int pos)
{
  (sec->act) += pos;
}

void a_mayuscula(char* caracter)
{
    if(*caracter >= 'a' && *caracter <= 'z')
        *caracter -= ('a'- 'A');
}

void a_minuscula(char* caracter)
{
    if(*caracter >= 'A' && *caracter <= 'Z')
        *caracter += ('a'- 'A');
}
