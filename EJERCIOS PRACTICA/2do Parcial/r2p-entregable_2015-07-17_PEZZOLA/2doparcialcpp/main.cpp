#include <iostream>
#include <windows.h>
#include "Hora.h"

using namespace std;

int main()
{
    Hora inicio, fin(0,0,20); ///Horas, Minutos, Segundos
    cout<<"Ingrese el horario de inicio: ";  ///FORMATO: hh:mm:ss
    cin>>inicio;                                         ///desarrollar >>
    cout<<endl<<"Ingrese el horario de fin: ";
    cin>>fin;                                            ///desarrollar >>
    if(inicio>=fin)                                     ///desarrollar >=
    {
        cout<<endl<<"Error! El horario de inicio debe ser menor al de fin.";
        return 0;
    }
    while(inicio<fin)                               ///desarrollar <
    {
        system("CLS");
        cout<<"Actual: "<<inicio++<<endl<<"Fin: "<<fin; ///desarrollar ++
        Sleep(1000);
    }
    cout<<endl<<"FIN";
    Hora h1(22,54,21), h2(1,20,55), h3; ///La hora nunca debe ser mayor a las 23:59:59
    h3 = h1+h2;                             ///desarrollar OPERADOR +
    cout<<h3<< endl;
    h3+=2; //Segundos                       ///desarrollar OPERADOR +=
    cout<<h3<< endl;                        ///desarrollar OPERADOR <<
    h3 = 3+h3; //Segundos                   ///desarrollar int + hora
    cout<<h3<< endl;
    h3 = Hora::getHoraMaxima(); //Devuelve una hora a las 23:59:59
    cout<<h3<< endl;
    return 0;
}
