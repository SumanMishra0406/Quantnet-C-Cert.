//Point.hpp
#ifndef Point_hpp
#define Point_hpp
#include <string>
using namespace std;

class Point{
    private:
    double x,y;

    public:
    Point();
    Point(double x_val, double y_val); // parameter constructor
        Point(Point& p); //copy constructor

    ~Point();

    //we don't get an error here since input parameters are different
    //for getter and setter functions
    double X();
    double Y();

    void X(double X); 
    void Y(double Y);

    string ToString();

    double Distance(); // function overloading, doesn't lead to error because params are different
    double Distance(const Point& p); // pass by reference
};

#endif