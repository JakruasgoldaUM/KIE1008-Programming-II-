/**Example 2: Overloading << and >> Operators**/

#include <iostream>
using namespace std;

class Box
{
public:
  void setParam(int, int, int);
  friend ostream& operator<< (ostream& , const Box&);
  friend istream& operator>> (istream&, Box&);

private:
  int length, breadth, height;
};

void Box::setParam(int x, int y, int z)
{
    length = x;
    breadth = y;
    height = z;
}

ostream& operator<< (ostream& os, const Box& b)
{
    os << "length = " << b.length << "; breath = " << b.breadth << "; height = " << b.height << endl;
    return os;
}

istream& operator>> (istream& is, Box& b)
{
    cout << "Enter length, breath, height: ";
    is >> b.length;
    is >> b.breadth;
    is >> b.height;

    return is;
}

int main()
{
   Box Box1, Box2;

   Box1.setParam(4, 5, 6);
   Box2.setParam(5, 6, 7);
   cin >> Box1;
   cout << "Box 1: " << Box1 << endl;
   cout << "Box 2: " << Box2 << endl;

   return 0;
}
