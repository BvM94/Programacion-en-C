#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

#include <iostream>
using namespace std;

class Hora
{
private:
    int seg;
public:
    Hora(int h , int m , int s);
    Hora(int seg);
    Hora();

    void set_HMS(int h, int m , int s);

    bool operator >=(const Hora &otra)const;
    bool operator <(const Hora &otra)const;
    Hora operator +(const Hora &otra)const;
    Hora& operator +=(const int valor);
    Hora operator ++(int);

    static Hora getHoraMaxima();

    friend Hora operator +(const int valor , const Hora& hora);
    friend istream& operator >> (istream& ent , Hora& hora);
    friend ostream& operator << (ostream& sal ,const Hora& hora);



};


#endif // HORA_H_INCLUDED

