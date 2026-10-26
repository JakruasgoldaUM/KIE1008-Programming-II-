/**Example: Dynamic Memory Management**/

#include <iostream>
using namespace std;

int main()
{
    int *p, *q;

    p = new int;
    *p = 34;
    cout << "Initial p = " << p << ", *p = " << *p << endl;

    p = new int;
    *p = 18;
    cout << "New p = " << p << ", *p = " << *p << endl;

    *q = 45;
    cout << "Initial q = " << q << ", *q = " << *q << endl;

    delete q;
    q = new int;
    *q = 62;
    cout << "New q = " << q << ", *q = " << *q << endl;

    return 0;
}
