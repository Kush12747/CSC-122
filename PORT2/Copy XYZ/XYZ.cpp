#include <fstream>
#include <iostream>
#include <cstring>
#include <climits>
#include <cctype>
#include <string>
#include "XYZ.h"
using namespace std;

int main() {
    ifstream data_file;
    ofstream outfiles;
    Data data;
    string fileName1, fileName2;

    cout << "\t\tWelcome to the People Copying Data Program!!";
    cout << "\n\nPlease enter the name of your data file: ";
    getline(cin, fileName1);
    data_file.open(fileName1);

    while (!data_file) {//loop check input file
        data_file.close();
        data_file.clear();
        cout << "\nI'm sorry, I could not open '" << fileName1
            << "'. Please enter another name: ";
        getline(cin, fileName1);
    }
    cout << "\nFile '" << fileName1 << "' opened successfully!\n";

    cout << "\nPlease enter the name of your data file: ";
    getline(cin, fileName2);
    outfiles.open(fileName2);

    while (!outfiles) {//loop check for output file
        outfiles.close();
        outfiles.clear();
        cout << "\nI'm sorry, I could not open '" << fileName2
            << "'. Please enter another name: ";
        getline(cin, fileName2); 
    }
    cout << "\nFile '" << fileName2 << "' opened successfully!\n";

    cout << "\nCopying data from '" << fileName1 << "' to '" 
        << fileName2 << "'...\n";
    data_file.peek();
    while (!data_file.eof()) {
        data.read(data_file);
        data.write(outfiles);
        data_file.peek();
    }
    cout << "\nDone copying data!\n" << "\nThank you for using the PCP!\n"
        << "\nEndeavour to have a tremendous day" << endl;
    return 0;
}

Data::Data() : idNum(000000), gpa(0.0), grade('A') { name[0] = '\0'; }

void comment_Line(char pound, istream& input) 
{//function for any # or \n is removed 
    input >> ws;
    while (input.peek() == pound || input.peek() == '\n') {
        input.ignore(INT_MAX, '\n');
        input >> ws;
    }
    return;
}

void Data::read(ifstream& input) {
    comment_Line('#', input);
    input.getline(name, length);
    char *check = strchr(name, '#');
    if (check != NULL) {//if comment then set the null chr.
        *check = '\0';
    }
    comment_Line('#', input);
    input >> idNum;
    comment_Line('#', input);
    input >> gpa;
    comment_Line('#', input);
    input >> grade;
    comment_Line('#', input);
}

void Data::write(ofstream& output) {
    output << name << endl;
    output << idNum << endl;
    output << gpa << endl;
    output << grade << endl << endl;
}
