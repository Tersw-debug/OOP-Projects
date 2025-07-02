#ifndef HOURLYWORKER_H_INCLUDED
#define HOURLYWORKER_H_INCLUDED
#include "Employee.h"
#include <string>
class HourlyWorker : public Employee
{
public:
    HourlyWorker(const std::string &,const std::string &,const std::string &,double = 0.0, double = 0.0);
    virtual ~HourlyWorker() { }

    void setPayHour(double);
    double getPayHour() const;
     void setPayWageH(double);
    double getPayWageH() const;

    virtual double earning() const override;
    virtual void print() const override;
private:
    double wage;
    double hours;
};


#endif // HOURLYWORKER_H_INCLUDED
