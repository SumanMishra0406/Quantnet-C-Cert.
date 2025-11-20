//Point.hpp
/* Point Class Header file
The point class contains coordinates (x,y)
Includes Functions that create points, accessing and modifying the coordinates
and calculate the distance between the point and origin or between two points
*/
#ifndef Point_hpp
#define Point_hpp
#include <string>

class Point{
    private:
    double x,y;

    public:
    Point();
    Point(double x_val, double y_val); // param constructor
    Point(const Point& p); //copy constructor
    ~Point();

    double X() const;
    double Y() const;

    void X(double X);
    void Y(double Y);

    std::string ToString() const;

    double Distance() const;
    double Distance(const Point& p) const; // pass by reference
};

#endif