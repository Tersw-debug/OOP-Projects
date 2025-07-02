#include <iostream>
using namespace std;
#include "tic_tac_tio.h"
#include <stdexcept>

TicTacToe::TicTacToe(int d1,int d2,int typefirst,int typesecond)
    : type1( typefirst ) , type2( typesecond )
{
    for (int i = 0; i < 3;i++)
    {
        arr[0][i] = 0;
        arr[i][0] = 0;
        arr[1][i] = 0;
        arr[i][1] = 0;
        arr[2][i] = 0;
        arr[i][2] = 0;
    }
    arr[d1][d2] = type1;
}


void TicTacToe::firstPlayer(int d1,int d2,int type)
{
    bool result;
    if((arr[d1][d2] == 1) || (arr[d1][d2] == 2))
    {
        cout << "it's full though choose another place1" << endl;
    }
    else if(type1 != type2 || type != type2)
    {
        type1 = type;
        arr[d1][d2] = type1;
        for(int i = 0; i < 3; i++)
        {
            if ( arr[0][i] == type1 && arr[1][i] == type1 && arr[2][i] == type1)
            {
                result = true;
            }
            if ( arr[i][0] == type1 && arr[i][1] == type1 && arr[i][2] == type1)
            {
                result = true;
            }
        }
        if (arr[0][0] == type1 && arr[1][1] == type1 && arr[2][2]== type1)
        {
            result = true;
        }
        if(result == true)
        {
            cout << "you win player 1" << endl;
        }
        else {
            result = false;
            cout << "draw" << endl;
        }
    }

}

void TicTacToe::secondPlayer(int d1,int d2,int type)
{
    bool result;
    if((arr[d1][d2] == 1) || (arr[d1][d2] == 2))
    {
        cout << "it's full though choose another place2" << endl;
    }
    else if(type1 != type2 || type != type1)
    {
        type2 = type;
        arr[d1][d2] = type2;
        for(int i = 0; i < 3; i++)
        {
            if ( arr[0][i] == type2 && arr[1][i] == type2 && arr[2][i] == type2)
            {
                result = true;
            }
            if ( arr[i][0] == type2 && arr[i][1] == type2 && arr[i][2] == type2)
            {
                result = true;
            }
        }
        if (arr[0][0] == type2 && arr[1][1] == type2 && arr[2][2]== type2)
        {
            result = true;
        }
        if(result == true)
        {
            cout << "you win player 2" << endl;
        }
        else {
            result = false;
            cout << "draw" << endl;
        }
    }
}




int main(void)
{
    TicTacToe te(0,0,1,2);
    te.firstPlayer(0,1,1);
    te.secondPlayer(2,0,2);
    te.secondPlayer(2,1,2);

    te.secondPlayer(2,2,2);
}
