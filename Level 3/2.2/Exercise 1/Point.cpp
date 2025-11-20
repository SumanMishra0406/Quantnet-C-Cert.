/*
Point.cpp
Implementation of the Point class.
We define the constructors, destructor, and member functions
for (x,y) coordinates
 
 Author: Suman Mishra
 Date: 29/08/2025
 */

#include "Point.hpp"
#include <iostream> //stdcout
#include <sstream> //std::stringstream
using namespace std;

//constructor defn

// Default constructor.
// Initializes the x and y coordinates to 0.0
Point :: Point(){
    x = y = 0.0;
}

//destructor defn
// Prints a message when a Point object is destroyed.
Point :: ~Point(){
    cout << "Bye my point...\n";
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