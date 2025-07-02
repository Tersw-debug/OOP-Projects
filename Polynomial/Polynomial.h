#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <iostream>
#include <array>
#include <string>
class Polynomial
{

public:
    static const int size_of_array = 30;
    Polynomial(float,float, char);
    ~Polynomial();
    void setPoly(float,float,char,int);
    float getPoly(int) const;
    Polynomial operator+(const Polynomial &);
    Polynomial operator-(const Polynomial &);
    Polynomial operator*(const Polynomial &);
    Polynomial operator=(const Polynomial &);
    Polynomial operator+=(const Polynomial &);

    Polynomial operator-=(const Polynomial &);
    Polynomial operator*=(const Polynomial &);
private:
    std::array<short, size_of_array>container;
    std::array<float, size_of_array>coffi;
    std::array<float, size_of_array>exponen;
    char ter;
    int index;
};
#endif // HEADER_H_INCLUDED
