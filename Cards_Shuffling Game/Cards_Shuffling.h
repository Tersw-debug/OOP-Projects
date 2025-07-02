#ifndef CARDS_SHUFFLING_H
#define CARDS_SHUFFLING_H
#include <iostream>
#include <vector>
#include <string>
class Cards
{
public:
    explicit Cards(int,int);
    explicit Cards();
    static char suit_arr[];
    static char face_arr[];
    std::string toString();
    int getFace() ;
    friend class DeckOfCards;
private:
    int face;
    int suit;
    std::string cards[6];
};

class DeckOfCards
{

public:
    DeckOfCards();
    void setDeck(Cards& temp);
    void shuffle();
    int dealCard() const;
    bool moreCards() const;
    std::string dealer();
    std::string player(int,int);
    std::string player();
    std::string determineCards();
    int getResult() const;
private:
    int result;
    std::string deck[6];
    int currentCard;
};


#endif // CARDS_SHUFFLING_H_INCLUDED
