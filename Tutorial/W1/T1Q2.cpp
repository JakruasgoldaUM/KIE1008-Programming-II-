#ifndef CLASSES_Y_X_H
#define CLASSES_Y_X_H

#include <iostream>

using namespace std;

// ============================================================
// CLASS DECLARATIONS
// ============================================================

class yClass {
public:
    void one();
    yClass(); // Default constructor
private:
    int a;
    int b;
};

class xClass {
public:
    void two();
    xClass(); // Default constructor
private:
    int z;
};

#endif // CLASSES_Y_X_H


// ============================================================
// MEMBER FUNCTION DEFINITIONS
// ============================================================

// Constructors initializing private data members
yClass::yClass() {
    a = 10;
    b = 20;
}

xClass::xClass() {
    z = 30;
}


// ------------------------------------------------------------
// STATEMENT (a):
// void yClass::one() { cout << a + b << endl; }
// STATUS: VALID
// EXPLANATION: 'one()' is a member function of 'yClass'. Member 
// functions have direct access to all private data members ('a' and 'b') 
// belonging to their own class.
// ------------------------------------------------------------
void yClass::one() {
    cout << "Sum (a + b) = " << a + b << endl;
}


// ------------------------------------------------------------
// STATEMENT (c):
// void xClass::two() { a = 10; b = 15; z = 30; cout << a + b + z << endl; }
// STATUS: INVALID (Compilation Error)
// EXPLANATION: 'two()' is a member function of 'xClass'. It has direct 
// access to 'z' (its own private member), but it CANNOT access 'a' and 'b' 
// because 'a' and 'b' belong to 'yClass'.
// ------------------------------------------------------------
void xClass::two() {
    // a = 10; // ERROR: 'a' is not a member of 'xClass'
    // b = 15; // ERROR: 'b' is not a member of 'xClass'
    z = 30;    // VALID: 'z' is a private data member of 'xClass'
    cout << "Value of z = " << z << endl;
}


// ============================================================
// MAIN DRIVER PROGRAM
// ============================================================
int main() {
    yClass y;
    xClass x;

    // Execute valid statement (a)
    cout << "Executing y.one(): ";
    y.one(); // Outputs: Sum (a + b) = 30

    // Execute statement (c)
    cout << "Executing x.two(): ";
    x.two(); // Outputs: Value of z = 30

    // ------------------------------------------------------------
    // STATEMENT (b):
    // cout << y.a << " " << y.b << " " << x.z << endl;
    // STATUS: INVALID (Compilation Error)
    // EXPLANATION: 'a' and 'b' are private members of 'yClass', and 'z' 
    // is a private member of 'xClass'. Private members cannot be accessed 
    // directly from outside the class scope (such as inside main()).
    // ------------------------------------------------------------
    /* 
    // UNCOMMENTING THE FOLLOWING LINE WILL CAUSE A COMPILER ERROR:
    cout << y.a << " " << y.b << " " << x.z << endl; 
    */

    return 0;
}