#ifndef INPUT_VALIDATION_H_INC
#define INPUT_VALIDATION_H_INC

#include <vector>
#include <string>
using namespace std;

double Double_both_Bound(double lowBound, double upBound, string prompt);
long Long_Both_Bound(long lowBound, long upBound, string prompt);
long Long_Low(long lowBound, string prompt);
long Long_Up(long upBound, string prompt);
long Num_Check_Long(vector<long> &numbers, string prompt);
double Num_Check_Double(vector<double> &numbers, string prompt);
char Char_low_bound(char lowBound, string prompt);
char Char_Up_Bound(char UpBound, string prompt);
double Double_LowBound(double lowBound, string prompt);
double Double_UpBound(double upBound, string prompt);
#endif
