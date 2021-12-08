#ifndef CARDS_H_INC
#define CARDS_H_INC
#include <iostream>
using namespace std;

//types of cards
enum Cards
{
    hearts,
    clubs,
    diamonds,
    spades,
    other
};


//function to search for type of cards
Cards searchCard(string cardSuit)
{
    //able to store the substr card
    Cards newOther = other;

    //initalize the types of cards to strings by letters
    string s = "spades",
           h = "hearts",
           d = "diamonds",
           c = "clubs";

    size_t strLen = cardSuit.length(); //finds the length of string

    //convert string to lowercase to compare the strings
    for (size_t i = 0; i < strLen; i++)
    {
        cardSuit[i] = tolower(cardSuit[i]);
    }

    //now to the given string with substr
    //and set them to newOther from other
    if (cardSuit == h.substr(0, strLen)) 
    {
        newOther = hearts;
    }
    else if (cardSuit == c.substr(0, strLen)) 
    {
        newOther = clubs;
    }
    else if (cardSuit == d.substr(0, strLen)) 
    {
        newOther = diamonds;
    }
    else if (cardSuit == s.substr(0, strLen)) 
    {
        newOther = spades;
    }
    return newOther;
}

//function to display the message for the playing cards entered
void cardDisplay(Cards newOther)
{
    switch (newOther)
    {
    case diamonds:
        cout << "Ooo...diamonds. Don't cut my montier with those!" << endl;
        break;
    case hearts:
        cout << "You have a heart! Dont't wear it on your sleeve...!" << endl;
        break;
    case clubs:
        cout << "Ah, a club! Don't beat me up!!" << endl;
        break;
    case spades:
        cout << "So, you have a spade! Dig me a hole out back, won't you?" 
             << endl;
        break;
    case other:
        cout << "I'm sorry, I don't recongnize that suit...Please try again." 
             << endl;
        break;
    }
}
#endif
