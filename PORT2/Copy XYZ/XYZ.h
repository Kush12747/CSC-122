#ifndef DATA_CLASS_H_INC
#define DATS_CLASS_H_INC

#include <iostream>
using namespace std;

class Data 
{
public:
    Data();
    void read(ifstream& input);
    void write(ofstream& output);

private:
    static const int length = 30;
    int idNum;
    double gpa;
    char name[length], grade;
};
#endif
