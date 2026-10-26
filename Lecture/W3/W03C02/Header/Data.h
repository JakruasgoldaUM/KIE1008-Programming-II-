#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
public:
    static const int monthsPerYear = 12; // number of months in a year
    Date(int = 1, int = 1, int = 2000); // default constructor
    void print() const; // print date in month/day/year format
    ~Date();
private:
    int month;
    int day;
    int year;
    int checkDay(int) const; // to check if day is proper for month
};


#endif // DATE_H_INCLUDED
