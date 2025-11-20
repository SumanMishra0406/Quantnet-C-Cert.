//Point.hpp
#ifndef Point_hpp
#define Point_hpp
#include <string>
using namespace std;

class Point{
    private:
    double x,y;

    public:
    Point(); //default constructor
    Point(double x_val, double y_val); // parameter constructor
    Point(Point& p); //copy constructor
    ~Point(); //destructor

    double GetX();
    double GetY();

    void SetX(double X);
    void SetY(double Y);

    string ToString();

    double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
    double Distance(const Point& p); // pass by const reference
};

#endif