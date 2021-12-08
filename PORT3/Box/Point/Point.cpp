#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

//input function for (x,y) format
void Point::Input(std::istream& is)
{
    char temp;
    is >> temp >> x >> temp >> y >> temp;
    return;
}
//output for (x,y) format
void Point::Output(std::ostream& os) const
{
    os << '(' << x << ", " << y << ')';
    return;
}
//calculate the distance between 2 points
double Point::distance(const Point& other)const
{
    return sqrt(pow(other.x - x, 2.0) +
           pow(other.y - y, 2.0));
}
//using setters functions
void Point::set_x(double new_x)
{
    x = new_x;
    return;
}
void Point::set_y(double new_y)
{
    y = new_y;
    return;
}

//function to flip points
Point Point::flip_x(void) const
    { return Point(x, -y); }
Point Point::flip_y(void) const
    { return Point(-x, y); }

//function to move points for x and y
Point Point::shift_x(double move_by) const
    { return Point(x + move_by, y); }
Point Point::shift_y(double move_by) const
    { return Point(x, y + move_by); }
