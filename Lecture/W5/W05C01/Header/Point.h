#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

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

};


#endif // POINT_H_INCLUDED
