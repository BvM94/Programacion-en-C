#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    Hora inicio, fin(0,0,20); ///Horas, Minutos, Segundos
    cout<<"Ingrese el horario de inicio: ";
    cin>>inicio;
    cout<<endl<<"Ingrese el horario de fin: ";
    cin>>fin;
    if(inicio>=fin)
    {
        cout<<endl<<"Error! El horario de inicio debe ser menor al de fin.";
        return 0;
    }
    while(inicio<fin)
    {
        system("CLS");
        cout<<"Actual: "<<inicio++<<endl<<"Fin: "<<fin;
        Sleep(1000);
    }
    cout<<"FIN";
    Hora h1(22,54,21), h2(1,20,55), h3; ///La hora nunca debe ser mayor a las 23:59:59
    h3 = h1+h2;
    cout<<h3<< endl;
    h3+=2; //Segundos
    cout<<h3<< endl;
    h3 = 3+h3; //Segundos
    cout<<h3<< endl;
    h3 = Hora::getHoraMaxima(); //Devuelve una hora a las 23:59:59
    cout<<h3<< endl;
    return 0;
}
