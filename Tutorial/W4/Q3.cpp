#include <iostream>
#include <stdexcept>
using namespace std;

class Rational
{
   private:
    int a; // numerator
    int b; // denominator
   public:
    Rational(int numerator = 0, int denominator = 1); // Default & parameterized constructor
    // Overloaded stream insertion (<<) and extraction (>>) declared as friend functions
    friend ostream& operator<<(ostream& os, const Rational& r);
    friend istream& operator>>(istream& is, Rational& r);
    // Overloaded arithmetic operators (+) and (*)
    Rational operator+(const Rational& operand2) const;
    Rational operator*(const Rational& operand2) const;
    Rational operator-(const Rational& operand2) const
    {
        return Rational(a * operand2.b - b * operand2.a, b * operand2.b);
    }
    Rational operator/(const Rational& operand2) const
    {
        return Rational(a * operand2.b, b * operand2.a);
    }
    Rational& operator+=(int value)
    {
        a += value * b;
        return *this;
    }
    // Overloaded equality comparison operator (==)
    bool operator==(const Rational& operand2) const;
};

Rational::Rational(int numerator, int denominator)
    : a(numerator), b(denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("A rational number cannot have a zero denominator.");
    }
}

Rational Rational::operator+(const Rational& operand2) const
{
    return Rational(a * operand2.b + b * operand2.a, b * operand2.b);
}

Rational Rational::operator*(const Rational& operand2) const
{
    return Rational(a * operand2.a, b * operand2.b);
}

bool Rational::operator==(const Rational& operand2) const
{
    return a * operand2.b == b * operand2.a;
}

ostream& operator<<(ostream& os, const Rational& r)
{
    os << r.a << '/' << r.b;
    return os;
}

istream& operator>>(istream& is, Rational& r)
{
    int numerator;
    int denominator;
    char separator;

    if (is >> numerator >> separator >> denominator)
    {
        if (separator != '/' || denominator == 0)
        {
            is.setstate(ios::failbit);
        }
        else
        {
            r.a = numerator;
            r.b = denominator;
        }
    }

    return is;
}

int main()
{
    cout << boolalpha;

    Rational defaultValue;
    Rational first(2, 3);
    Rational second(3, 4);

    cout << "Default rational: " << defaultValue << '\n';
    cout << first << " + " << second << " = " << first + second << '\n';
    cout << first << " - " << second << " = " << first - second << '\n';
    cout << first << " * " << second << " = " << first * second << '\n';
    cout << first << " / " << second << " = " << first / second << '\n';

    Rational updated(2, 3);
    updated += 3;
    cout << "2/3 += 3 gives " << updated << '\n';

    cout << "2/3 == 4/6: " << (first == Rational(4, 6)) << '\n';

    Rational input;
    cout << "Enter a rational number (a/b): ";
    if (cin >> input)
    {
        cout << "You entered: " << input << '\n';
    }
    else
    {
        cout << "Invalid rational number. Enter a/b with a nonzero denominator.\n";
        return 1;
    }

    return 0;
}