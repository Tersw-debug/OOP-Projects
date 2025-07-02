#ifndef PIECEWORKER_H_INCLUDED
#define PIECEWORKER_H_INCLUDED
#include "Employee.h"
#include <string>
class PieceWorker : public Employee
{
public:
    PieceWorker(const std::string &,const std::string &,const std::string &,double = 0.0, double = 0.0);
    virtual ~PieceWorker() { }

    void setPayPieces(double);
    double getPayPieces() const;
    void setPayWageP(double);
    double getPayWageP() const;


    virtual double earning() const override;
    virtual void print() const override;
private:
    double wage;
    double pieces;
};

#endif // PIECEWORKER_H_INCLUDED
