#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class pointType
{
private:
    double x, y;

public:
    // Parameterized constructor
    pointType()
    {
        x = 0;
        y = 0;
    }

    // Default constructor initializes coordinates
    pointType(double xCoord, double yCoord)
    {
        x = xCoord;
        y = yCoord;
    }

    // Set and retrieve x-coordinate
    void setX(double xCoord)
    {
        x = xCoord;
    }

    double getX() const
    {
        return x;
    }

    // Set and retrieve y-coordinate
    void setY(double yCoord)
    {
        y = yCoord;
    }

    double getY() const
    {
        return y;
    }

    // Calculate distance between two points
    double distance(const pointType& p) const
    {
        double dx = x - p.x;
        double dy = y - p.y;

        return sqrt(pow(dx, 2) + pow(dy, 2));
    }
};

class lineType
{
private:
    pointType p1, p2;

public:
    // Default constructor
    lineType()
    {
        p1 = pointType(0, 0);
        p2 = pointType(1, 1);
    }

    // Parameterized constructor
    lineType(pointType point1, pointType point2)
    {
        p1 = point1;
        p2 = point2;
    }

    // Determine whether the line is vertical
    bool isVertical() const
    {
        return p1.getX() == p2.getX();
    }

    // Determine whether the line is horizontal
    bool isHorizontal() const
    {
        return p1.getY() == p2.getY();
    }

    // Determine whether the line is slanted
    bool isSlanted() const
    {
        return !isVertical() && !isHorizontal();
    }

    // Calculate slope (except vertical lines)
    double getSlope() const
    {
        return (p2.getY() - p1.getY()) /
               (p2.getX() - p1.getX());
    }

    // Output the equation of the line
    void printEquation() const
    {
        cout << fixed << setprecision(2);

        if (isVertical())
        {
            cout << "Equation: x = " << p1.getX() << endl;
        }
        else
        {
            double m = getSlope();
            double c = p1.getY() - m * p1.getX();

            cout << "Equation: y = " << m << "x";

            if (c >= 0)
                cout << " + " << c;
            else
                cout << " - " << -c;

            cout << endl;
        }
    }
};

int main()
{
    double x1, y1, x2, y2;

    cout << "Enter coordinates of point 1 (x,y): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of point 2 (x,y): ";
    cin >> x2 >> y2;

    pointType p1(x1, y1);
    pointType p2(x2, y2);

    lineType line(p1, p2);

    if (line.isVertical())
        cout << "The line is vertical." << endl;
    else if (line.isHorizontal())
        cout << "The line is horizontal." << endl;
    else
        cout << "The line is slanted." << endl;

    if (!line.isVertical())
        cout << "Slope: " << line.getSlope() << endl;
    else
        cout << "Slope: Undefined" << endl;

    line.printEquation();

    return 0;
}
