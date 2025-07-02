#include <iostream>
#include <string>
#include <stdexcept>
#include "Employee.h"
#include "Salaried_Employee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"
#include <vector>
using namespace std;

Employee::Employee(const string &fn,const string &ln,const string &ssl)
    : firstName(fn) , lastName(ln) , soicalSecurityNumber(ssl)
{

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
    cout << getFirstName()<< " " << getLastName() << "\nSSL: " << getSoicalSecurityNumber() ;
}


SalariedEmployee::SalariedEmployee(const string &fn1,const string &ln2,const string &ssl1,double salary)
    :   Employee(fn1,ln2,ssl1)
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

CommissionEmployee::CommissionEmployee(const string &f2,const string &l2,const string &ssl2, double grosssale, double rate)
    :   Employee(f2,l2,ssl2)
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

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &f3,const string &l3,const string &ssl3,  double sales, double rate, double salary)
    :   CommissionEmployee(f3,l3,ssl3,sales,rate)
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

PieceWorker::PieceWorker(const string &f4,const string &l4,const string &ssl4,  double piece, double wag)
    :   Employee(f4,l4,ssl4)
{
    setPayPieces(piece);
    setPayWageP(wag);
}

void PieceWorker::setPayPieces(double p)
{
    if(p >= 0.0)
        pieces = p;
    else
        throw invalid_argument("Pieces must be >= 0.0");
}

void PieceWorker::setPayWageP(double w)
{
    if(w >= 0.0)
        wage = w;
    else
        throw invalid_argument("Wage must be >= 0.0");
}


double PieceWorker::getPayPieces() const
{
   return pieces;
}

double PieceWorker::getPayWageP()   const
{
       return wage;
}

double PieceWorker::earning() const
{
    return getPayWageP() * getPayPieces();
}

void PieceWorker::print() const
{
    cout << "PiecesWorker:";
    Employee::print();
    cout << "\nPieces Number: " << getPayPieces() << "\nWage: "<< getPayWageP() <<endl;
}





HourlyWorker::HourlyWorker(const string &f5,const string &l5,const string &ssl5,  double hour, double wag)
    :   Employee(f5,l5,ssl5)
{
    setPayHour(hour);
    setPayWageH(wag);
}
void HourlyWorker::setPayWageH(double w)
{
    if(w >= 0.0)
        wage = w;
    else
        throw invalid_argument("Wage must be >= 0.0");
}


double HourlyWorker::getPayWageH()   const
{
       return wage;
}


void HourlyWorker::setPayHour(double p)
{
    if(p >= 0.0){
        hours = p;
    }
    else
        throw invalid_argument("Hours must be >= 0.0");
}

double HourlyWorker::getPayHour()   const
{
       return hours;
}

double HourlyWorker::earning() const
{
    if(getPayHour() > 40.0)
        return (getPayHour() - 40) * 1.5 * getPayWageH() + 40 * getPayWageH();
    else
        return getPayHour() * getPayWageH();
}

void HourlyWorker::print() const
{
    cout << "Hourly-Workter: ";
    Employee::print();
    cout << "\nNumber of Hours: " << getPayHour() << "\nWage: " << getPayWageH() << endl;
}


void earningAccessByPointer(const Employee * const ptr)
{
     ptr->print();
     cout << "The earnings: " << ptr->earning();
    cout <<"\n";

}


int main()
{

    SalariedEmployee ob2("Mark","Smith", "244410003560",200);

    CommissionEmployee ob3("Mina", "Mage2d", "31114560004",1500,0.5);

    BasePlusCommissionEmployee ob4("Neinm","Alexandro", "15687N4202359",3000,0.75,1300);

    PieceWorker ob5("Nuyem","Ali", "3791462850", 120,30);

    HourlyWorker ob6("Koko","Mag2ed", "167913482591", 50, 30);
    vector<Employee *>employees(5);
    employees[0] = &ob2;
    employees[1] = &ob3;
    employees[2] = &ob4;
    employees[3] = &ob5;
    employees[4] = &ob6;
    for(const Employee *employeePtr : employees)
    earningAccessByPointer(employeePtr);
    return 0;
}
