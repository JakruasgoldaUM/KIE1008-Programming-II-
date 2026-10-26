/**Example: friend class**/
#include <iostream>
using namespace std;

class Employee
{
    friend class Employer;
public:
    Employee(int);

private:
    int counter;
};

Employee::Employee(int c)
{
    counter = c;
}

class Employer
{
public:
    Employer() {}
    int getCount (Employee &);
};

int Employer::getCount (Employee &e)
{
    return e.counter;
}

int main()
{
    Employee e1(5);
    Employer m1;

    cout << m1.getCount(e1) << endl;

    return 0;
}
