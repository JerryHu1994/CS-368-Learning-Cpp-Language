#include <iostream>
#include "ComplexNumber.h"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Enter a complex number C1:"<< endl;
    ComplexNumber C1;
    cin >> C1;
    cout << "Enter a complex number C2:"<< endl;
    ComplexNumber C2;
    cin >> C2;
    cout << "For C1 = "<< C1 << " and C2 = " << C2<< " :"<<endl;
    cout << "C1 + C2 = " << (C1+C2) << endl;
    cout << "C1 - C2 = " << (C1-C2) << endl;
    cout << "C1 * C2 = " << (C1*C2) << endl;
    cout << "C1 == C2 is " << (C1 == C2) <<endl;
    cout << "C1 != C2 is " << (C1 != C2) <<endl;
    cout << "After C1 += C2, C1 = " << (C1+=C2) << endl;
    C1 -= C2;
    cout << "After C1 -= C2, C1 = " << (C1-=C2) <<endl;
    C1 += C2;
    cout << "After C1 *= C2, C1 = " << (C1*=C2) <<endl;
    return 1;
}
