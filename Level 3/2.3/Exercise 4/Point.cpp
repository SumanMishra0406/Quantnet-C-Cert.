/*
Point.cpp
This file contains the implementation of the Point class.
It defines the constructors, destructor, and member functions
for handling a 2D point's coordinates and related operations.
Const after function gaurentees that the function will not modify the objects
member variables

Author: Suman Mishra
Date: 29/08/2025
 */
#include "Point.hpp"
#include <iostream> //stdcout
#include <sstream> //std::stringstream

//constructor defn
Point :: Point(){
    x = y = 0.0;
    cout<<"Default constructor"<<endl;
}

// parameter constructor
Point::Point(double x_val, double y_val){
    x = x_val;
    y = y_val;
    cout << "Parameter constructor" << endl;
}

//copy constructor
Point::Point(Point& p){
    x=p.x;
    y=p.y;
    cout << "Copy constructor" << endl;
}

//destructor defn
Point :: ~Point(){
    cout<<"Destructor"<<endl;
}

//getter defn for x coord
double Point :: X() const{
    return x;
}

//getter defn for y coord
double Point :: Y() const{
    return y;
}

//setter defn for x
void Point::X(double X){
    x = X;
}

//setter defn for y
void Point::Y(double Y){
    y = Y;
}

// defn of ToString function 
string Point::ToString()const{
    stringstream sstream;
    sstream << "Point(" << x << "," << y << ")";

    return sstream.str();  // get the string from the string buffer
}

// Distance function without param
//calculate the distance between point and origin
double Point :: Distance() const{
    return sqrt(x*x + y*y);

}
//distance function with 1 param.
// Calculate the distance between two points.
double Point:: Distance(const Point& p) const{ //const ensures passed in object isn't modified
    //we dont create a temporary copy of p now.
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));

}