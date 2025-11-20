//Point.hpp
/* Point Class Header file
The point class contains coordinates (x,y)
Includes Functions that create points, accessing and modifying the coordinates
and calculate the distance between the point and origin or between two points.
All methods are const except for setter functions here

Also included function overloading for getter and setter here
*/
#ifndef Point_hpp
#define Point_hpp
#include <string>
using namespace std;

class Point{
    private:
    double x,y;

    public:
    // Default constructor
    Point();
    // Param Constructor
    // Initializes the point with x and y
    Point(double x_val, double y_val);
    Point(Point& p); //copy constructor
    // Destructor.
    ~Point();

    double X() const; //getter function returns x coord.
    double Y() const; //getter function returns y coord

    void X(double X); // setter function sets x coord
    void Y(double Y); //setter function sets y coord

    string ToString() const; //convert point to string

    double Distance() const; //calculate distance between point and origin
    double Distance(const Point& p) const; // pass by reference
    //calculate distance between two points
};

#endif