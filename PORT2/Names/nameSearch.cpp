#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

string suffix(const int & count);//makes the oput nicer by nd,st,rd
void strcmp_ncase(const string & name, const string & temp, bool & found);
bool nameSearch(const string & name, ifstream & input);

int main(void)
{
    string name, fileName, list;
    ifstream input;

    cout << "\t\tWelcome to the Name Searching Program!!!" << endl;

    cout << "\nPlease enter the name of your names file: ";
    getline(cin, fileName);
    input.open(fileName);

    while (!input)//loop check input file
    {
        input.close();
        input.clear();
        cout << "\nI'm sorry, I could not open '" << fileName
            << "'. Please enter another name: ";
        getline(cin, fileName);
        input.open(fileName);
    }
    cout << "\nFile '" << fileName << "' opened successfuly!\n";

    cout << "\nWhat name would you like to find in this file? ";
    getline(cin, name);//get user input
    nameSearch(name, input);//call to function to search name
    input.close();
    input.clear();

    cout << "\nThank you for using the NSP!!" 
        << "\nEndeavor to have an amazing day!" << endl;
}

string suffix(const int & count)
{
    string chr = "th";//set default

    if (count / 100 % 10 != 1)
    {
        switch (count % 10)//if different POS then print others
        {
            case 1:
                chr = "st";
                break;
            case 2:
                chr = "nd";
                break;
            case 3:
                chr = "rd";
                break;
        }
    }
    return chr;
}
void strcmp_ncase(const string & name, const string & temp, bool & found) 
{//function for match string and partially of it
    size_t i = 0;

    while (i < name.length() && tolower(name[i]) == tolower(temp[i]))
    {
        i++;
    }
    found = i >= name.length();
}

bool nameSearch(const string & name, ifstream & input)
{
    string temp;
    bool finallyFound = false, found = false;
    int count = 0;

    input.peek();

    while (!input.eof())//search through file
    {
        count++;//line increment
        getline(input, temp);
        strcmp_ncase(name, temp, finallyFound);//call to function
        if (finallyFound)//for valid names
        {
            cout << "\n'" << name << "' is the " << count << suffix(count) <<
                " name in the file!" << endl;
            found = true;
        }
        input.peek();
    }
    if (!found)//for invalid names
    {
        cout << "\nInvalid Name!" << endl;
    }
    
    return found;
}
