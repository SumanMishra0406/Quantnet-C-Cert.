//Point.hpp
/* Point Class Header file using inline
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
    Point(double x_val, double y_val); // parameter constructor
    Point(Point& p); //copy constructor
    ~Point();

    // getter functn will be defined outside the class
    inline double X() const;
    inline double Y() const;

    // The setters are defined inside the class
    //which makes them default inline
    void X(double X){x=X;}
    void Y(double Y){y=Y;}

    std::string ToString() const;

    double Distance() const;
    double Distance(const Point& p) const; // pass by reference
};

// The getters are defined outside the class declaration
// using the inline keyword.
inline double Point::X() const {
    return x;
}

inline double Point::Y() const {
    return y;
}


#endif