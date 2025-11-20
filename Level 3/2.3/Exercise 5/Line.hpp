/*
Header file to define the Line Class. 
Consists of start and end point and methods to get, set points as well as
convert to string and calculate length of line in coordinate plane
*/
#ifndef Line_hpp
#define Line_hpp
#include "Point.hpp"
#include <string>

class Line{
    private:
    Point start; //  this is aggregation (has-a relationship)
    Point end;

    public:
    // Default constructor
    Line();
    // Start and end point constructor
    Line(const Point& start_pt, const Point& end_pt);
    // Copy constructor
    Line(const Line& line);
    // Destructor
    ~Line();

    // Getter functions (const-correct)
    const Point& Point1() const; //start
    const Point& Point2() const; //end
    
    // Setter functions (void return type)
    void Point1(const Point& start_pt);
    void Point2(const Point& end_pt);

    std::string ToString() const;
    double Length() const; 
};

#endif