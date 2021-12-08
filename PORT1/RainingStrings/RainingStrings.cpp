#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "RainingStrings.h"
using namespace std;

vector<string>::size_type bizz;
vector<string> businessName;

int main() {

    string bizzName;
    char ans = 'y';

    cout << "\t\tWelcome to the Business sorting program\n\n";

    do {
        cout << "\nPlease enter the name of a business: ";
        getline(cin, bizzName);
        businessName.push_back(bizzName);
        sortBusiness(businessName);
        names(businessName);
        displayList(businessName);
        cout << "\nWould you like to enter another one? (y/n) ";
        cin >> ans;
        while (ans == 'N' || ans == 'n') {
            cout << "\nThanks for using my sorting program!!\n";
            return 0;
        }
        cin.ignore();
    } while (ans == 'y' || ans == 'Y');
}
