#ifndef BOX_H_INC
#define BOX_H_INC
#include <iostream>
using namespace std;


class Box 
{
    string message;
    string messages[15];

public:
    //functions that sets messages from input
    //getters and setters
    void setMessage();
    string getMessage();
    string* getMessages();
    void setMessages(ifstream& input);

    //sets height border functions
    void setHeight(char symbols);
    void setHeight(ofstream& output, char symbols);
    void setHeightFile(char symbols);
    void setHeightFile(ofstream& output, char symbols);

    //sets the width borders functions
    void setWidth(char symbols);
    void setWidth(ofstream& output, char symbols);
    void setWidthFile(char symbols);
    void setWidthFile(ofstream& output, char symbols);

    //sets the 3 types of borders
    void setNewBorder(int options);

    //overloaded operators for input and output
    friend ostream& operator<<(ostream& output, const Box& a);
    friend istream& operator>>(istream& input, Box& a);
    
    size_t messageLength();
    void singleLine();
    void doubleLine();
    void shaded();
};
#endif
