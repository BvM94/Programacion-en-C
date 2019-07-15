#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED
#include <iostream>

using namespace std;

class Racional
{
    private:
            int numerador;
            int denominador;
    public:
            Racional Racional(int n=0,int d=1);
            float Real(int n,int d);
            Racional &operator+(int&n,int&d);
            Racional &operator*(int&n,int&d);
            friend ostream &operator<<(ostream &out,Racional &racio);
            friend iostream &operator>>(istream &in,Racional &racio);
};
#endif // RACIONAL_H_INCLUDED
