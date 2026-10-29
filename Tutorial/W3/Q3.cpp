#include <iostream>
#include <string>
using namespace std;

// Proxy class
class student
{
private:
    string name;
    int age;
    string gender;

public:
    student(string n, int a, string g)
    {
        name = n;
        age = a;
        gender = g;
    }

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    string getGender() const
    {
        return gender;
    }

    void setAge(int a)
    {
        age = a;
    }

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class postgrad; // Forward declaration

// Undergraduate class
class undergrad
{
private:
    student s; // Proxy

public:
    undergrad(string n, int a, string g)
        : s(n, a, g)
    {
    }

    void display() const
    {
        cout << "\nUndergraduate Student" << endl;
        s.display();
    }

    friend void modifyAge(undergrad& u, postgrad& p,int newUndergradAge,int newPostgradAge);
};

// Postgraduate class
class postgrad
{
private:
    student s; // Proxy

public:
    postgrad(string n, int a, string g)
        : s(n, a, g)
    {
    }

    void display() const
    {
        cout << "\nPostgraduate Student" << endl;
        s.display();
    }

    friend void modifyAge(undergrad& u, postgrad& p,int newUndergradAge,int newPostgradAge);
};

// Friend function
void modifyAge(undergrad& u, postgrad& p,int newUndergradAge,int newPostgradAge)
{
    u.s.setAge(newUndergradAge);
    p.s.setAge(newPostgradAge);
}

int main()
{
    undergrad u("Raymond", 20, "Male");
    postgrad p("Ke Xin", 24, "Female");

    cout << "Before modifying age:" << endl;
    u.display();
    p.display();

    modifyAge(u, p, 21, 25);

    cout << "\nAfter modifying age:" << endl;
    u.display();
    p.display();

    return 0;
}
