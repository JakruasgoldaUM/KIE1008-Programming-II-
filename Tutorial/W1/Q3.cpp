#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

using namespace std;

// ============================================================
// 1. CLASS DECLARATION
// ============================================================
class myClass {
public:
    void printX() const;       // Function to output x
    void printCount();         // Function to output count
    void incrementCount();     // Function to increment count
    myClass(int a = 0);        // Constructor with default parameter

private:
    int x;
    static int count;          // Static count shared by all myClass objects
};

#endif // MYCLASS_H


// ============================================================
// 2. MEMBER FUNCTION DEFINITIONS & STATIC INITIALIZATION
// ============================================================

// Definition and initialization of static data member outside the class
int myClass::count = 0;

// Constructor: sets x = a
myClass::myClass(int a) {
    x = a;
}

// Function to output x
void myClass::printX() const {
    cout << "x = " << x;
}

// Function to output count
void myClass::printCount() {
    cout << "count = " << count;
}

// Function to increment count
void myClass::incrementCount() {
    count++;
}


// ============================================================
// 3. MAIN DRIVER PROGRAM (Parts b & c)
// ============================================================
int main() {
    // Part (b): Declaration statements
    myClass myObject1(5); // Creates myObject1 with x = 5
    myClass myObject2(7); // Creates myObject2 with x = 7

    // Part (c): Execution trace with expected output beside each line
    myObject1.printX(); cout << endl;      // OUTPUT: x = 5
    myObject1.incrementCount();            // (No output; static variable count increases from 0 to 1)
    myObject1.printCount(); cout << endl;  // OUTPUT: count = 1
    myObject2.printCount(); cout << endl;  // OUTPUT: count = 1  (Shares the same static variable count)
    myObject2.printX(); cout << endl;      // OUTPUT: x = 7

    return 0;
}