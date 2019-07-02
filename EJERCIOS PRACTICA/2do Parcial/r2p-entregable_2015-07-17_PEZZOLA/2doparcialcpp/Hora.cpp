#include <iostream>
#include "Hora.h"

using namespace std;

    Hora::Hora(int h , int m , int s)
    {
        this->seg = h*3600 + m*60 + s;
    }

    Hora::Hora( int s)
    {
        this->seg = s;
    }

    Hora::Hora()
    {
        this->seg = 0;
    }

    void Hora::set_HMS(int h, int m , int s)
    {
        this->seg = h*3600 + m*60 + s;
    }

    bool Hora::operator >=(const Hora &otra)const
    {
        return this->seg >= otra.seg;
    }

    bool Hora::operator <(const Hora &otra)const
    {
        return this->seg < otra.seg;
    }

    Hora Hora::operator +(const Hora &otra)const
    {
        return Hora((this->seg + otra.seg)%86400);
    }

    Hora& Hora::operator +=(const int valor)
    {
        this->seg += valor;
        this->seg%=86400;
        if(this->seg <0)
            this->seg +=86400;
        return *this;
    }

    Hora Hora::operator ++(int)
    {
        Hora aux(this->seg);
        this->seg++;
        return aux;
    }


    Hora operator +(const int valor , const Hora& hora)
    {
        return Hora((valor + hora.seg)%86400);
    }

    istream& operator >> (istream& ent , Hora& hora)
    {
        int h,m,s;
        char c;

        ent>>h>>c>>m>>c>>s;
        hora.set_HMS(h,m,s);
        return ent;
    }

    ostream& operator << (ostream& sal ,const Hora& hora)
    {
        sal<<hora.seg/3600<<":"<<hora.seg%3600/60<<":"<<hora.seg%60;
        return sal;
    }

    Hora Hora::getHoraMaxima()
    {
       return Hora(23,59,59);
    }
