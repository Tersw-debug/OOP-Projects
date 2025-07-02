#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <array>
#include <iostream>

class Date
{
    friend std::ostream &operator<<(std::ostream &, const Date &);
public:
    Date(int m = 1,int d = 1,int y = 2000);
    void setDate(int,int,int);
    Date &operator++();
    Date operator++( int );
    Date &operator+=(unsigned int);
    unsigned int getMonth() const;
    static bool leapYear(int);
    bool endOfMonth(int) const;
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    static const std::array<unsigned int, 13> days;
    void helpIncrement();
};


#endif // DATE_H_INCLUDED
