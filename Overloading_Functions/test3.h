#ifndef TEST3_H
#define TEST3_H
#include <string>
#include <vector>
#include <array>
class IntgerSet
{
public:
    IntgerSet(std::vector<int>);
    IntgerSet(int [],int);
    void unionOfSets(int input[30] ,int input2[30]);
    void intersection(int input[30],int input2[30]);
    void insertElement(int input);
    void deletElement(int input);
    void print(int [100]);
    void isEqualto(int [] , int[]);
private:
    std::vector<bool> intgers;

};

#endif // TEST3_H_INCLUDED
