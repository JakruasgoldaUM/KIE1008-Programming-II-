/**Example: Multiple Inheritance**/

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
public:
    Date(int = 1, int = 1, int = 2000); // default constructor
    void printDate() const; // print date in month/day/year format

private:
    int month;
    int day;
    int year;
};

Date::Date(int d, int m, int y)
{
   if (m > 0 && m <= 12) // validate the month
      month = m;
   else
      throw invalid_argument("month must be 1-12");

   year = y;
   day = d;
}


void Date::printDate() const
{
cout << month << '/' << day << '/' << year;
}


class Time {
public:
    Time(int = 0, int = 0, int = 0); // default constructor
    void printTime() const; // print date in month/day/year format

private:
    int hour;
    int minute;
    int second;
};

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

void Time::printTime() const
{
    cout << ((hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" << setfill('0') << setw(2)
    << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM" ) << endl;
}

class DateTime : public Date, public Time
{
public:
    DateTime();
    DateTime(int, int, int, int, int, int);
};

DateTime::DateTime()
{
   cout << "Date is ";
   printDate();
   cout << "; Time is ";
   printTime();
}

DateTime::DateTime(int dy, int mon, int yr, int hr, int mt, int sc) :
    Date(dy, mon, yr), Time(hr, mt, sc)
{
   cout << "Date is ";
   printDate();
   cout << "; Time is ";
   printTime();
}


int main()
{
    DateTime Day1;
    DateTime Day2(31, 10, 2021, 15, 32, 27);
    return 0;
}
