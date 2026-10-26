/**Example 2: Overloading '+' Operator**/
#include <iostream>

using namespace std;

class Box
{
public:
  void setParam(int, int, int);
  int getVol();
  Box operator+ (const Box& b);

private:
      int length, breadth, height;
};

void Box::setParam(int x, int y, int z)
{
    length = x;
    breadth = y;
    height = z;
}

int Box::getVol()
{
    return length * breadth * height;
}

Box Box::operator+(const Box& b)
{
     Box box;
     box.length = this->length + b.length;
     box.breadth = this->breadth + b.breadth;
     box.height = this->height + b.height;
     return box;
}

int main()
{
   Box Box1, Box2, Box3;

   Box1.setParam(4, 5, 6);
   Box2.setParam(5, 6, 7);
   Box3 = Box1 + Box2;

   cout << Box1.getVol() << endl;
   cout << Box2.getVol() <<endl;
   cout << Box3.getVol() <<endl;

    return 0;
}
