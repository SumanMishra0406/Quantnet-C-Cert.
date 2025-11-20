/*
Point.cpp
Implementation of the Point class.
We define the constructors, destructor, and member functions
for (x,y) coordinates
Here we are using function overloading to show that we can have more than one 
function with the same name as long as they have different input arguments
 
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

// param constructor
Point::Point(double x_val, double y_val) {
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
double Point :: X(){
    return x;
}

//getter defn for y coord
double Point :: Y(){
    return y;
}

//setter defn for x
void Point::X(double X)
{
    x = X;
}

//setter defn for y
void Point::Y(double Y)
{
    y = Y;
}

// defn of ToString function 
string Point::ToString()
{
    stringstream sstream;
    sstream << "Point(" << x << "," << y << ")";

    return sstream.str();  // get the string from the string buffer
}

// Distance function without param
//calculate the distance between point and origin
double Point :: Distance(){
    return sqrt(x*x + y*y);

}
//distance function with 1 param.
// Calculate the distance between two points.
double Point:: Distance(const Point& p){
    //we dont create a temporary copy of p now.
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));

}