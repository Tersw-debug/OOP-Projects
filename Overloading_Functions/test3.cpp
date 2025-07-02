#include <iostream>
using namespace std;
#include "test3.h"
#include <array>
#include <stdexcept>
#include <vector>
#include <bits/stdc++.h>
IntgerSet::IntgerSet(vector<int>sets)
{
    intgers.resize(101);
    for (int i = 0; i < 101;i++)
    {
        intgers.at(i) = false;
    }
    for (int h = 0; h < sets.size(); h++)
    {
        if(sets.at(h) <= 100)
        {
            intgers.at(h) = true;
        }
    }
}

IntgerSet::IntgerSet(int input[],int si)
{
    for(int i = 0; i < si;i++)
    {
        if(input[i] <= 100)
        {
            intgers.at(i) = true;
        }
        else{
            intgers.at(i) = false;
        }
    }
}


void IntgerSet::isEqualto(int firstset[],int secondset[])
{
    if(firstset == secondset)
    {
        cout << "true" << endl;
    }
    else{
        cout << "false" <<endl;
    }
}
void IntgerSet::unionOfSets(int input[30] , int input2[30])
{
    int temp = 0;
    int size_input1 = sizeof(input) / sizeof(input[0]);
    int size_input2 = sizeof(input2) / sizeof(input2[0]);
    vector<bool> result(size_input1 + size_input2);
    for(int i = 0; i < size_input1;i++)
    {
        for(int j = i + 1; j < size_input1;i++)
        {
            if(input[i] > input[j])   // 1 2 3 5 4 6
            {
                int temp4 = input[i];
                input[i] = input[j];
                input[j] = temp4;
            }
        }
    }

    for(int i = 0; i < size_input2 ;i++)
    {
        for(int j = i + 1; j < size_input2;i++)
        {
            if(input2[i] > input2[j])   // 1 2 3 5 4 6
            {
                int temp4 = input2[i];
                input2[i] = input2[j];
                input2[j] = temp4;
            }
        }
    }


    for(int i = 0; i < result.size();i++)
    {
        if(input[i] == input2[i] || input[i] != input2[i])
        {
            result.at(temp) = true;
            cout << "testing true" << endl;
            temp++;
        }
    }

}

void IntgerSet::intersection(int input[30],int input2[30])
{
       int temp = 0;
    int size_input1 = sizeof(input) / sizeof(input[0]);
    int size_input2 = sizeof(input2) / sizeof(input2[0]);
    vector<bool> result(size_input1 + size_input2);
    for(int i = 0; i < size_input1;i++)
    {
        for(int j = i + 1; j < size_input1;i++)
        {
            if(input[i] > input[j])   // 1 2 3 5 4 6
            {
                int temp4 = input[i];
                input[i] = input[j];
                input[j] = temp4;
            }
        }
    }

    for(int i = 0; i < size_input2 ;i++)
    {
        for(int j = i + 1; j < size_input2;i++)
        {
            if(input2[i] > input2[j])   // 1 2 3 5 4 6
            {
                int temp4 = input2[i];
                input2[i] = input2[j];
                input2[j] = temp4;
            }
        }
    }


    for(int i = 0; i < result.size();i++)
    {
        if(input[i] == input2[i] || input[i] != input2[i])
        {
            result.at(temp) = true;
            cout << "testing true" << endl;
            temp++;
        }
    }

}

void IntgerSet::insertElement(int input)
{
    if( input <= 100)
    {
        intgers.at(input) = true;
    }
    else{
        cout << "please there's an error" << endl;
    }
}


void IntgerSet::deletElement(int input)
{
    if( input <= 100)
    {
        intgers.at(input) = false;
    }
    else{
        cout << "please there's an error" << endl;
    }
}


void IntgerSet::print(int input[])
{
    int size_of_input = sizeof(input) / sizeof(input[0]);
    for(int i = 0; i < size_of_input;i++)
    {
        if(intgers.at(input[i]) == true)
        {
            cout << input[i] << " ";
        }

        else
        {
            cout << "---" << " ";
        }
    }
}
int main()
{
    IntgerSet in({0,1,2,3});
    int test[5] = {1,2,3,4};
    int test2[5] = {4,3,2,1};
    in.unionOfSets( test , test2);
}
