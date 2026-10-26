#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

// ============================================================
// CLASS DECLARATION
// ============================================================
class student // Corrected: Removed parentheses () from class declaration header
{
public:
    bool canGraduate();
    void print() const;
    student(int = 0, double = 0); // Corrected: Removed return type 'void' (constructors cannot have return types)

private: // Corrected: Replaced semicolon ';' with colon ':' after access specifier
    int ID;
    double gpa;
};

#endif // STUDENT_H


// ============================================================
// MEMBER FUNCTION DEFINITIONS
// ============================================================

// Constructor implementation
student::student(int idVal, double gpaVal) {
    ID = idVal;
    gpa = gpaVal;
}

// Function to check if student can graduate (e.g., GPA >= 2.0)
bool student::canGraduate() {
    return (gpa >= 2.0);
}

// Function to print student details
void student::print() const {
    cout << "Student ID: " << ID << ", GPA: " << gpa << endl;
}


// ============================================================
// MAIN DRIVER PROGRAM
// ============================================================
int main() {
    student s1(1001, 3.5);
    student s2(1002, 1.8);

    s1.print();
    if (s1.canGraduate()) {
        cout << "Status: Eligible to graduate" << endl;
    } else {
        cout << "Status: Not eligible to graduate" << endl;
    }

    cout << endl;

    s2.print();
    if (s2.canGraduate()) {
        cout << "Status: Eligible to graduate" << endl;
    } else {
        cout << "Status: Not eligible to graduate" << endl;
    }

    return 0;
}