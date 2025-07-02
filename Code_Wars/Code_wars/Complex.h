#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>

class Peter
{
    friend std::ostream &operator<<(std::ostream &, const Peter &);
    friend std::istream &operator>>(std::istream &, Peter &);
private:
    int real;
    int rety;
};
/*

ostream &operator<<(ostream &output, const Peter &num)
{
    output << num.real << "  "<< showpos << num.rety << "i";
    return output;
}

istream &operator>>(istream &input, Peter &num)
{
    string temp;int converting = 0, sign = 1;num.real = 0; num.rety = 0;
    input >> temp;

    for(char c:temp)
    {
        if(c >= '0' && c <= '9')
        {
            converting = converting * 10 + (c - '0');
        }
        else if(c == '-')
        {
            sign = -1;
        }
        else if((c == '+' && num.rety == 0) || (sign == -1 && num.rety == 0))
        {
            num.real = converting * sign;
            converting = 0;
            sign = 1;
        }
        else if(c == 'i')
        {
            num.rety = converting * sign;
        }
        else
            input.clear(input.failbit);
    }
    return input;
}
*/
#endif // COMPLEX_H_INCLUDED
