#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double index_count(string message);//calculates the total of index
short sentences(string symbol);//checks number of senteces
bool punctation(char v);//punctitation caller
short words(string message);//checks number of words
bool vowel(char v);//vowel check
short syllables(string message);//checks for syllables

int main() {
    ifstream files;
    string message, file, temp, response;

    cout << "Got a File (y/n) ";
    getline(cin, response);

    switch (response[0]) { 
    case 'N': case 'n':
        cout << "Enter a message: ";
        getline(cin, message);
        break;
    case 'y': case 'Y':
        cout << "\nEnter a file: ";
        cin >> file;
        files.open(file);
        if (files.fail()) {
            cout << "FILE INVALID" << endl;
        }
        else {
            files.peek();
            cout << "File Found: " << file << endl;
            while (!files.eof()) {
                getline(files, temp);
                message += temp;
                files.peek();
            }
            files.close();
            files.clear();
        }
        break;
      default:
        cout << "\nAnswer Invalid" << endl;
        break;
    }
    
    //output design below
    cout << "\nNumber of words are " << words(message);
    cout << "\nNumber of syllables are " << syllables(message);
    cout << "\nNumber of senteces are " << sentences(message);
    cout << "\nTotal index is " << index_count(message) << endl;
}

double index_count(string message) {//function for the calculations
    double index = 206.835 - 84.6 * syllables(message) / words(message)
        - 1.015 * words(message) / sentences(message);
    return index;
}

short sentences(string symbol) { //counts the number of senteces by symbols
    short sentence = 0;
    short i = 0;
    while (symbol[i] != '\0') {
        if (symbol[i] == '.' || symbol[i] == '!' || symbol[i] == ':' ||
            symbol[i] == ';' || symbol[i] == '?') {
            ++sentence;
        }
        ++i;
    }
    return sentence;
}

bool punctation(char v) { //checks for puncctation
    return v == '!' || v == ',' || v == ';' || v == '?' ||
        v == ',' || v == '.' || v == ' ';
}

short words(string message) { //counts the number of words entered
    short word = 0;
    short i = 0;
    char less = '<', greater = '>';

    while (message[i] != '\0') {
        if (message[i] == less && i > 0 && punctation(message[i - 1])) {
            --word;
        }
        if (message[i] == greater) {
            ++i;
        }
        if (message[i] == less) {
            do {
                ++i;
            } while (message[i] != greater && message[i] != '\0');
        }
        if (punctation(message[i]) && !punctation(message[i + 1])) {
            word++;
        }
        ++i;
    }
    if (message[0] == '\0') {
        word = 0;
    }
    return word;
}

bool vowel(char v) { //function for vowels
    return v == 'e' || v == 'i' || v == 'a' || v == 'u' || v == 'o';
}

short syllables(string message) {
    short syllable = 0;
    short i = 0;

    while (message[i] != '\0') {
        if (vowel(message[i]) && !vowel(message[i + 1])) {
            ++syllable;
        }
        ++i;
    }
    return syllable;
}
