/**Example: Virtual Inheritance**/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Person
{
public:
    Person(string);
protected:
    string name;
};

Person::Person(string n)
{
    name = n;
    cout << "Constructor for class Person invoked." << endl;
}

class Teacher : virtual public Person
{
public:
    Teacher(string);
    void printInfo() const;
protected:
    int staffID;
};

Teacher::Teacher(string n):Person(n)
{
    srand(time(0));
    staffID = rand()%100000;
    cout << "Constructor for class Teacher invoked." << endl;
}

void Teacher::printInfo() const
{
    cout << "Name: " << name << "; Staff ID: " << setfill('0') << setw(5) << staffID << endl;
}

class Student : virtual public Person
{
public:
    Student(string);
    void printInfo() const;
protected:
    int studentID;
};

Student::Student(string n):Person(n)
{
    studentID = rand()%100000;
    cout << "Constructor for class Student invoked." << endl;
}

void Student::printInfo() const
{
    cout << "Name: " << name << "; Student ID: " << setfill('0') << setw(5) << studentID << endl;
}

class Tutor : public Teacher, public Student
{
public:
    Tutor(string n): Person(n), Teacher(n),Student(n)
    {
        cout << "Constructor for class Tutor invoked." << endl;
    }

    void printInfo() const
    {
        cout << "Name: " << name << "; Staff ID: " << setfill('0') << setw(5) << staffID << "; Student ID: " << setfill('0') << setw(5) << studentID << endl;
    }
};

int main()
{
    Tutor s1("Ali");
    s1.printInfo();
    return 0;
}
