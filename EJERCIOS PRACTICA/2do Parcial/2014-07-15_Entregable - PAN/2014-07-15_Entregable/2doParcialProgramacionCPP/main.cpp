#include <iostream>

#include"../include/Racional.h"
using namespace std;

int main()
{
    Racional r1, r2(1, 3), r3, r4;

    r1 = r2;

    //r3 = r1 + r2;

    r3= r1 + 2;

    r4 = 2 + r3;

	cout << "r1: "<< r1 << ", r2: " << r2 << ", r3: " << r3 << ", r4: " << r4 << endl;

    return 0;
}
