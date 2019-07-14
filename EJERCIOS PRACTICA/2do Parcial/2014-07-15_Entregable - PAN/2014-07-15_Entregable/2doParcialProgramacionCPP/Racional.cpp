#include "../include/Racional.h"

Racional::Racional ( int a, int b)
{
    if(b<0)
    {
        b*=-1;
        a*=-1;
    }

    if(b==0)
        throw runtime_error("Denominador no puede ser 0");
    this->num = a;
    this->den=b;

}
Racional::Racional ()
{
    this->den=1;
    this->num=0;
}

Racional Racional::operator +(const Racional& otro)const
{
    Racional res;

    res.den = this->den * otro.den;
    res.num = this->num * otro.den + otro.num * this->den;
    res.simplificar();
    return res;
}

Racional Racional::operator -(const Racional& otro)const
{
    Racional res;

    res.den = this->den * otro.den;
    res.num = this->num * otro.den - otro.num * this->den;
    res.simplificar();
    return res;
}

Racional operator -(const int valor, const Racional& racional)
{
    Racional res;

    res.den = racional.den;
    res.num = valor * racional.den - racional.num;
    res.simplificar();
    return res;
}

Racional operator +(const int valor, const Racional& racional)
{
    Racional res;

    res.den = racional.den;
    res.num = valor * racional.den + racional.num;
    res.simplificar();
    return res;
}

ostream& operator<<(ostream& sal,const Racional& racional)
{
    if(racional.den ==1 )
        sal<<racional.num;
    else
        sal<<racional.num<<'/'<<racional.den;

    return sal;
}

Racional Racional::operator /(const Racional& otro)const
{
    Racional res;

    res.den = this->den * otro.num;
    res.num = this->num * otro.den;
    res.simplificar();
    return res;
}


Racional Racional::operator *(const Racional& otro)const
{
        Racional res;

    res.den = this->den * otro.den;
    res.num = this->num * otro.num;
    res.simplificar();
    return res;
}

void Racional::simplificar()
{
    int mcd  = maximo_comun_divisor(this->num, this->den);
    if(mcd != 1)
    {
        this->num /= mcd;
        this->den /= mcd;
    }
}

int maximo_comun_divisor(int a, int b)
{
    a = abs(a);
    int resto;
    while (b!= 0)
    {
        resto = a % b;
        a = b;
        b=resto;
    }

    return a;
}

