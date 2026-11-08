#include <iostream>
#include <cmath>
using namespace std;

class circle //base class
{
    public:
     void print() const;
     void setRadius(double);
     void setCenter(double, double);
     void getCenter(double&, double &);
     double getRadius();
     double area();
     circle(); //constructor 
     circle(double, double, double);
    private:
     double xCoordinate;
     double yCoordinate;
     double radius;
};

//cylinder as inheritance of class circle
class cylinder: public circle //derived class
{
 public:
     void print() const;
     void setHeight(double);
     double getHeight();
     double area();// b) area() overrides the area() member function of base class circle
     double volume();
     cylinder(); //constructor 
     cylinder(double, double, double, double);
    private:
     double height;
};

//a) Definitions of member functions of class circle
circle::circle()
{
    xCoordinate = 0.0;
    yCoordinate = 0.0;
    radius = 0.0;
}

circle::circle(double x, double y, double r)
{
    xCoordinate = x;
    yCoordinate = y;
    radius = r;
}

void circle::setRadius(double r)
{
    if (r >= 0)
       radius = r;
    else
       radius = 0;
}

void circle::setCenter(double x, double y)
{
    xCoordinate = x;
    yCoordinate = y;
}

void circle::getCenter(double &x, double &y)
{
    x = xCoordinate;
    y = yCoordinate;
}

double circle::getRadius()
{
    return radius;
}

double circle::area()
{
    return 3.14159 * pow(radius, 2);
}

void circle::print() const
{
    cout << "Center = (" << xCoordinate << "," << yCoordinate << ") Radius = " << radius << endl;
}

//a) Definitions of member functions of class cylinder
//default constrcutor calls base class default constructor
cylinder::cylinder() 
{
    height = 0.0;
}

//parameterized constructor calls base class parameterized constructor
cylinder::cylinder(double x, double y, double r, double h) 
: circle(x, y, r)
{
    height = h;
}

void cylinder::setHeight(double h)
{
    if (h >= 0)
       height = h;
    else 
       height = 0;
}

double cylinder::getHeight()
{
    return height;
}

double cylinder::area()
{
    return 2 * circle::area() + 2 * 3.14159 * getRadius() * height;
}

double cylinder::volume()
{
    return circle::area() * height;
}

//b) this member function of derived class cylinder 
//overrides the print() member function of base class circle
void cylinder::print() const 
{
    circle::print();
    cout << "Height = " << height << endl;
}

int main()
{
    circle c1(1.0, 2.0, 3.0);
    c1.print();
    cout << "Area of circle c1= " << c1.area() << endl;

    cylinder cy1(4.0, 5.0, 6.0, 7.0);
    cout << endl;
    cy1.print();
    cout << "Area of cylinder cy1= " << cy1.area() << endl;
    cout << "Volume of cylinder cy1= " << cy1.volume() << endl;
    
    //c) object newCylinder has 4 private data members,
    //3 inherited from base class circle and 
    //1 from derived class cylinder
    cylinder newCylinder;
    newCylinder.setCenter(8.0, 9.0);
    newCylinder.setRadius(10.0);
    newCylinder.setHeight(11.0);
    cout << "\nFor newCylinder, "<< endl;
    newCylinder.print();
    cout << "Area of newCylinder= " << newCylinder.area() << endl;
    cout << "Volume of newCylinder= " << newCylinder.volume() << endl;

    return 0;
}