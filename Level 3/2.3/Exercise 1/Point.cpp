//Point.cpp
/*
Point.cpp
Implementation of the Point class.
We define the constructors, destructor, and member functions
for (x,y) coordinates
Distance functions are included to find distance between origin and distance between
p1 and p2. Here we are making extra constructors (parameter and copy) to see how they work

 
 Author: Suman Mishra
 Date: 29/08/2025
 */


#include "Point.hpp"
#include <iostream> //stdcout
#include <sstream> //std::stringstream
using namespace std;

//constructor defn
Point :: Point(){
    x = y = 0.0;
    cout<<"Default constructor"<<endl;
}

// param constructor
Point::Point(double x_val, double y_val){
    x = x_val;
    y = y_val;
    cout << "Parameter constructor" << endl;
}

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
double Point :: GetX(){
    return x;
}

//getter defn for y coord
double Point :: GetY(){
    return y;
}

//setter defn for x
void Point::SetX(double X){
    x = X;
}

//setter defn for y
void Point::SetY(double Y){
    y = Y;
}

// defn of ToString function 
string Point::ToString(){
    stringstream sstream;
    sstream << "Point(" << x << "," << y << ")";

    return sstream.str();  // get the string from the string buffer
}

// Calculate the distance to the origin (0, 0).
double Point :: DistanceOrigin(){
    return sqrt(x*x + y*y);

}

 // Calculate the distance between two points.
double Point:: Distance(Point p){ //pass by value
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    // The destructor for the temporary object is called when the function returns.

}