/**Example 1: Overloading '+' Operator**/

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
   Point operator+(const Point & rhs);
};

Point::Point(int x, int y) : x(x), y(y) { }

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

void Point::print() const {
   cout << "(" << x << "," << y << ")" << endl;
}

Point Point::operator+(const Point & rhs) { //need to defined correctly beforehand
   return Point(x + rhs.x, y + rhs.y);
}


int main()
{
   Point p1(1, 2), p2(4, 5);
   // Use overloaded operator +
   Point p3 = p1 + p2;
   cout << "Points for p1 are ";
   p1.print();  // (1,2)
   cout << "Points for p2 are ";
   p2.print();  // (4,5)
   cout << "Points for p3 are ";
   p3.print();  // (5,7)

   // Invoke via usual dot syntax, same as p1+p2
   Point p4 = p1.operator+(p2);
   cout << "Points for p4 are ";
   p4.print();  // (5,7)

   // Chaining
   Point p5 = p1 + p2 + p3 + p4;
   cout << "Points for p5 are ";
   p5.print();  // (15,21)
}
