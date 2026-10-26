/**Example 2: Composition using Employee and Date Classes**/
#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
    Date birth(7, 24, 2000);
    Date hire(3, 12, 2020);
    Employee manager("Bob", "Blue", birth, hire);

    cout << endl;
    manager.print();
    return 0;
}
