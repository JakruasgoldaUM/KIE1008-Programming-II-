#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>

using namespace std;

class Complex {
public:
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);

    Complex() : real(0.0), imag(0.0) {};
    Complex(double re, double im) : real(re), imag(im) {};
    Complex(const Complex&) = default;

    void display() const;

    Complex& operator=(const Complex &); // c1 = c2
    Complex operator+(const Complex &) const; // c1 + c2
    Complex& operator+= (const Complex &); // c1 += c2

    Complex& operator++();  // ++c
    Complex& operator+=(double); // c += double
    bool operator== (const Complex &) const;  // c1 == c2

private:
    double real;
    double imag;
};

#endif // COMPLEX_H_INCLUDED
