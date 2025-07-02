#include <iostream>
#include <stdexcept>
#include "Baseheader.h"
#include "header1.h"
#include <vector>
using namespace std;
Account::Account(double term)
{

    setAccountBalance(term);
}
void Account::setAccountBalance(double te)
{
    if(te >= 0.0)
        accountBalance = te;
    else
        throw invalid_argument("Error: Account balance must be positve or 0");
}
void Account::credit(double add)
{
    accountBalance += add;
}
void Account::debit(double withdrw)
{
    if(withdrw > accountBalance)
        throw invalid_argument("Debit amount exceeded account balance.");
    else
        accountBalance -= withdrw;
}


double Account::getAccountBalance() const
{
    return accountBalance;
}

SavingAccount::SavingAccount(double balance, double rate)
    :   Account(balance)
{
    setInterestRate(rate);
}
void SavingAccount::setInterestRate(double ret)
{
    if(ret > 0.0)
        interestRate = ret;
    else
        throw invalid_argument("Error: Interest Rate must be positve perctenage");
}
double SavingAccount::getInterestRate() const
{
    return interestRate;
}
double SavingAccount::calculateInterest()
{
    return interestRate * getAccountBalance();
}

CheckingAccount::CheckingAccount(double balance,double fee)
    :   Account(balance)
{
    setFee(fee);
}

void CheckingAccount::setFee(double f)
{
    fee = f;
}
double CheckingAccount::getFee() const
{
    return fee;
}
bool CheckingAccount::debit(double taking)
{
    if(taking > getAccountBalance()){return false;}
    else{setAccountBalance((getAccountBalance() - taking - getFee())) ; return true;}
}

void CheckingAccount::credit(double add)
{
    setAccountBalance(getAccountBalance() + add - getFee());
}


int main()
{
    SavingAccount ob1(50000,0.5);
    CheckingAccount ob2(60000,350);
    vector< Account * > acc(2);
    acc[0] = &ob1;
    acc[1] = &ob2;
    for( Account * accptr:acc){
        SavingAccount *dptr = dynamic_cast<SavingAccount * >(accptr);
        if(dptr != nullptr)
        {
            double temp = dptr->calculateInterest() + dptr->getAccountBalance();
            dptr->credit(temp);
            cout << "Saving Account: " << dptr->getAccountBalance() <<endl;
        }
        else
        {
            cout << "Checking Account: " << accptr->getAccountBalance() << endl;
        }
    }

    for(Account * deletptr : acc)
        delete deletptr;
    return 0;
}
