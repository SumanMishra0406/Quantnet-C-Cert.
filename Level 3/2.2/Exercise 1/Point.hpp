/*
Point.hpp Header File for Point Class
we have a (x,y) coordinates (private) with methods to get and set values
and convert point to string
 */

#ifndef Point_hpp
#define Point_hpp
#include <string>
class Point{
    private:
    double x,y;  // Member variables to store the x and y coordinates of the point.

    public:
    // Constructors and Destructor
    Point(); // Default constructor. Initializes a point to (0, 0).
    ~Point(); // Destructor

    double GetX(); //gets the x coordinate
    double GetY(); //gets the y coordinate

    void SetX(double X); //sets the x coordinate
    void SetY(double Y); //sets the y coordinate

    std::string ToString(); // Returns a string representation of the point (e.g., "Point(x,y)").

};

#endif