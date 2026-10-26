/**Example: static Class Members**/
#include <iostream>
using namespace std;

class Employee {
public:
    Employee(string); // constructor
    static int getCount(); // return number of objects instantiated

private:
    static int count; // number of objects instantiated
};

int Employee::count = 0; // cannot include keyword static

// define static member function
int Employee::getCount()
{
    return count;
}

Employee::Employee(string name)
{
    count++;
    cout << "Employee constructor for " << name << " called." << endl;
}

int main()
{
    cout << "Number of employees before instantiation of any objects is " << Employee::getCount() << endl;

    Employee e1("Ali");
    Employee e2("Bakar");

    cout << "Number of employees after objects are instantiated is " << Employee::getCount() << endl;

    return 0;
}
