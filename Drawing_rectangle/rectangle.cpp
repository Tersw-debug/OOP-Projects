#include <iostream>
#include <string>
using namespace std;
#include "rectangle_header.h"
#include <stdexcept>
#include <iomanip>
#include <cmath>

Rectangle::Rectangle(float firstsideX,float firstsideY, float secondsideX,float secondsideY, float thirdsideX,float thirdsideY
                     , float fourthsideX,float fourthsideY)
{
    setRectangle(firstsideX, firstsideY, secondsideX,secondsideY,thirdsideX, thirdsideY, fourthsideX,
                  fourthsideY);

    setWidth(firstsideY,secondsideY);
    setLength(firstsideX, fourthsideX);

}

void Rectangle::setRectangle(float firstsideX,float firstsideY,float secondsideX,float secondsideY,float thirdsideX,
                             float thirdsideY,float fourthsideX,
                            float fourthsideY)
{
    if (firstsideX == secondsideX && firstsideY == fourthsideY && thirdsideX == fourthsideX && thirdsideY == secondsideY &&
         (fourthsideX - firstsideX) != (secondsideY - firstsideY) && (fourthsideX - firstsideY) > (secondsideY - firstsideY))
    {
        if (firstsideX >= 0.0 && firstsideX < 20.0 && secondsideX >= 0.0 && secondsideX < 20.0 && thirdsideX >= 0.0 && thirdsideX <20.0
             && fourthsideX >= 0.0 && fourthsideX < 20.0 && firstsideY >= 0.0 && firstsideY < 20.0 && secondsideY >= 0.0 && secondsideY < 20.0 && thirdsideY >= 0.0 && thirdsideY <20.0
             && fourthsideY >= 0.0 && fourthsideY < 20.0 )
        {
            cout << "it's rectangle" << endl;
            fx = firstsideX;
            fy = firstsideY;
            sx = secondsideX;
            sy = secondsideY;
            tx = thirdsideX;
            ty = thirdsideY;
            fourx = fourthsideX;
            foury = fourthsideY;
        }
    }
    else if ((fourthsideX - firstsideX) == (thirdsideX - secondsideX) && (secondsideY - firstsideY) == (thirdsideY - fourthsideY))
    {
        cout << "it's square" << endl;
        fx = firstsideX;
        fy = firstsideY;
        sx = secondsideX;
        sy = secondsideY;
        tx = thirdsideX;
        ty = thirdsideY;
        fourx = fourthsideX;
        foury = fourthsideY;
    }
    else
        throw invalid_argument("Check the rules of the program\n");
}

void Rectangle::setWidth(float firstsideY,float secondsideY)
{
    width = secondsideY - firstsideY;
}


void Rectangle::setLength(float firstsideX,float fourthsideX)
{
    length = fourthsideX - firstsideX;
}

void Rectangle::area()
{
    cout << "The area: " <<length * width << endl;
}

void Rectangle::primeter()
{
    int result = length * length + width * width;
    cout << "The primeter: " << sqrt(result) << endl;
}

void Rectangle::setFillContent(string content)
{
    setFillC = content;
}

void Rectangle::setFillPrimeter(string perimeter)
{
    setFillP = perimeter;
}



void Rectangle::draw()
{
            for(float i = 0; i < 25; i++){
            if (i == 0|| i == 24)
            {
                for(int j = 0; j < 25;j++)
                {
                    cout << "*";
                }
            }
            else{
                    if (i >= fy && i <= sy){
                        for( float j = 0.0; j < (25.0 - (fourx - fx));j++)
                        {
                            if (i != 1){

                                cout << " ";
                            }
                            if(j == (25.0 - (fourx - fx)-1) )
                            {
                                cout << "*" <<endl;
                            }
                        }
                    }
                    else {
                        for( float j = 0.0; j < (26.0);j++)
                        {
                            if (i != 1){

                                cout << " ";
                            }
                            if(j == (26.0 -1))
                            {
                                cout << "*" <<endl;
                            }
                        }
                    }
            }
            cout << "*";


        if(i < fy)
        {
            for(float g = 0; g < fy ;g++)
            {
                cout << " " << endl;
            }
        }
        if(i != 24){
            for (int k = 0.0; k <= (fourx); k++)
            {
                if( k < fx && i != 0 && i != 25)
                {
                    cout << " " ;
                }
                if((k == fx && i > fy && i <sy) || (k == fourx && i >fy  && i < sy) || (i == fy) || (i == sy))
                {
                    cout << setFillP;
                }
                else{
                    if (i <= (sy - fy) &&i != 0 && k >=fx){
                        cout << setFillC;
                    }
                }
            }
        }

    }
}

int main(void)
{
    Rectangle re(2.0,1.0,2.0,8.0,10.0,8.0,10.0,1.0);
    re.setFillContent("g");
    re.setFillPrimeter("q");
    re.draw();
}
