#ifndef ROMANTYPE_H
#define ROMANTYPE_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ============================================================
// 1. CLASS DECLARATION
// ============================================================
class romanType {
private:
    string romanNum;   // Stores the Roman numeral representation
    int decimalNum;    // Stores the converted positive integer

    // Private helper functions
    int romanCharValue(char c) const; // Converts single Roman character to integer value
    void convertToDecimal();           // Internal logic to parse and convert romanNum

public:
    // Constructor with default parameter
    romanType(string r = "");

    // Mutator and Accessor Functions
    void setRoman(string r);          // Sets new Roman numeral and re-converts
    void printRoman() const;          // Prints Roman numeral
    void printDecimal() const;        // Prints converted decimal integer
    
    string getRoman() const;          // Returns Roman numeral string
    int getDecimal() const;           // Returns positive integer value
};

#endif // ROMANTYPE_H


// ============================================================
// 2. MEMBER FUNCTION DEFINITIONS
// ============================================================

// Private Helper: Returns corresponding decimal value for a single Roman numeral character
int romanType::romanCharValue(char c) const {
    switch (toupper(c)) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default:  return 0;
    }
}

// Private Helper: Converts romanNum string to positive integer decimalNum
// Uses standard Roman numeral rules (subtractive notation if current < next)
void romanType::convertToDecimal() {
    decimalNum = 0;
    int len = romanNum.length();

    for (int i = 0; i < len; i++) {
        int currentVal = romanCharValue(romanNum[i]);
        int nextVal = (i + 1 < len) ? romanCharValue(romanNum[i + 1]) : 0;

        // Subtractive notation (e.g., IV = 4, IX = 9, CD = 400)
        if (currentVal < nextVal) {
            decimalNum += (nextVal - currentVal);
            i++; // Skip the next character since it was processed in pair
        } else {
            decimalNum += currentVal;
        }
    }
}

// Constructor
romanType::romanType(string r) {
    setRoman(r);
}

// Mutator: Update Roman numeral string and recalculate decimal value
void romanType::setRoman(string r) {
    romanNum = r;
    convertToDecimal();
}

// Output Roman numeral
void romanType::printRoman() const {
    cout << "Roman Numeral: " << romanNum;
}

// Output decimal integer
void romanType::printDecimal() const {
    cout << "Positive Integer: " << decimalNum;
}

// Getter for Roman numeral
string romanType::getRoman() const {
    return romanNum;
}

// Getter for Decimal value
int romanType::getDecimal() const {
    return decimalNum;
}


// ============================================================
// 3. MAIN DRIVER PROGRAM (Part d: Test cases)
// ============================================================
int main() {
    cout << "=== Testing romanType Class ===" << endl << endl;

    // Test Case 1: MCXIV  (1000 + 100 + (10 - 1) + 5 = 1114)
    romanType r1("MCXIV");
    r1.printRoman();  cout << " => "; r1.printDecimal();  cout << endl; // OUTPUT: Roman Numeral: MCXIV => Positive Integer: 1114

    // Test Case 2: CCCLIX (100*3 + 50 + (10 - 1) = 359)
    romanType r2("CCCLIX");
    r2.printRoman();  cout << " => "; r2.printDecimal();  cout << endl; // OUTPUT: Roman Numeral: CCCLIX => Positive Integer: 359

    // Test Case 3: MDCLXVI (1000 + 500 + 100 + 50 + 10 + 5 + 1 = 1666)
    romanType r3("MDCLXVI");
    r3.printRoman();  cout << " => "; r3.printDecimal();  cout << endl; // OUTPUT: Roman Numeral: MDCLXVI => Positive Integer: 1666

    cout << endl;

    // Testing mutator function setRoman()
    cout << "--- Testing setRoman() ---" << endl;
    r1.setRoman("MCMXCIV"); // 1994
    r1.printRoman();  cout << " => "; r1.printDecimal();  cout << endl; // OUTPUT: Roman Numeral: MCMXCIV => Positive Integer: 1994

    return 0;
}