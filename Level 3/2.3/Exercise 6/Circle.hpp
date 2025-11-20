/*
Header file defines the Circle class.
Circle has a 2d circle with a center and a radius
Methods involve creating a circle, getting and seeting the circle properties
getting the area, diameter, and circumference

Author: Suman Mishra
Date: 29/08/2025
*/
#ifndef Circle_hpp
#define Circle_hpp
#include "Point.hpp"

class Circle{
    private:
    Point center;
    double radius;

    public:
    Circle(); //default constructor
    Circle(Point& new_center, double new_radius); // parameter constructor
    Circle(const Circle& c); // copy constructor
    ~Circle(); //destructor

    //Member functions
    Point center_pt() const; //getter function to get center
    double Radius() const; //getter function to get radius

    void center_pt(const Point& update_center); //setter to set the center
    void Radius(double update_radius);

    double Diameter() const;
    double Area() const;
    double Circumference() const;
    std::string ToString() const;

    
};
#endif