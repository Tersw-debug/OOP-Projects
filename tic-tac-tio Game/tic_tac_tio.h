#ifndef TIC_TAC_TIO_H_INCLUDED
#define TIC_TAC_TIO_H_INCLUDED
#include <iostream>
class TicTacToe
{
public:
    TicTacToe(int = 0,int = 0,int = 0, int = 0);
    void firstPlayer(int,int,int);
    void secondPlayer(int,int,int);
private:
    int arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int type1;
    int type2;
};



#endif // TIC_TAC_TIO_H_INCLUDED
