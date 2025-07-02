#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include<cstdlib>
#include<random>
#include "Cards_Shuffling.h"
using namespace std;
char Cards::face_arr[7];
char Cards::suit_arr[7];
Cards::Cards()
{
}

Cards::Cards(int sui, int fac)
    : suit( sui ), face(fac)
{
    if(suit <= 20 && face <= 20)
    {
        for(int i = 0; i < 6;i++)
        {
            face_arr[i] = face;
            suit_arr[i] = suit;
        }
    }
    else
    {
        throw invalid_argument("Input value must be 1 - 20");
    }
}


string Cards::toString()
{


    for (int i = 0; i < 6 ; i++)
    {
        return to_string(face_arr[i]) + "of" + to_string(suit_arr[i]);
        cards[i] = to_string(face_arr[i]) + "of" + to_string(suit_arr[i]);
    }

}
int Cards::getFace()
{
    for(int i = 0;i < 6;i++)
    {
        return face_arr[i];
    }
}
DeckOfCards::DeckOfCards()
{
}
void DeckOfCards::setDeck(Cards& temp)
{

    for(int i = 0;i < 6;i++)
    {
        deck[i] = temp.toString();
        result += temp.getFace();
    }
}
int DeckOfCards::getResult() const
{
    return result;
}
void DeckOfCards::shuffle()
{
    string temp;
    srand(10);
    for (int i = 0;i < 6; i++)
    {
        temp = deck[(rand() / 10)% i];
        deck[i] = temp;
    }
}

int DeckOfCards::dealCard() const
{
    return currentCard;
}

bool DeckOfCards::moreCards() const
{
    if (currentCard == 5)
        return false;
    else
        return true;
}

string DeckOfCards::determineCards()
{
    string result_det;
    if (getResult() > 21)
    {
        result_det = "you lost";
        return result_det;
    }
    else
    {
        for(int i = 0;i < 6;i++)
        {
            if (deck[i] == deck[0] && deck[i] == deck[1] && deck[i] == deck[2] && deck[i] == deck[3] && deck[i] == deck[4])
            {
                result_det = "it's flush";
                return  "it's flush";
            }
            else{
                    if (deck[i] == deck[0] && deck[i] == deck[1])
                    {
                        result_det = "it's two pair";
                        return result_det;
                    }
                    else{
                        if (deck[i] == deck[0] && deck[i] == deck[1] && deck[i] == deck[2])
                        {
                            result_det = "it's jack";
                            return  result_det;
                        }
                        else{
                             if (deck[i] == deck[0] && deck[i] == deck[1] && deck[i] == deck[2] && deck[i] == deck[3])
                             {
                                result_det = "it's ace" ;
                                return result_det;
                             }
                             else{
                                  if(deck[i] == deck[0])
                                  {
                                        result_det = "it's pair";
                                        return result_det;
                                  }
                             }
                        }
                }
            }
        }
    }
}
string DeckOfCards::dealer()
{
    Cards cr(1,1);
    Cards cr1(1,1);
    Cards cr2(1,1);
    Cards cr3(1,1);
    Cards cr4(1,1);
    Cards start2;
    DeckOfCards de;
    de.setDeck(start2);


    if((de.determineCards() == "it's flush" || result == 21 ) || (de.determineCards() == "it's flush" && result == 21) || (de.determineCards() == "it's ace" || result == 21)
        || (de.determineCards() == "it's pair" || result == 21) || (de.determineCards() == "it's jack" || result == 21) || (de.determineCards() == "it's two pair" || result == 21))
    {
        return de.determineCards();

    }

    else{
        int temp[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        int size_of_temp = sizeof(temp) / sizeof(temp[0]);
        int min = 0;
        int max = 20;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(min, max);

        for(int i = 0;i < 6;i++)
        {
            deck[i] = to_string(temp[distrib(gen)]);
            result += temp[distrib(gen)];  //5
            if ((de.determineCards() == "it's flush" || result == 21) || (de.determineCards() == "it's flush" && result == 21) || (de.determineCards() == "it's two pair" && result == 21) ||
                (de.determineCards() ==   "it's pair" && result == 21) || (de.determineCards() == "it's ace" || result == 21) || (de.determineCards() == "it's jack" && result == 21))
            {
                return de.determineCards();
            }
        }

    }



}
string DeckOfCards::player()
{
     Cards start;
    Cards cr5(1,1);
    Cards cr6(1,1);
    Cards cr7(1,1);
    Cards cr8(1,1);
    Cards cr9(1,1);
    DeckOfCards det;
    det.setDeck(start);




    if((det.determineCards() == "it's flush" || result == 21 ) || (det.determineCards() == "it's flush" || result == 21) || (det.determineCards() == "it's ace" || result == 21)
        || (det.determineCards() == "it's pair" || result == 21) || (det.determineCards() == "it's jack" || result == 21) || (det.determineCards() == "it's two pair" || result == 21))
    {
        return det.determineCards();
    }

    else{
        int temp[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        int size_of_temp = sizeof(temp) / sizeof(temp[0]);
        int min = 0;
        int max = 20;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(min, max);

        for(int i = 0;i < 6;i++)
        {
            deck[i] = to_string(temp[distrib(gen)]);
            result += temp[distrib(gen)];
            if ((det.determineCards() == "it's flush" || result == 21) || (det.determineCards() == "it's flush" && result == 21) || (det.determineCards() == "it's two pair" && result == 21) ||
                (det.determineCards() ==   "it's pair" && result == 21) || (det.determineCards() == "it's ace" && result == 21) || (det.determineCards() == "it's jack" && result == 21))
            {
                return det.determineCards();
            }
        }

    }


}
string DeckOfCards::player(int hg1,int hg2)
{
    Cards start;
    Cards cr5(1,1);
    Cards cr6(1,1);
    Cards cr7(1,1);
    Cards cr8(1,1);
    Cards cr9(1,1);
    DeckOfCards det;
    det.setDeck(start);




    if((det.determineCards() == "it's flush" || result == 21 ) || (det.determineCards() == "it's flush" && result == 21) || (det.determineCards() == "it's ace" || result == 21)
        || (det.determineCards() == "it's pair" && result == 21) || (det.determineCards() == "it's jack" && result == 21) || (det.determineCards() == "it's two pair" && result == 21))
    {
        return det.determineCards();
    }

    else{
        int temp[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        int size_of_temp = sizeof(temp) / sizeof(temp[0]);
        int min = 0;
        int max = 20;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(min, max);

        for(int i = 0;i < hg1;i++)
        {
            deck[hg2++] = to_string(temp[distrib(gen)]);
            result += temp[distrib(gen)];
            if ((det.determineCards() == "it's flush" || result == 21) || (det.determineCards() == "it's flush" && result == 21) || (det.determineCards() == "it's two pair" && result == 21) ||
                (det.determineCards() ==   "it's pair" && result == 21) || (det.determineCards() == "it's ace" && result == 21) || (det.determineCards() == "it's jack" && result == 21))
            {
                return det.determineCards();
            }
        }

    }


}

int main(void)
{
    DeckOfCards ter;
    DeckOfCards yer;
    if ((ter.dealer() == "it's flush" && yer.player() != "it's flush")|| (yer.player() == "it's two pair" && ter.dealer() != "it's two pair" )|| (ter.dealer() == "it's jack" && yer.player()  != "it's jack")
        ||  (ter.dealer() == "it's ace" && yer.player() != "it's ace" )|| (ter.dealer() ==  "it's pair" && yer.player() != "it's pair"))
    {
        cout  << "you win player1" << endl;
    }

    else{
        if(ter.dealer() == yer.player())
        {
            cout << "draw"  << endl;
        }
        else{
            cout  << "you win player2" << endl;
        }
    }
}
