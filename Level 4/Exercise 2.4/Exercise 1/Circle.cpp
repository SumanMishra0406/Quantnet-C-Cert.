/*
Circle.cpp
Implementation of circle class.
Circle has a 2d circle with a center and a radius
Methods involve creating a circle, getting and seeting the circle properties
getting the area, diameter, and circumference

New assignment operator implementation
Author: Suman Mishra
*/

#define _USE_MATH_DEFINES
#include "Circle.hpp"
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

// Default constructor
Circle::Circle() : center(), radius(1.0){
    cout<<"Default Constructor\n";
}

// Parameter constructor
Circle::Circle(Point& new_center, double new_radius) : center(new_center), radius(new_radius){
    cout<<"Parameter Constructor\n";
}

//copy constructor
Circle::Circle(const Circle& c) : center(c.center), radius(c.radius){
    cout<<"Copy Constructor\n";
}
//destructor
Circle::~Circle() {
    cout<<"Destructor\n";
}

// Assignment operator
Circle& Circle::operator = (const Circle& source)
{
    if (this == &source){
        return *this;
    }
    center = source.center;
    radius = source.radius;
    return *this;
}

// Getter for center
Point Circle::center_pt() const{
    return center;
}

// Getter for radius
double Circle::Radius() const{
    return radius;
}

// Setter for center
void Circle::center_pt(const Point& update_center){
    center = update_center;
}

// Setter for radius
void Circle::Radius(double update_radius){
    radius = update_radius;
}

//Diameter function
double Circle::Diameter() const{
    return 2.0 * radius;
}

// Area pi*(r^2)
double Circle::Area() const{
    return M_PI * pow(radius,2);
}

// circumference 2*pi*r
double Circle::Circumference() const{
    return 2.0 * M_PI * radius;
}

string Circle::ToString() const{
    stringstream sstream;
    sstream << "Center: " << center.ToString() << ", Radius: " << radius;
    return sstream.str();
}