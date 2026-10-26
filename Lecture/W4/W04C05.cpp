/**Example: Overloading Prefix and Postfix**/

#include <iostream>
using namespace std;

class Counter
{
private:
   int count;
public:
   Counter(int count = 0);   // Constructor
   int getCount() const;
   void setCount(int count);
   Counter & operator++();              // ++prefix
   const Counter operator++(int dummy); // postfix++

   friend ostream &operator<<(ostream & out, const Counter &);
};

Counter::Counter(int c) : count(c) { } // using member initializer list

int Counter::getCount() const { return count; }

void Counter::setCount(int c) { count = c; }

// ++prefix, return reference of this
Counter & Counter::operator++() {
   ++count;
   return *this;
}

// postfix++, return old value by value
const Counter Counter::operator++(int dummy) {
   Counter old(*this);
   ++count;
   return old;
}

// Overload stream insertion << operator
ostream & operator<<(ostream & out, const Counter & counter) {
   out << counter.count;
   return out;
}

int main()
{
   Counter c1;
   cout << c1 << endl;     // 0
   cout << ++c1 << endl;   // 1
   cout << c1 << endl;     // 1
   cout << c1++ << endl;   // 1
   cout << c1 << endl;     // 2
   cout << ++++c1 << endl; // 4
// cout << c1++++ << endl; // error caused by const return value
}
