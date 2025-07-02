#ifndef BASEHEADER_H_INCLUDED
#define BASEHEADER_H_INCLUDED


class Account
{
public:
    Account(double = 0.0);
    void setAccountBalance(double);
    double getAccountBalance()const;
    virtual void credit(double);
    void debit(double);


private:
    double accountBalance;
};

#endif // BASEHEADER_H_INCLUDED
