/**Example 1: Overloading << and >> Operators**/

#include <iostream>
using namespace std;

class Point
{
private:
   int x, y;

public:
   Point(int x = 0, int y = 0); // Constructor
   int getX() const;
   int getY() const;
   void setX(int x);
   void setY(int y);
   void print() const;
   friend ostream &operator<<(ostream & out, const Point & point);
   friend istream &operator>>(istream & in, Point & point);

};

Point::Point(int x, int y) : x(x), y(y) { }

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

void Point::print() const
{
   cout << "(" << x << "," << y << ")" << endl;
}

ostream & operator<<(ostream & out, const Point & point)
{
   out << "(" << point.x << "," << point.y << ")";  // access private data
   return out;
}

istream & operator>>(istream & in, Point & point)
{
   cout << "Enter x and y coord: ";
   in >> point.x >> point.y;  // access private data
   return in;
}

int main() {
   Point p1(1, 2), p2;

   // Using overloaded operator "<<"
   cout << p1 << endl;    // support cascading
   operator<<(cout, p1);  // same as cout << p1
   cout << endl;

   // Using overloaded operator >>
   cin >> p1;
   cout << p1 << endl;
   operator>>(cin, p1);  // same as cin >> p1
   cout << p1 << endl;
   cin >> p1 >> p2;      // support cascading
   cout << "p1 = " << p1 <<  "; p2 = " << p2 << endl;
}

