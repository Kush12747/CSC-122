#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "InputValidation.h"
using namespace std;

double Double_both_Bound(double lowBound, double upBound, string prompt) {
    double num;
   
    do {
        cout << endl << prompt;
        cin >> num;   
    } while (num <= lowBound || num >= upBound);
    return num;
}

long Long_Both_Bound(long lowBound, long upBound, string prompt) {
    long num;
    do {
        cout << endl << prompt;
        cin >> num;
    } while (num <= lowBound || num >= upBound);
    return num;
}

long Long_Low(long lowBound, string prompt) {
    long num;

    do {
        cout << endl << prompt;
        cin >> num;
    } while (num < lowBound);
    return num;
}

long Long_Up(long upBound, string prompt) {
    long num;

    do {       
        cout << endl << prompt;
        cin >> num;
    } while (num > upBound);
    return num;
}

long Num_Check_Long(vector<long> &numbers, string prompt) {
    long num;
    bool end = false;

    for (auto i : numbers) {//loop to print nums from vector
        cout << i << " ";
    }
    do {
        cout << prompt;
        cin >> num;

        for (vector<long>::size_type i = 0; i < numbers.size(); i++) {
            if (numbers[i] <= num) {
                end = true;
            }
        }
    } while (cin.fail() || !end);
    return num;
}

double Num_Check_Double(vector<double> &numbers, string prompt) {
    double num;
    bool end = false;

    for (auto i : numbers) {//loop to print nums from vector
        cout << i << " ";
    }
    do {
        cout << prompt;
        cin >> num;

        for (vector<double>::size_type i = 0; i < numbers.size(); i++) {
            if (numbers[i] <= num) {
                end = true;
            }
        }
    } while (cin.fail() || !end);
    return num;
}

char Char_low_bound(char lowBound, string prompt) {
    char value;
    do {
        cout << endl << prompt;
        cin >> value;
    } while (value < lowBound);
    return value;
}

char Char_Up_Bound(char UpBound, string prompt) {
    char value;
    do {
        cout << endl << prompt;
        cin >> value;
    } while (value > UpBound);
    return value;
}

double Double_LowBound(double lowBound, string prompt) {
    double num;
    
    do {
        cout << endl << prompt;
        cin >> num;
    } while (num < lowBound);
    return num;
}

double Double_UpBound(double upBound, string prompt) {
    double num;

    do {
        cout << endl << prompt;
        cin >> num;
    } while (num > upBound);
    return num;
}

int main() {
    vector<long> choiceLong;
    choiceLong.push_back(1);
    choiceLong.push_back(3);
    choiceLong.push_back(9);
    choiceLong.push_back(10);
    choiceLong.push_back(24);
    choiceLong.push_back(48);
    choiceLong.push_back(60);
    choiceLong.push_back(100);

    vector<double> choiceDouble;
    choiceDouble.push_back(3.3);
    choiceDouble.push_back(7.5);
    choiceDouble.push_back(65.1);
    choiceDouble.push_back(10.4);
    choiceDouble.push_back(19.8);
    choiceDouble.push_back(65.2);
    choiceDouble.push_back(55.5);
    choiceDouble.push_back(14.6);
    cout << Double_both_Bound(10.2, 125.8
        , "Enter a number between 10.2-125.8: ") << "\n";
    cout << Long_Both_Bound(100, 5000
        , "Enter a number between 100-5000: ") << "\n";
    cout << Double_UpBound(50.6, "Enter a number < 50.6: ") << "\n";
    cout << Double_LowBound(40.4, "Enter a number > 40.4: ") << "\n";
    cout << Num_Check_Long(choiceLong, "Choose from the list: ") << "\n";
    cout << Num_Check_Double(choiceDouble, "Choose from the list: ") << "\n";
    cout << Long_Low(70, "Enter a number > 70: ") << "\n";
    cout << Long_Up(2000, "Enter a number < 2000: ") << "\n";
    cout << Char_low_bound('D', "Enter a character less than D: ") << "\n";
    cout << Char_Up_Bound('k', "Enter a character greater than k: ") << "\n";
}
