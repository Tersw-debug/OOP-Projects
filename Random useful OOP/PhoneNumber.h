#ifndef PHONENUMBER_H_INCLUDED
#define PHONENUMBER_H_INCLUDED
#include <iostream>
#include <string>



class PhoneNumber
{
friend std::ostream &operator<<(std::ostream &, const PhoneNumber &);
friend std::istream &operator>>(std::istream &, PhoneNumber &);
private:
    std::string areaCode;
    std::string exchange;
    std::string line;
};
/*
ostream &operator<<(ostream &output, const PhoneNumber &number)
{
    output << "(" << number.areaCode << ")" << number.exchange << "-" << number.line;
    return output;
}

istream &operator>>(istream &input, PhoneNumber &number)
{
    string test;
    for(int j = 0; j < 14;j++)
    {
        if(j == 5)
            input.ignore();
        else
            input >> test[j];
    }

    for(int i = 0;i < 14;i++)
    {

        if(test[0] == '(' && test[4] == ')' && test[9] == '-' && test[1] != '0' && test[1] != '1' && (test[2] == '1' || test[2] == '0'))
        {
            if(i >= 1 && i <= 3)
                number.areaCode += test[i];
            if(i >= 6 && i <= 8)
                number.exchange += test[i];
            if(i >= 10 && i <= 14)
                number.line += test[i];
        }
        else
        {
            input.clear(input.failbit);
        }
    }
    return input;
}
*/

#endif // PHONENUMBER_H_INCLUDED
