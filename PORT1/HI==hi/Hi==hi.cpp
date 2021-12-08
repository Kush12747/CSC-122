#include <iostream>
#include <string>
#include <cctype>
#include "strextra.h"
using namespace std;

int main() {
    bool skipSpace = false;
    bool skipPunct = false;
    string a, b, space, punct;
    short comp_res;

    cout << "Enter first string: ";
    getline(cin, a);
    cout << "Enter second string: ";
    getline(cin, b);
    cout << "\nAny Spaces Skipped: ";
    cin >> space;
    if (space[0] == 'y' || space[0] == 'Y') {
        skipSpace = true;//set bool to true
    }
    cout << "\nAny Punuation Skipped: ";
    cin >> punct;
    if (punct[0] == 'y' || punct[0] == 'Y') {
        skipPunct = true;//bool to true
    }
    //set comp_res to function to perform action
    //case switch to check the return val of function
    //and output a statement
    comp_res = string_comparison(a, b, skipSpace, skipPunct);
    switch (comp_res) {
    case -1:
        cout << "\nString a < String b" << endl;
        break;
    case 0:
        cout << "\nThey're both equal" << endl;
        break;
    case 1:
        cout << "\nstring a > string b" << endl;
        break;

    }
}
