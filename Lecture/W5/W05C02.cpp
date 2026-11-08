/**Example: Multilevel Inheritance**/

#include <iostream>
using namespace std;

//Base Class : class A
class A
{
    private:
        int a = 10;
    public:
        int get_a()
        {
            return a;
        }

        void disp_a(void)
        {
            cout << "Value of a: " << a << endl;
        }
};

//Here Class B is base class for class C and derived class for class A
class B: public A
{
    private:
        int b = 20;
    public:
        //assign value of a from here
        int get_b()
        {
            //assign value of a by calling function of class A
            return b;
        }

        void disp_b(void)
        {
            //display value of a
            disp_a();
            cout << "Value of b: " << b << endl;
        }
};

//Here class C is derived class and B is base class
class C: public B
{
    private:
        int c = 30;
    public:
        //assign value of a from here
        int sum()
        {
            /*** Multilevel Inheritance ***/
            //assign value of a, b by calling function of class B and Class A
            //here Class A is inherited on Class B, and Class B in inherited on Class B
           return c+get_b()+get_a();
        }

        void disp_c(void)
        {
            //display value of a and b using disp_b()
            disp_b();
            cout << "Value of c: " << c << endl;
        }
};

int main()
{
    //create object of final class, which is Class C
    C objC;

    cout << "a + b + c = " << objC.sum() << endl;
    objC.disp_c();

    return 0;
}
