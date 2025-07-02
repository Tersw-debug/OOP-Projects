#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <exception>
#include <stdexcept>
using namespace std;

class RomanHelper{
  public:
         string to_roman(unsigned int n) {
        const string thousands[] = {"", "M", "MM", "MMM", "MMMM"};
        const string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return thousands[n / 1000]
             + hundreds[(n % 1000) / 100]
             + tens[(n % 100) / 10]
             + ones[n % 10];
    }


    int from_roman( string rn){
      int result = 0;
      for(int i = 0;i < rn.length();i++)
      {
        char current = rn[i];
        char next = (i + 1 < rn.length()) ? rn[i + 1] : '\0';

        if (current == 'I' && next == 'V') {
            result += 4; i++;
        } else if (current == 'I' && next == 'X') {
            result += 9; i++;
        } else if (current == 'X' && next == 'L') {
            result += 40; i++;
        } else if (current == 'X' && next == 'C') {
            result += 90; i++;
        } else if (current == 'C' && next == 'D') {
            result += 400; i++;
        } else if (current == 'C' && next == 'M') {
            result += 900; i++;
        } else {
            switch (current) {
                case 'I': result += 1; break;
                case 'V': result += 5; break;
                case 'X': result += 10; break;
                case 'L': result += 50; break;
                case 'C': result += 100; break;
                case 'D': result += 500; break;
                case 'M': result += 1000; break;
            }
        }
      }
      return result;
    }
};


//IVLCMMMMM
int main()
{
    RomanHelper ob;
    cout << ob.to_roman(4954)<<endl;
    cout << ob.from_roman("MMMMMCLVI");


    return 0;
}
/*string *ptr;
      int i = 0;
      while(n > 0){
        int letter = n % 10;
        if(letter == 1 && i == 0)
        {
            result += "I";
        }
        if(letter == 4 && i == 0)
        {
            result += "IV";
        }
        if(letter == 5 && i == 0)
        {
            result += "V";
        }
        if(letter == 9 && i == 0)
        {
            result += "IX";
        }
        if(letter == 1 && i == 1)
        {
            result += "X";
        }
        if(letter == 4 && i == 1)
        {
            result += "XL";
        }
        if(letter == 5 && i == 1)
        {
            result += "L";
        }
        if(letter == 9 && i == 1)
        {
            result += "XC";
        }
        if(letter == 1 && i == 2)
        {
            result += "C";
        }
        if(letter == 4 && i == 2)
        {
            result += "CD";
        }
        if(letter == 5 && i == 2)
        {
            result += "D";
        }
        if(letter == 9 && i == 2)
        {
            result += "CM";
        }
        if(letter == 1 && i == 3)
        {
            result += "M";
        }
        if(letter == 2 && i == 3)
        {
            result += "MM";
        }
        if(letter == 3 && i == 3)
        {
            result += "MMM";
        }
        if(letter == 4 && i == 3)
        {
            result += "MMMM";
        }
        ++i;
        n = n / 10;
          reverse(result.begin(),result.end());*/
