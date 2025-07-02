#include <iostream>
#include <stdexcept>
#include "Polynomial.h"
#include <cmath>
using namespace std;
#define MAX_OPEARTIONS 4
using namespace std;


Polynomial::Polynomial(float cofficient,float exponent, char term)
{
    for(short &elemnt : container)
        elemnt = 0;
    for(float &item : exponen)
        item = 0;
    for(float &item : coffi)
        item = 0;
    for(int i = 0; i < size_of_array; i++)
    {
        coffi[ i ] = cofficient;
        exponen[ i ] = exponent;
        container[ i ] = cofficient * term ;
        for(int j = 0; j <= exponent; j++)
        {
            container[ i ] = term * exponent;
        }
    }

}

Polynomial::~Polynomial()
{
}

void Polynomial::setPoly(float coff, float exp,char te,int index)
{
    coffi[index] = coff;
    exponen[index] = exp;
    container[index] = coff * te;
    for(int i = 0;i <= exp;i++)
        container[index] = te * exp;
}

float Polynomial::getPoly(int ind) const
{
    return container[ind];
}

Polynomial Polynomial::operator+(const Polynomial &numbers)
{
    Polynomial result(*this);
    result += numbers;
    return numbers;
}

Polynomial Polynomial::operator+=(const Polynomial &numbers)
{
    return *this;
}
Polynomial Polynomial::operator-(const Polynomial &numbers)
{
    Polynomial result(*this);
    result -= numbers;
    return numbers;
}
Polynomial Polynomial::operator-=(const Polynomial &numbers)
{
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial &numbers)
{
    Polynomial result(*this);
    for(int i = 0;i < size_of_array;i++)
        if(result.container[i] == numbers.container[i]) // 4x8
        {
            result.exponen[i] += numbers.exponen[ i ];  //6  = 8+ 6 = 14
            result.coffi[i] *= numbers.coffi[i];        //8 = 4 * 8 = 32
            result.container[i] = numbers.container[i]; // 4x8 ^ 6*8
            return result;
        }
    return result * numbers;
}

Polynomial Polynomial::operator*=(const Polynomial &numbers)
{
    Polynomial result(*this);
    return result;
}

Polynomial Polynomial::operator=(const Polynomial &numbers)
{
    Polynomial result(*this);
    return result;
}

int main(void)
{

}
