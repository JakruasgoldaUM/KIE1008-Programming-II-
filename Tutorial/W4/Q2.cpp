#include <iostream>
#include <iomanip>
using namespace std;

// 1. CLASS DECLARATION
class Complex {
    

public:
    Complex(double realPart = 0.0, double imagPart = 0.0); // Default & parameterized constructor
    // Part (a): Overloaded stream insertion (<<) and extraction (>>) declared as friend functions
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
    // Part (b): Overloaded arithmetic operators (+) and (*)
    Complex operator+(const Complex& operand2) const;
    Complex operator*(const Complex& operand2) const;

    // Part (c): Overloaded equality comparison operator (==)
    bool operator==(const Complex& operand2) const;

private:
    double real;      // Real part
    double imaginary; // Imaginary part
};


// 2. MEMBER & FRIEND FUNCTION DEFINITIONS
// Constructor implementation using initializer list
Complex::Complex(double x, double y) : real(x), imaginary(y) {}

// Part (a): Overloaded stream insertion operator <<
// Outputs in the form: (realPart, imaginaryPart)
ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.real << ", " << c.imaginary << ")";
    return os;
}

// Part (a): Overloaded stream extraction operator >>
// Reads complex numbers formatted as: (realPart, imaginaryPart)
istream& operator>>(istream& is, Complex& c) {
    char ch;
    is >> ch;          // Read and discard '('
    is >> c.real;      // Read real part
    is >> ch;          // Read and discard ','
    is >> c.imaginary; // Read imaginary part
    is >> ch;          // Read and discard ')'
    return is;
}

// Part (b): Overloaded addition operator +
// Formula: (a + bi) + (c + di) = (a + c) + (b + d)i
Complex Complex::operator+(const Complex& operand2) const {
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

// Part (b): Overloaded multiplication operator *
// Formula: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex& operand2) const {
    double resReal = (real * operand2.real) - (imaginary * operand2.imaginary);
    double resImag = (real * operand2.imaginary) + (imaginary * operand2.real);
    return Complex(resReal, resImag);
}

// Part (c): Overloaded equality operator ==
bool Complex::operator==(const Complex& operand2) const {
    return (real == operand2.real && imaginary == operand2.imaginary);
}



//3. MAIN FUNCTION
int main() {
    // Format output with two decimal places
    cout << fixed << setprecision(2) << boolalpha;

    cout << "=== Testing Complex Class ===" << endl << endl;

    // Instantiate complex numbers
    Complex c1(3.50, 2.50);
    Complex c2(1.20, 4.10);
    Complex c3;

    // Part (a): Testing << operator output
    cout << "c1 = " << c1 << endl;                  // OUTPUT: c1 = (3.50, 2.50)
    cout << "c2 = " << c2 << endl;                  // OUTPUT: c2 = (1.20, 4.10)
    cout << "c3 (default) = " << c3 << endl << endl; // OUTPUT: c3 (default) = (0.00, 0.00)

    // Part (b): Testing + operator
    Complex cAdd = c1 + c2;
    cout << "c1 + c2 = " << cAdd << endl;           // OUTPUT: c1 + c2 = (4.70, 6.60)

    // Part (b): Testing * operator
    Complex cMul = c1 * c2;
    cout << "c1 * c2 = " << cMul << endl << endl;   // OUTPUT: c1 * c2 = (-6.05, 17.35)

    // Part (c): Testing == operator
    Complex c4(3.50, 2.50);
    cout << "c1 == c4: " << (c1 == c4) << endl;     // OUTPUT: c1 == c4: true
    cout << "c1 == c2: " << (c1 == c2) << endl;     // OUTPUT: c1 == c2: false

    return 0;
}