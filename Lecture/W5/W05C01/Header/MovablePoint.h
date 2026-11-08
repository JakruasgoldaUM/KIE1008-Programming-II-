/**Inheritance Example 2: Point and MovablePoint Classes **/
#ifndef MOVABLEPOINT_H_INCLUDED
#define MOVABLEPOINT_H_INCLUDED

#include "Point.h"

class MovablePoint : public Point
{
private:
   int xSpeed, ySpeed;

public:
   MovablePoint(int x, int y, int xSpeed = 0, int ySpeed = 0);
   int getXSpeed() const;
   int getYSpeed() const;
   void setXSpeed(int x);
   void setYSpeed(int y);
   void Move();
   void print() const;
};


#endif // MOVABLEPOINT_H_INCLUDED
