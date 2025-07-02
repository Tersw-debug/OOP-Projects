#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "Date.h"
#include <string>

class Employee
{
public:
    Employee(const std::string &,const std::string &,const std::string &,const Date &);
    virtual ~Employee() { }
    void setFirstName(const std::string &);
    std::string getFirstName() const;

    void setLastName(const std::string &);
    std::string getLastName() const;

    void setSoicalSecurityNumber(const std::string &);
    std::string getSoicalSecurityNumber() const;

    unsigned int getCurrentMonth() const;

    virtual double earning() const = 0;
    virtual void print() const;
private:
    Date birthdate;
    std::string firstName;
    std::string lastName;
    std::string soicalSecurityNumber;
};


#endif // EMPLOYEE_H_INCLUDED
