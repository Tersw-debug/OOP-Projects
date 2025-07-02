#ifndef COMMISSIONEMPLOYEE_H_INCLUDED
#define COMMISSIONEMPLOYEE_H_INCLUDED
#include <string>
#include "Employee.h"

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const std::string &,const std::string &,const std::string &,double = 0.0, double = 0.0);
    virtual ~CommissionEmployee() { }
    void setCommissionEmployee(double);
    double getCommissionEmployee()const;

    void setGrossSales(double);
    double getGrossSales()const;

    virtual double earning() const override;
    virtual void print() const override;
private:
    double grossSales;
    double commissionRate;
};

#endif // COMMISSIONEMPLOYEE_H_INCLUDED
