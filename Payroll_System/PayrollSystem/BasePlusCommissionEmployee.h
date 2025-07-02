#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H_INCLUDED
#define BASEPLUSCOMMISSIONEMPLOYEE_H_INCLUDED
#include <string>
#include "Date.h"
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:

    BasePlusCommissionEmployee(const std::string &,const std::string &,const std::string &,const Date &,double = 0.0,double = 0.0,double = 0.0);
    virtual ~BasePlusCommissionEmployee() {}


    void setBaseSalary(double);
    double getBaseSalary()const;

    virtual double earning() const override;
    virtual void print() const override;
private:
    double baseSalary;
};


#endif // BASEPLUSCOMMISSIONEMPLOYEE_H_INCLUDED
