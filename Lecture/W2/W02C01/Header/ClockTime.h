#ifndef CLOCK_TIME_H_INCLUDED
#define CLOCK_TIME_H_INCLUDED

class Time
{
public:
    Time();
    // set functions
    void setTime(int, int, int); // set hour, minute, second
    void setHour(int); // set hour
    void setMinute(int);

    // get functions
    int getHour(); // return hour
    int getMinute();


    void printStandard();


private:
    int hour;
    int minute;
    int second;
};

#endif // CLOCK_TIME_H_INCLUDED
