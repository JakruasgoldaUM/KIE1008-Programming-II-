/**Example 1: Composition using Point and Location Classes**/
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    Point(int x = 0, int y = 0); // Constructor
    int getX() const;
    int getY() const;
    void print() const;
private:
    int x;
    int y;
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::print() const
{
   cout << "(" << x << "," << y << ")";
}

class Location
{
public:
    Location(Point, Point);
    double distance();
private:
    Point Source;
    Point Destination;
};

Location::Location(Point s, Point d)
{
    Source = s;
    Destination = d;
}

double Location::distance()
{
    int x = Destination.getX() - Source.getX();
    int y = Destination.getY() - Source.getY();
    return sqrt(pow(x, 2) + pow(y, 2) * 1.0);
}


int main()
{
    Point p1(2, 7);
    Point p2(5, 9);
    Location loc(p1, p2);

    cout << "Distance between ";
    p1.print();
    cout << " and ";
    p2.print();
    cout <<  " is " << loc.distance() << endl;
    return 0;
}
