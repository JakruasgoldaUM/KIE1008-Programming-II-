#include <iostream>
#include "Employee.h" // Employee class definition
#include "Data.h" // Date class definition
using namespace std;

// constructor uses member initializer list to pass initializer values to constructors of member objects
Employee::Employee(const string &first, const string &last,
   const Date &dob, const Date &doh)
   : firstName(first), // initialize firstName
     lastName(last), // initialize lastName
     birthDate(dob), // initialize birthDate
     hireDate(doh) // initialize hireDate
{
   // output Employee object to show when constructor is called
   cout << "Employee object constructor: "
      << firstName << ' ' << lastName << endl;
}


void Employee::print() const
{
   cout << lastName << ", " << firstName << "  Hired: ";
   hireDate.print();
   cout << "  Birthday: ";
   birthDate.print();
   cout << endl;
}

Employee::~Employee()
{
   cout << "Employee object destructor: "
      << lastName << ", " << firstName << endl;
}
