#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point a, b;

    cout << "\t\tTest For Point Class" << endl
         << "==================================================="
         << "\nEnter your 1st cordinate point: ";
    cin >> a;
    cout << "\nEnter your 2nd point: ";
    cin >> b;

    Point check(a / b);

    cout << "\nThe distance between " << a << " and "
         << b << " is: " << (a - b) << "\nThe midpoint is: " << check;

    cout << "\n\nTesting the points if equal or not equal..." << endl;
    //0 = false, 1 = true
    cout << "\nAre the points equal? " << (a == b);
    cout << "\nAre the points not equal? " << (a != b);
    cout << "\n===================================================" << endl;
    cout << endl;
}
