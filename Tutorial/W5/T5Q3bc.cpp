#include <iostream>
#include <string>
using namespace std;

class employee
{
    public:
     void setData(string n = "", string d = "", int a = 0,
                  double p = 0);
     void setName(string n);
     string getName() const;
     void setDepartment(string dept);
     string getDepartment() const;
     void setAge(int a);
     int getAge() const;
     void setPay(double p);
     double getPay() const;

     employee(string n = "", string d = "", int a = 0, 
              double p = 0);

    private:
     string name;
     string department;
     int age;
     double pay;
};

class hourlyEmployee: public employee
{
  public:
   void setData(string n = "", string d = "", int a = 0, double
                p = 0, double hrsWk = 0, double payRate = 0.0);  
   void setHoursWorked(double hrsWk);
   double getHoursWorked() const;
   void setHourlyPayRate(double payRate);
   double getHourlyPayRate() const;
   void setPay();
   hourlyEmployee(string n = "", string d = "", int a = 0, double
                   p = 0, double hrsWk = 0, double payRate = 0.0);
  private:
   double hoursWorked;
   double hourlyPayRate;
};

void employee::setData(string n, string d, int a, double p)
{
    setName(n);
    setDepartment(d);
    setAge(a);
    setPay(p);
}

void employee::setName(string n)
{
    name = n;
}

string employee::getName() const
{
    return name;
}

void employee::setDepartment(string dept)
{
    department = dept;
}

string employee::getDepartment() const
{
    return department;
}

void employee::setAge(int a)
{
    age = a;
}

int employee::getAge() const
{
    return age;
}

void employee::setPay(double p)
{
    pay = p;
}

double employee::getPay() const
{
    return pay;
}

employee::employee(string n, string d, int a, double p)
    : name(n), department(d), age(a), pay(p)
{
}

hourlyEmployee::hourlyEmployee(string n, string d, int a, double p,
                               double hrsWk, double payRate)
    : employee(n, d, a, p), hoursWorked(0), hourlyPayRate(0)
{
    setHoursWorked(hrsWk);
    setHourlyPayRate(payRate);
}

void hourlyEmployee::setData(string n, string d, int a, double p, double hrsWk, double payRate)
{
    employee::setData(n, d, a, p);
    setHourlyPayRate(payRate);
    setHoursWorked(hrsWk);
    setPay();
}

void hourlyEmployee::setHoursWorked(double hrsWk)
{
    if (hrsWk >= 0)
     hoursWorked = hrsWk;
    else 
     hoursWorked = 0;
    setPay();
}

double hourlyEmployee::getHoursWorked() const
{
    return hoursWorked;
}

void hourlyEmployee::setHourlyPayRate(double payRate)
{
    if (payRate >= 0)
        hourlyPayRate = payRate;
    else
        hourlyPayRate = 0;
    setPay();
}

double hourlyEmployee::getHourlyPayRate() const
{
    return hourlyPayRate;
}

void hourlyEmployee::setPay()
{
    employee::setPay(hoursWorked * hourlyPayRate);
}

int main()
{
    hourlyEmployee worker("Alex", "IT", 30, 0, 40, 25.50);

    cout << "Name: " << worker.getName() << '\n'
         << "Department: " << worker.getDepartment() << '\n'
         << "Age: " << worker.getAge() << '\n'
         << "Hours worked: " << worker.getHoursWorked() << '\n'
         << "Hourly pay rate: " << worker.getHourlyPayRate() << '\n'
         << "Pay: " << worker.getPay() << '\n';

    return 0;
}
