/**Example: Using this pointer**/
#include <iostream>
#include <iomanip>
using namespace std;

class rectangle
{
public:
    rectangle();
    double getLength() const;
    double getWidth() const;
    double area() const;
    void print() const;
    rectangle doubleDimensions();
    rectangle& setLength(double l);
    rectangle& setWidth(double w);

private:
    double length;
    double width;
};

rectangle::rectangle()
{
    length = 0;
    width = 0;
}

double rectangle::getLength() const
{
    return length;
}

double rectangle::getWidth() const
{
    return width;
}

double rectangle::area() const
{
    return length * width;
}

void rectangle::print() const
{
    cout << "Length = " << length << "; Width = " << width << endl;
}

// uses the pointer this to return the value of the entire object
rectangle rectangle::doubleDimensions()
{
    length = 2 * length;
    width = 2 * width;
    return *this;
}

// After setting the length a reference to the object, that is, the address of the object, is returned
rectangle& rectangle::setLength(double l)
{
    length = l;
    return *this;
}

// After setting the width a reference to the object, that is, the address of the object, is returned
rectangle& rectangle::setWidth(double w)
{
    width = w;
    return *this;
}

int main()
{
    rectangle oldYard;
    rectangle newYard;
    oldYard.setLength(15.00).setWidth(12.00);
    cout << fixed << showpoint << setprecision(2);
    cout << "oldYard: ";
    oldYard.print();
    cout << "newYard: ";
    newYard.print();

    cout << "Area of oldYard = " << oldYard.getLength() << " x " << oldYard.getWidth() << " = " << oldYard.area() << endl;
    newYard = oldYard.doubleDimensions();
    cout << "Area of newYard = " << newYard.getLength() << " x " << newYard.getWidth() << " = " << newYard.area() << endl;

    return 0;
}
