#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <climits>
#include "Box.h"
using namespace std;

//sets message = message
void Box::setMessage() 
{ 
    this->message = message; 
}

//return the message
string Box::getMessage() 
    { return message; }

//allocate new memmory for the array
string* Box::getMessages() 
{
    string* temp = new string[15];
    for (size_t i = 0; i < 14; i++) 
    {
        temp[i] = messages[i];
    }
    return temp;
    delete[] temp;
}

//input for message
void Box::setMessages(ifstream& input) 
{
    for (size_t i = 0; i < 14; i++) 
    {
        getline(input, messages[i]);
    }
}

//functions for height border
void Box::setHeight(char symbols) 
{ 
    cout << symbols << message << symbols; 
}

void Box::setHeight(ofstream& output, char symbols) 
{
    output << symbols << message << symbols;
    output << endl;
}

void Box::setHeightFile(char symbols)
{
    for (size_t i = 0; i < 14; i++) 
    {
        cout << symbols << messages[i] << setw(messageLength() - messages[i].length() + 1)
             << symbols << endl;
    }
}

void Box::setHeightFile(ofstream& output, char symbols) 
{
    size_t size = messageLength();
    for (size_t i = 0; i < 14; i++) 
    {
        cout << symbols << messages[i] << setw(size - messages[i].length() + 1)
             << symbols << endl;
    }
}

//functions for width border
void Box::setWidth(char symbols)
{
    for (size_t i = 0; i < message.length() + 2; i++) 
    {
        cout << symbols;
    }
    cout << "\n";
}

void Box::setWidth(ofstream& output, char symbols) 
{
    for (size_t i = 0; i < messageLength() + 2; i++) 
    {
        output << symbols;
    }
    output << endl;
}

void Box::setWidthFile(char symbols) 
{
    for (size_t i = 0; i < messageLength() + 2; i++) 
    {
        cout << symbols;
    }
    cout << endl;
}

void Box::setWidthFile(ofstream& output, char symbols) 
{
    for (size_t i = 0; i < messageLength() + 2; ++i) 
    {
        output << symbols;
    }
    output << endl;
}

//sets the different borders for output
void Box::setNewBorder(int options) 
{
    if (options == 1) {
        singleLine();

    }
    else if (options == 2) {
        doubleLine();

    }
    else if (options == 3) {
        shaded();

    }
    else
        singleLine();
}

ostream& operator<<(ostream& output, const Box& a) 
{
    output << a.message;
    return output;
}

istream& operator>>(istream& input, Box& a) 
{
    cin.ignore(INT_MAX, '\n');
    getline(input, a.message);
    return input;
}

size_t Box::messageLength() 
{
    size_t biggest = messages[0].length();
    for (size_t i = 0; i < 20; i++) 
    {
        if (messages[i].length() > biggest) 
        {
            if (messages[i] == "")
                break;
            biggest = messages[i].length();
        }
    }
    return biggest;
}

void Box::singleLine() {
    cout << "-----------------";
    cout << "|" << message << "|";
    cout << "-----------------";
}

void Box::doubleLine() {
    cout << "=================";
    cout << "||" << message << "||";
    cout << "=================";
}

void Box::shaded() {
    cout << "\n###################";
    cout << "\n=================";
    cout << "\n||" << message << "\t||";
    cout << "\n=================";
    cout << "\n###################";
}

int main() 
{
    Box a;
    ifstream input;
    ofstream output;
    string fileChoice, message, BoxType, 
           BoxFrame, file, outFile, printResults;
    char symbols;
    size_t option{};

    cout << "\t\tWelcome the box program!!!" << endl;

    cout << "\nDo you want to choose frame type?: ";
    cin >> BoxFrame;

    if (BoxFrame == "Y" || BoxFrame == "y") 
    {
        cout << "-Frame types-:\n"
             << "1. Single line\n"
             << "2. Double line\n"
             << "3. Shaded\n"
             << "Pick one: ";
        cin >> BoxType;
        cout << "\nEnter your message: ";
        cin.ignore(INT_MAX, '\n');
        cin >> message;

        if (BoxType == "S" || BoxType == "s") 
        {
            a.setNewBorder(1);
        }
        else if (BoxType == "D" || BoxType == "d") 
        {
            a.setNewBorder(2);
        }
        else if (BoxType == "SH" || BoxType == "sh") 
        {
            a.setNewBorder(3);
        }
        else 
        {
            cout << "\nSilly you, Error";
        }
    }

    cout << "\nEnter any symbol for the use of border: ";
    cin >> symbols;
    cout << "\nWant to obtain a message from a file: ";
    cin >> fileChoice;

    if (fileChoice == "Y" || fileChoice == "y") 
    {
        cout << "\nEnter the name of the file:   ";
        cin >> file;
        input.open(file.c_str(), ios::in);
        a.setMessages(input);
    }
    else 
    {
        cout << "\nEnter your message: ";
        cin >> a;
    }

    cout << "\nWant to print the result in a file?: ";
    cin >> printResults;

    if (printResults == "Y" || printResults == "y")
    {
        cout << "\nEnter the name of the file: ";
        cin >> outFile;
        output.open(outFile.c_str(), ios::out);
    }
    cout << endl << endl;
    
     if (option != 1) {
        a.setWidth(symbols);
        a.setHeight(symbols);
        cout << "\n";
        a.setWidth(symbols);
    }
    else 
    {
        a.setWidthFile(symbols);
        a.setHeightFile(symbols);
        cout << "\n";
        a.setWidthFile(symbols);
    }

    //closing the files
    output.close();
    output.clear();
    input.close();
    input.clear();
}
