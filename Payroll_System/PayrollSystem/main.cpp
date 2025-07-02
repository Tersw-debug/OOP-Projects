#include <iostream>
#include <string>
#include <stdexcept>
#include "Date.h"
#include "Employee.h"
#include "Salaried_Employee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include <vector>
using namespace std;
const array<unsigned int , 13> Date::days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int month1, int day1, int year1)
{
    setDate(month1,day1,year1);
}
void Date::setDate(int mm,int dd,int yy)
{
    if(mm >= 1 && mm <=12)
        month = mm;
    else
        throw invalid_argument("Month must be 1-12");
    if(yy >= 1900 && yy <= 2100)
        year = yy;
    else
        throw invalid_argument("Year must be 1900-2100");

    if((month == 2 && leapYear(year) && dd >=1 && dd <= 29) || (dd >= 1 && dd <= days[month]))
        day = dd;
    else
        throw invalid_argument("Day is out of range of current year and current month");

}

unsigned int Date::getMonth() const
{
    return month;
}

Date &Date::operator++()
{
    helpIncrement();
    return *this;
}
Date Date::operator++(int)
{
    Date temp = *this;
    helpIncrement();
    return temp;
}

Date &Date::operator+=(unsigned int addtionalDays)
{
    for(int i = 0;i < addtionalDays;++i)
        helpIncrement();
    return *this;
}

bool Date::leapYear(int testyear)
{
    if(testyear % 400 == 0 || (testyear % 100 != 0 && testyear % 4 == 0)) return true;
    else return false;
}

bool Date::endOfMonth(int edm) const
{
    if(month == 2 && leapYear(year) == true)
    {
        return edm == 29;
    }
    else return edm == days[month];
}

void Date::helpIncrement()
{
    if(!endOfMonth(day))
        day++;
    else
        if(month < 12)
        {
            ++month;
            day = 1;
        }
        else{
            year++;
            month = 1;
            day = 1;
        }

}

ostream &operator<<(ostream &output,const Date &de)
{
    static string monthName[ 13 ] = { "", "January", "February",
    "March", "April", "May", "June", "July", "August",
    "September", "October", "November", "December" };
    output << monthName[de.month] << "/" << de.day << "/" << de.year;
    return output;
}
Employee::Employee(const string &fn,const string &ln,const string &ssl,const Date &bir)
    : firstName(fn) , lastName(ln) , soicalSecurityNumber(ssl)
{
    birthdate = bir;
    Date intalize(bir);
}

unsigned int Employee::getCurrentMonth() const
{
    return birthdate.getMonth();
}

void Employee::setFirstName(const string &first)
{
    firstName = first;
}

void Employee::setLastName(const string &last)
{
    lastName = last;
}

void Employee::setSoicalSecurityNumber(const string &ssle)
{
    soicalSecurityNumber = ssle;
}

string Employee::getFirstName() const
{
    return firstName;
}

string Employee::getLastName() const
{
    return lastName;
}

string Employee::getSoicalSecurityNumber() const
{
    return soicalSecurityNumber;
}

void Employee::print() const
{
    cout << getFirstName()<< " " << getLastName() << "\nSSL: " << getSoicalSecurityNumber() <<   "\nBirthDate: " << birthdate;
}


SalariedEmployee::SalariedEmployee(const string &fn1,const string &ln2,const string &ssl1,const Date &bir1,double salary)
    :   Employee(fn1,ln2,ssl1,bir1)
{
    setWeeklySalary(salary);
}

void SalariedEmployee::setWeeklySalary(double sal)
{
    if(sal >= 0.0)
        weeklySalary = sal;
    else
        throw invalid_argument("Weekly must be >= 0.0");
}

double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary ;
}

double SalariedEmployee::earning() const
{
    return getWeeklySalary();
}

void SalariedEmployee::print() const
{
    cout << "Salaried Employee: " ;
    Employee::print();
    cout  << "\nWeekly-Salary: " << getWeeklySalary()<< "\n";
}

CommissionEmployee::CommissionEmployee(const string &f2,const string &l2,const string &ssl2, const Date &bir2, double grosssale, double rate)
    :   Employee(f2,l2,ssl2,bir2)
{
    setGrossSales( grosssale );
    setCommissionEmployee(rate);
}


void CommissionEmployee::setGrossSales(double sale)
{
    if(sale >= 0.0)
        grossSales = sale;
    else
        throw invalid_argument("GrossSales must be >= 0.0");
}

double CommissionEmployee::getGrossSales() const
{
   return grossSales;
}


void CommissionEmployee::setCommissionEmployee(double sale)
{
    if(sale >= 0.0)
        commissionRate = sale;
    else
        throw invalid_argument("Commission Rate must be >= 0.0");
}

double CommissionEmployee::getCommissionEmployee() const
{
   return commissionRate;
}

double CommissionEmployee::earning() const
{
    return getCommissionEmployee() * getGrossSales();
}

void CommissionEmployee::print() const
{
    cout << "Commission Employee: " ;
    Employee::print();
    cout << "\nGross Sales: " << getGrossSales() << "\nCommission Rate: " << getCommissionEmployee()<< "\n";
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &f3,const string &l3,const string &ssl3, const Date &bir3, double sales, double rate, double salary)
    :   CommissionEmployee(f3,l3,ssl3,bir3,sales,rate)
{
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double sale)
{
    if(sale >= 0.0)
        baseSalary = sale;
    else
        invalid_argument("Salary must be >= 0.0");
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

double BasePlusCommissionEmployee::earning() const
{
    return getBaseSalary() + CommissionEmployee::earning();
}

void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried"<<endl;
    CommissionEmployee::print();
    cout << "\nBase Salary: " << getBaseSalary() << "\n";
}


void earningAccessByPointer(const Employee * const ptr)
{
     ptr->print();
    if(ptr->getCurrentMonth() == 6)
    {
        cout <<"Eearning of Month: "<< ptr->earning() + 100.0 << endl;
    }
    cout <<"\n";

}


int main()
{
    Date ob1(6,5,2000);
    SalariedEmployee ob2("Mark","Smith", "244410003560",ob1 ,200);
    ob1.setDate(6,8,2002);
    CommissionEmployee ob3("Mina", "Mage2d", "31114560004", ob1,1500,0.5);
    ob1.setDate(6,14,2004);
    BasePlusCommissionEmployee ob4("Neinm","Alexandro", "15687N4202359",ob1,3000,0.75,1300);
    vector<Employee *>employees(3);
    employees[0] = &ob2;
    employees[1] = &ob3;
    employees[2] = &ob4;
    for(const Employee *employeePtr : employees)
    earningAccessByPointer(employeePtr);
    return 0;
}
