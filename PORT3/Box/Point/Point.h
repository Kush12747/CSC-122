#ifndef POINT_CLASS_HEADER_INCLUDED
#define POINT_CLASS_HEADER_INCLUDED
#include <iostream>

// A 2D point class
class Point
{
    double x, // x cordinate of point
           y; //y cordinate of point
public:
    Point(void) : x(0), y(0) {}
    Point(double new_x, double new_y) : x(new_x), y(new_y) {}
    Point(const Point & other) : x(other.x), y(other.y) {}

    void Output(std::ostream & os = std::cout) const; //output this point
    friend std::ostream& operator << (std::ostream & os, const Point & a)
        { a.Output(os); return os; };

    void Input(std::istream & is = std::cin); //input this point
    friend std::istream & operator>>(std::istream & is, Point & a)
        { a.Input(is); return is; }

    // distance between this point and other
    double distance(const Point & other) const; 
    
    double operator-(const Point& a) const
        { Point b(*this); return b.distance(a); }

    double get_x(void) const { return x; }
    double get_y(void) const { return y; }

    void set_x(double new_x);
    void set_y(double new_y);

    double operator[](char c)
        { return c == 'x' ? get_x() : (c == 'y' ? get_y() : 0); }

    Point midPoint(const Point& a)//find the midpoint
    {
        Point mp((get_x() + a.get_x()) / 2, (get_y() + a.get_y()) / 2);
        return mp; 
    }

    Point operator/(const Point & b)
    {   
        Point a(*this); 
        return a.midPoint(b); 
    }

    Point flip_x(void) const;
    Point flip_y(void) const;

    Point shift_x(double move_by) const;
    Point shift_y(double move_by) const;

    bool operator==(const Point& b)//to check ==
    {
        Point a(*this);
        return ((a.get_x() == b.get_x())
            && (a.get_y() == b.get_y()));
        
    }
    bool operator!=(const Point& b)//check !=
    {
        Point a(*this);
        return !(a == b);
    }
};

#endif
