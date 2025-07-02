#ifndef SALARIED_EMPLOYEE_H_INCLUDED
#define SALARIED_EMPLOYEE_H_INCLUDED
#include "Employee.h"
#include <string>

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string &,const std::string &,const std::string &,double = 0.0);
    virtual ~SalariedEmployee() { }
    void setWeeklySalary(double);
    double getWeeklySalary() const;
    virtual double earning() const override;
    virtual void print() const override;
private:
    double weeklySalary;
};


#endif // SALARIED_EMPLOYEE_H_INCLUDED
