#ifndef RAINING_STRINGS_H_INC
#define RAINING_STRINGS_H_INC
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sortBusiness(vector<string>& bizz) {
    string n;
    for (unsigned int i = 1; i < bizz.size(); i++) {
        for (unsigned int j = 0; j < bizz.size() - 1; j++) {
            if (bizz[j] > bizz[i]) {
                n = bizz[j];
                bizz[j] = bizz[i];
                bizz[i] = n;
            }
        }
    }
}


void displayList(vector<string>& bizz) {
    for (unsigned int i = 0; i != bizz.size(); i++) {
        cout << bizz[i] << "\n";
    }
}

void names(vector<string>& names) {
    if (names.size() == 1) {
        cout << "\nYour business is: \n\n";
    }
    else {
        cout << "\nYour businesses are: \n\n";
    }
}
#endif
