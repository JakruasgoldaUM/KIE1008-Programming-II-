#include <iostream>
using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Clock(int h = 0, int m = 0, int s = 0) {
        setTime(h, m, s);
    }

    // Function to set the time
    void setTime(int h, int m, int s) {
        if (h >= 0 && h < 24) hours = h; else hours = 0;
        if (m >= 0 && m < 60) minutes = m; else minutes = 0;
        if (s >= 0 && s < 60) seconds = s; else seconds = 0;
    }

    // Function to print the current time
    void printTime() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    // Function to compare two clocks
    bool equals(const Clock& otherClock) const {
        return (hours == otherClock.hours && minutes == otherClock.minutes && seconds == otherClock.seconds);
    }

    // Function to add one hour to the clock
    void incrementHour() {
        hours = (hours + 1) % 24;
    }

    // Overloading the assignment operator
    Clock& operator=(const Clock& otherClock) {
        if (this != &otherClock) { // Check for self-assignment
            hours = otherClock.hours;
            minutes = otherClock.minutes;
            seconds = otherClock.seconds;
        }
        return *this;
    }
};

int main() {
    // a) Define a class object myClock with parameters hours = 8, minutes = 12, and seconds = 30
    Clock myClock(8, 12, 30);
    cout << "myClock: ";
    myClock.printTime();

    // b) Define another class object yourClock with parameters hours = 12, minutes = 35, and seconds = 45
    Clock yourClock(12, 35, 45);
    cout << "yourClock: ";
    yourClock.printTime();

    // c) Change the parameters in myClock using setTime() function to hours = 3, minutes = 48, seconds = 52
    myClock.setTime(3, 48, 52);
    cout << "myClock after setTime: ";
    myClock.printTime();

    // d) Compare the values between myClock and yourClock. Print out the result
    if (myClock.equals(yourClock)) {
        cout << "myClock and yourClock are the same." << endl;
    } else {
        cout << "myClock and yourClock are different." << endl;
    }

    // e) Assign the values of myClock into yourClock using assignment operator (=)
    yourClock = myClock;
    cout << "yourClock after assignment from myClock: ";
    yourClock.printTime();

    // f) Compare again the values between myClock and yourClock
    if (myClock.equals(yourClock)) {
        cout << "myClock and yourClock are the same after assignment." << endl;
    } else {
        cout << "myClock and yourClock are different after assignment." << endl;
    }

    // g) Increase myClock to an hour faster
    myClock.incrementHour();
    cout << "myClock after increasing by one hour: ";
    myClock.printTime();

    return 0;
}