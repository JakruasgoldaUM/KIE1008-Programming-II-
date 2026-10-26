/**Time Class - Overloaded Constructors**/
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Time
{
public:
    Time(); // default constructor
    Time(int); // initialize hour; default minute and second to 0
    Time(int, int); // initialize hour and minute; default second to 0
    Time(int, int, int); // initialize hour, minute and second
    void setTime(int=0, int=0, int=0); // function with default argument
    void printStandard(); // print time in standard-time format
    ~Time();

private:
    int hour;
    int minute;
    int second;
};

Time::Time(int h, int m, int s)
{
    setTime(h, m, s);
}

Time::Time(int h, int m)
{
    setTime(h, m);
}

Time::Time(int h)
{
    setTime(h);
}

Time::Time()
{
    setTime();
}

Time::~Time()
{
    cout << "Object with h = " << hour << ", m = " << minute << ", s = " << second << " deleted." << endl;
}

void Time::setTime(int h, int m, int s)
{
    if ((h >= 0 && h < 24 ) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
    {
        hour = h;
        minute = m;
        second = s;
    }
    else
        throw invalid_argument("hour, minute and/or second was out of range");
}

void Time::printStandard()
{
    cout << ((hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" << setfill('0') << setw(2)
    << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM" ) << endl;
}

int main()
{
    Time t1; // all arguments defaulted
    Time t2(2); // hour specified; minute and second defaulted
    Time t3(21, 34); // hour and minute specified; second defaulted
    Time t4(12, 25, 42); // hour, minute and second specified
    cout << "The initial standard time of object t1 is ";
    t1.printStandard(); // 12:00:00 AM
    cout << "The initial standard time of object t2 is ";
    t2.printStandard(); // 2:00:00 AM
    cout << "The initial standard time of object t3 is ";
    t3.printStandard(); // 9:34:00 PM
    cout << "The initial standard time of object t4 is ";
    t4.printStandard(); // 12:25:42 PM

    t1.setTime(13, 27, 6); // change time of object t1
    t2.setTime(21, 13, 45); // change time of object t2

    cout << "\nStandard time of object t1 after setTime is ";
    t1.printStandard(); // 1:27:06 PM
    cout << "Standard time of object t2 after setTime is ";
    t2.printStandard(); // 9:13:45 PM

    cout << endl;

    Time t[3] = {Time(2), Time(10,15), Time(12,15,20)};

    for (int i=0; i<3; i++)
    {
        cout << "Standard time of object t[" << i << "] is ";
        t[i].printStandard();
    }

    return 0;
}
