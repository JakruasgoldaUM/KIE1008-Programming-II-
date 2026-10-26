/**Example: Proxy Class**/

#include <iostream>
#include "Interface.h"
using namespace std;

int main()
{
    Interface i(5);

    cout << "(Before) Interface contains: " << i.getValue() << endl;

    i.setValue(10);
    cout << "(After) Interface contains: " << i.getValue() << endl;
    return 0;
}



