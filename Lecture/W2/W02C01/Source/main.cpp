/**Example: Using set and get functions in Time Class**/
#include <iostream>
#include "ClockTime.h"
using namespace std;

int main()
{
    Time t;
    t.setTime(12, 34, 56);
    cout << "Current time is ";
    t.printStandard();

    cout << "Current hour: " << t.getHour() << endl;

    t.setHour(21);

    cout << "Time after hour being modified to " << t.getHour() << " is ";
    t.printStandard();

    return 0;
}
