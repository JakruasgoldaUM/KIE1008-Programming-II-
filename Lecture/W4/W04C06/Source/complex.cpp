#include <iostream>
#include "complex.h"

using namespace std;

void Complex::display() const {
    cout << real << " + j" << imag << endl;
}

Complex& Complex::operator= (const Complex& other) {
    real = other.real;
    imag = other.imag;
    return *this;
}

//Complex Complex::operator+ (const Complex& other) {
//    double result_real = real + other.real;
//    double result_imag = imag + other.imag;
//    return Complex(result_real, result_imag);
//}

Complex Complex::operator+ (const Complex& other) const {

    Complex c;
    c.real = real + other.real;
    c.imag = imag + other.imag;
    return c;
}

Complex& Complex::operator+= (const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator++ () {
    ++real;
    ++imag;
    return *this;
}

Complex& Complex::operator+= (double n) {
    real += n;
    imag += n;
    return *this;
}

bool Complex::operator== (const Complex& other) const {
    return real == other.real && imag == other.imag;
}

//bool Complex::operator== (const Complex& other)
//{
//    return (real == other.real && imag == other.imag);
//}


ostream& operator<< (ostream& os, const Complex& other) {
    os << other.real << " + j" << other.imag << endl;
    return os;
}

istream& operator>> (istream& is, Complex& other) {
    char ch;

    is >> other.real;
    is >> ch;
    is >> ch;
    is >> other.imag;

    return is;
}
