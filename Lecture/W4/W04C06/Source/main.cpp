/**Case Study: Complex Class**/

#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex c1(2.3, 4.5), c2, c3, c4;
    cout << "c1 = " << c1;
    cout << "c2 = " << c2;

    cout << endl;
    c2=c1;
    cout << "c2 = c1 gives " << c2;

    c3 = c1 + c2;
    cout << "c3 = c1 + c2 gives " << c3;

    c3 += c1;
    cout << "c3 += c1 gives " << c3;

    cout << endl;
    if (c1==c2)
        cout << "c1 same as c2\n";
    else
        cout << "c1 not same as c2\n";

    if (c1==c3)
        cout << "c1 same as c3\n";
    else
        cout << "c1 not same as c3\n";

    ++c1;
    cout << "++c1 gives " << c1;

    c1 += 2.5;
    cout << "c1 += 2.5 gives " << c1;


    cout << "\nEnter a complex number (format a+jb): ";
    cin >> c1;
    cout << "c1 is " << c1;

    return 0;
}
