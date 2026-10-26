#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <string>
#include "Data.h" // include Date class definition
using namespace std;

class Employee
{
public:
   Employee(const string &, const string &, const Date &, const Date & );
   void print() const;
   ~Employee(); // provided to confirm destruction order
private:
   string firstName;
   string lastName;
   const Date birthDate; // composition: member object
   const Date hireDate; // composition: member object
};


#endif // EMPLOYEE_H_INCLUDED
