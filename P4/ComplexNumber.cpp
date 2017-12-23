#include <iostream>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber :: ComplexNumber(){
    
}

ComplexNumber :: ComplexNumber(double real_part, double imaginary_part){
    real = real_part;
    imag = imaginary_part;
    
}

ComplexNumber :: ComplexNumber(const ComplexNumber & rhs){
    real = rhs.real;
    imag = rhs.imag;
}

void ComplexNumber :: print(ostream & out = cout) const{
    cout << real << " " << imag <<"i"<<endl;
}

 bool ComplexNumber ::equals(const ComplexNumber & rhs) const{
    if(real == rhs.real && imag == rhs.imag){
        return true;
    }else{
        return false;
    }
}

const ComplexNumber & ComplexNumber ::operator=(const ComplexNumber & rhs){
    real = rhs.real;
    imag = rhs.imag;
    
}

const ComplexNumber & ComplexNumber ::operator+=(const ComplexNumber & rhs){
    real = real + rhs.real;
    imag = imag + rhs.imag;
    return *this;
}

const ComplexNumber & ComplexNumber ::operator-=(const ComplexNumber & rhs){
    real = real - rhs.real;
    imag = imag - rhs.imag;
    return *this;
}

const ComplexNumber & ComplexNumber ::operator*=(const ComplexNumber & rhs){
    real = real*rhs.real - imag*rhs.imag;
    imag = real*rhs.imag - imag*rhs.real;
    return *this;
}

friend ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
    int realpart = lhs.real + rhs.real;
    int imagpart = lhs.imag + rhs.imag;
    ComplexNumber result = ComplexNumber(realpart,imagpart);
    return result;
}
friend ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
    int realpart = lhs.real - rhs.real;
    int imagpart = lhs.imag - rhs.imag;
    ComplexNumber result = ComplexNumber(realpart,imagpart);
    return result;
}
friend ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
    int realpart = (lhs.real*rhs.real - lhs.imag*rhs.imag);
    int imagpart = (lhs.real*rhs.imag + lhs.imag*rhs.real);
    ComplexNumber result = ComplexNumber(realpart,imagpart);
    return result;
}

friend bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
    if (lhs.real == rhs.real && lhs.imag == rhs.imag){
        return true;
    }else{
        return false;
    }
}

friend bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
    if (lhs.real != rhs.real || lhs.imag != rhs.imag){
        return true;
    }else{
        return false;
    }
    
}

ostream & operator<<(ostream & out, const ComplexNumber & n){
    n.print(out);
    return out;
    
}
istream & operator>>(istream & in, ComplexNumber & n){
    double realpart;
    double imagepart;
    char s;
    int sign;
    cin >> realpart;
    cin.get(s);
    if(s == "+"){
        sign = 1
    }else{
        sign = -1
    }
    cin >> imagepart;
    imagepart = imagepart*sign;
    n = ComplexNumber(realpart,imagepart);
    
}
