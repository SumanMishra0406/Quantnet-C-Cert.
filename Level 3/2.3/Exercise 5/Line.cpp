/*
Implementation of Line Class. A Line requires two points - start and end
It provides methods to access and modify these points
convert the line to a string and calculate the length of the line

Suman Mishra
29/08/2025
*/
#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath> // Include cmath for sqrt, need for Point::Distance
using namespace std;
// Default constructor
Line::Line() : start(0.0, 0.0), end(0.0, 0.0){
    cout << "Line default constructor called." << endl;
}

// Parameterized constructor
Line::Line(const Point& start_pt, const Point& end_pt) : start(start_pt), end(end_pt){
    cout << "Line parameterized constructor called." << endl;
}

// Copy constructor
Line::Line(const Line& line) : start(line.start), end(line.end){
    cout << "Line copy constructor called." << endl;
}

// Destructor
Line::~Line(){
    cout << "Line destructor called." << endl;
}

// Getter for the start point
const Point& Line::Point1() const{
    return start;
}

// Getter for the end point
const Point& Line::Point2() const{
    return end;
}

// Setter for the start point (no const, void return)
void Line::Point1(const Point& start_pt){
    start = start_pt;
}

// Setter for the end point (no const, void return)
void Line::Point2(const Point& end_pt){
    end = end_pt;
}

// Returns a string representation of the line
std::string Line::ToString() const{
    stringstream sstream;
    sstream << "Line(" << start.ToString() << ", " << end.ToString() << ")";
    return sstream.str();
}

// Calculates the length by delegating to the Point's Distance function
double Line::Length() const{
    return start.Distance(end);
}