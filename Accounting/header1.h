#ifndef HEADER1_H_INCLUDED
#define HEADER1_H_INCLUDED
#include "Baseheader.h"
class SavingAccount : public Account
{
public:
    SavingAccount(double,double);
    double calculateInterest();
    void setInterestRate(double);
    double getInterestRate()const;
private:
    double interestRate;
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(double,double);
    void setFee(double);
    double getFee()const;
    bool debit(double);
    void credit(double) override;
private:
    double fee;
};

#endif // HEADER1_H_INCLUDED
