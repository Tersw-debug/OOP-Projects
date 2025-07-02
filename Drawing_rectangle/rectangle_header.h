#ifndef HEADER2_H
#define HEADER2_H
#include <string>

class Rectangle
{
public:
    explicit Rectangle(float = 0.0, float = 0.0,float = 0.0,float = 0.0,float = 0.0,float = 0.0,float = 0.0,float = 0.0);
    void area();
    void primeter();
    void setRectangle(float,float,float,float,float,float,float,float);
    void setWidth(float,float);
    void setLength(float,float);
    float getWidth() const;
    float getLength() const;
    void draw();
    void setFillPrimeter(std::string);
    void setFillContent(std::string);
private:
    float fx;
    float fy;
    float sx;
    float sy;
    float tx;
    float ty;
    float fourx;
    float foury;
    float width;
    float length;
    std::string setFillP;
    std::string setFillC;
};



#endif
