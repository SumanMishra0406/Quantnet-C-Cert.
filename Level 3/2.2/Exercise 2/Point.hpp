/*
Point.hpp Header File for Point Class
we have a (x,y) coordinates (private) with methods to get and set values
and convert point to string and to calculate distance
 */

#ifndef Point_hpp
#define Point_hpp
#include <string>

class Point{
    private:
    double x,y;

    public:
    Point();
    ~Point();

    double GetX();
    double GetY();

    void SetX(double X);
    void SetY(double Y);

    std::string ToString();

    double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
    double Distance(Point p); // Calculate the distance between two points.
};

#endif