#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
#include <string>

class Point
{
    friend std::ostream &operator<<(std::ostream &,const Point &);
    friend std::istream &operator>>(std::istream &, Point &);
private:
    int xCoordinate;
    int yCoordinate;
};
/*
ostream &operator<<(ostream &output, const Point &p)
{
    output << "x: " << p.xCoordinate << "y: " << p.yCoordinate;
    return output;
}

istream &operator>>(istream &input, Point &p)
{
   int converting = 0, sign = 1;string temp = "";
   input >> temp;
    for(char c:temp)
    {
        if(c >= '0' && c <='9')
        {
               converting = converting * 10 + (c - '0');
        }
        else if(c == '-')
        {
            sign = -1;
        }
        else if(c == ',')
        {
            p.xCoordinate = converting * sign;
            converting = 0;
            sign = 1;
        }
        else
            input.clear(input.failbit);
    }
    p.yCoordinate = converting * sign;
    return input;
}
*/

#endif // POINT_H_INCLUDED
