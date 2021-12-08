#include <iostream>
#include <string>
#include "Suit.h"
using namespace std;

int main()
{
    char chr;
    string cardSuit;//user input
    Cards card;//set the enum type
    cout << "\t\tWelcome to the Card Suit Entering Program!!!" << endl;

    do 
    {
       cout << "\nWhat is the suit of your card? ";
       cin >> cardSuit;
       card = searchCard(cardSuit);//search card function
       cardDisplay(card);//display message function
       cout << "\nAnother card? ";
       cin >> chr;
    } while (chr == 'y' || chr == 'Y');

    cout << "\nThank you for using the CESP!!"
         << "\nEndeavor to have a great day!" << endl;
}
