#ifndef LINETYPE_H
#define LINETYPE_H

#include <iostream>
#include <cmath>

using namespace std;

// ============================================================
// 1. CLASS DECLARATION
// ============================================================
class lineType {
private:
    double a; // Coefficient of x
    double b; // Coefficient of y
    double c; // Constant term (ax + by = c)

public:
    // Constructor with default parameters
    lineType(double aVal = 0, double bVal = 0, double cVal = 0);

    // Mutator and Accessor Functions
    void setLine(double aVal, double bVal, double cVal);
    double getA() const;
    double getB() const;
    double getC() const;

    // Helper Functions
    bool isVertical() const;    // Returns true if line is vertical (b == 0)
    bool isHorizontal() const;  // Returns true if line is horizontal (a == 0)

    // Core Required Operations (a - d)
    double slope() const;                               // a) Returns slope (-a/b) if nonvertical
    bool isEqual(const lineType& other) const;         // b) Checks if two lines are equal (k >= 0)
    bool isParallel(const lineType& other) const;      // c) Checks if two lines are parallel
    bool isPerpendicular(const lineType& other) const; // d) Checks if two lines are perpendicular

    void printEquation() const; // Utility function to print equation
};

#endif // LINETYPE_H


// ============================================================
// 2. MEMBER FUNCTION DEFINITIONS
// ============================================================

// Constructor implementation
lineType::lineType(double aVal, double bVal, double cVal) {
    setLine(aVal, bVal, cVal);
}

// Mutator: Validates that both a and b cannot be zero simultaneously
void lineType::setLine(double aVal, double bVal, double cVal) {
    if (aVal == 0 && bVal == 0) {
        cerr << "Error: 'a' and 'b' cannot both be zero. Defaulting to x = 0." << endl;
        a = 1;
        b = 0;
        c = 0;
    } else {
        a = aVal;
        b = bVal;
        c = cVal;
    }
}

// Accessors
double lineType::getA() const { return a; }
double lineType::getB() const { return b; }
double lineType::getC() const { return c; }

// Line orientation helpers
bool lineType::isVertical() const {
    return (b == 0);
}

bool lineType::isHorizontal() const {
    return (a == 0);
}

// a) Slope calculation (-a/b)
double lineType::slope() const {
    if (isVertical()) {
        cerr << "Warning: Vertical line has an undefined slope! Returning 0." << endl;
        return 0;
    }
    return -a / b;
}

// b) Check if two lines are equal: a1 = k*a2, b1 = k*b2, c1 = k*c2 for nonnegative k
bool lineType::isEqual(const lineType& other) const {
    double k = 0;

    // Determine proportionality factor k from a non-zero member
    if (other.a != 0) k = a / other.a;
    else if (other.b != 0) k = b / other.b;
    else if (other.c != 0) k = c / other.c;

    // k must be non-negative
    if (k < 0) return false;

    // Check proportionality across all coefficients using floating-point tolerance
    return (abs(a - k * other.a) < 1e-6 &&
            abs(b - k * other.b) < 1e-6 &&
            abs(c - k * other.c) < 1e-6);
}

// c) Check if two lines are parallel (same slope or both vertical)
bool lineType::isParallel(const lineType& other) const {
    if (isVertical() && other.isVertical()) {
        return true; // Both vertical
    }
    if (isVertical() || other.isVertical()) {
        return false; // Only one is vertical
    }
    return (abs(slope() - other.slope()) < 1e-6); // Equal slopes
}

// d) Check if two lines are perpendicular (one horizontal & one vertical OR m1 * m2 = -1)
bool lineType::isPerpendicular(const lineType& other) const {
    if ((isVertical() && other.isHorizontal()) || (isHorizontal() && other.isVertical())) {
        return true;
    }
    if (isVertical() || other.isVertical()) {
        return false;
    }
    return (abs(slope() * other.slope() + 1.0) < 1e-6); // Slope product == -1
}

// Helper: Formats and displays equation ax + by = c
void lineType::printEquation() const {
    cout << a << "x + " << b << "y = " << c;
}


// ============================================================
// 3. MAIN DRIVER PROGRAM
// ============================================================
int main() {
    cout << boolalpha; // Output boolean as true/false
    cout << "=== Testing lineType Class ===" << endl << endl;

    // Instantiate test lines
    lineType line1(2, 3, 6);   //  2x + 3y = 6  (slope = -2/3 = -0.6667)
    lineType line2(4, 6, 12);  //  4x + 6y = 12 (Equal to line1 with k = 2)
    lineType line3(2, 3, 10);  //  2x + 3y = 10 (Parallel to line1, different c)
    lineType line4(-3, 2, 8);  // -3x + 2y = 8  (slope = 3/2 = 1.5; Perpendicular to line1)
    lineType line5(1, 0, 4);   //   x + 0y = 4  (Vertical line: x = 4)
    lineType line6(0, 5, 15);  //  0x + 5y = 15 (Horizontal line: y = 3)

    // a) Slope
    cout << "a) Slopes:" << endl;
    cout << "   line1 slope: " << line1.slope() << endl; // OUTPUT:    line1 slope: -0.666667
    cout << "   line4 slope: " << line4.slope() << endl; // OUTPUT:    line4 slope: 1.5
    cout << "   line6 slope: " << line6.slope() << endl << endl; // OUTPUT:    line6 slope: -0

    // b) Equality test
    cout << "b) Line Equality (isEqual):" << endl;
    cout << "   line1 equals line2: " << line1.isEqual(line2) << endl; // OUTPUT:    line1 equals line2: true
    cout << "   line1 equals line3: " << line1.isEqual(line3) << endl << endl; // OUTPUT:    line1 equals line3: false

    // c) Parallel test
    cout << "c) Parallel Lines (isParallel):" << endl;
    cout << "   line1 parallel to line3: " << line1.isParallel(line3) << endl; // OUTPUT:    line1 parallel to line3: true
    cout << "   line1 parallel to line4: " << line1.isParallel(line4) << endl << endl; // OUTPUT:    line1 parallel to line4: false

    // d) Perpendicular test
    cout << "d) Perpendicular Lines (isPerpendicular):" << endl;
    cout << "   line1 perpendicular to line4: " << line1.isPerpendicular(line4) << endl; // OUTPUT:    line1 perpendicular to line4: true
    cout << "   line5 (vert) perpendicular to line6 (horiz): " << line5.isPerpendicular(line6) << endl; // OUTPUT:    line5 (vert) perpendicular to line6 (horiz): true

    return 0;
}