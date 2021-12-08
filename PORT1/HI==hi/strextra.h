#ifndef STREXTRA_H_INC
#define STREXTRA_H_INC

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

void skip(const string& skip, bool skipSpace, bool skipPunct,
    size_t& i, size_t& skippy) {//skip function to checks for skips

    while ((skipSpace && skip[i] == ' ') || (skipPunct && ispunct(skip[i]))) {
        skippy++;
        i++;
    }
}

short string_comparison(const string& str1, const string& str2,
    bool skipSpace, bool skipPunct) {
    short comp_res = 0;
    size_t skippy1{ 0 }, skippy2{ 0 }, i, j;

    for (i = 0, j = 0; i < str1.length() && j < str2.length() && 
        comp_res == 0; i++, j++) {
        //call function skip
        skip(str1, skipSpace, skipPunct, i, skippy1);
        skip(str2, skipSpace, skipPunct, j, skippy2);

        if (!isdigit(str1[i]) || !isdigit(str2[j])) {
            if (toupper(str1[i]) != toupper(str2[j])) {
                comp_res = toupper(str1[i]) < toupper(str2[j]);
            }
        }
    }
    //call to skip function
    skip(str1, skipSpace, skipPunct, i, skippy1);
    skip(str1, skipSpace, skipPunct, j, skippy2);
    //if statement to find !=, <, > or ==
    if (str1.length() - skippy1 != str2.length() - skippy2) {
       if (str1.length() - skippy1 < str2.length() - skippy2) {
           comp_res = -1;
       }
       else
           comp_res = 1;
       }
       else
           comp_res = 0;
       return comp_res;
}
#endif
