#ifndef RACIONAL_H
#define RACIONAL_H
#include <exception>
#include <stdexcept>
#include <iostream>

using namespace std;

class Racional
{
    private:
    int num;
    int den;

    public:

//        Racional::Racional () {this.num=0, this.den=0;};
       Racional ( int a, int b=1);
       Racional ();

       Racional operator +(const Racional& otro)const;
       friend Racional operator +(const int valor, const Racional& racional);
       friend ostream& operator<<(ostream& sal,const Racional& racional);


};

#endif // RACIONAL_H
