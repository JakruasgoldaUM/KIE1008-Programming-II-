/**Inheritance Example 2: Point and MovablePoint Classes **/

#include <iostream>
#include "MovablePoint.h"
using namespace std;

int main()
{
   Point p1(4, 5);  // base class
   cout << "Point 1: ";
   p1.print();      // Point @ (4,5)
   cout << endl;

//   MovablePoint mp1(11, 22); // derived class, default speed
//   mp1.print();       // MovablePoint @ (11,22) Speed=(0,0)
//   cout << endl;
//   mp1.setXSpeed(8);
//   mp1.Move();
//   mp1.print();       // MovablePoint @ (19,22) Speed=(8,0)
//   cout << endl;

   MovablePoint mp2(11, 22, 33, 44);
   mp2.print();  // MovablePoint @ (11,22) Speed=(33,44)
   cout << endl;
   mp2.Move();
   mp2.print();  // MovablePoint @ (44,66) Speed=(33,44)
   cout << endl;

  return 0;
}
