#ifndef HEADER1_H_INCLUDED
#define HEADER1_H_INCLUDED
#include "header2.h"

class TwoDayPackage : public Package
{
public:
    TwoDayPackage(const std::string &,const std::string &,const std::string &,
            const std::string &,int = 0,int = 0,double = 0.0,double = 0.0,double = 0.0);
    void setFlyFee(double);
    double getFlyFee() const;
    virtual double calculateCost() const override;

private:
    double flyfee;
};

class OverNightPackage : public Package
{
public:
    OverNightPackage(const std::string &,const std::string &,const std::string &,
            const std::string &,int = 0,int = 0,double = 0.0,double = 0.0,double = 0.0);
    void setFlyFee3(double);
    double getFlyFee3() const;
    virtual double calculateCost() const override;

private:
    double flyfee;
};


#endif // HEADER1_H_INCLUDED
