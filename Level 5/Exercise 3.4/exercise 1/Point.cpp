/*
Point.cpp
This file contains the implementation of the Point class.
It defines the constructors, destructor, and member functions
for handling a 2D point's coordinates and related operations.

Implementing the operator functions
Author: Suman Mishra
*/
#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace suman
{
    namespace CAD
    {

        // Default constructor using colon syntax
        Point::Point() : x(0.0), y(0.0){
            cout << "Default constructor" << endl;
        }

        // Parameterized constructor using colon syntax
        Point::Point(double x_val, double y_val) : x(x_val), y(y_val){
            cout << "parameter constructor" << endl;
        }

        // Copy constructor using colon syntax
        Point::Point(const Point &p) : x(p.x), y(p.y){
            cout << "Copy constructor" << endl;
        }

        // destructor defn
        Point ::~Point(){
            cout << "Destructor" << endl;
        }

        // getter defn for x coord
        double Point ::X() const{
            return x;
        }

        // getter defn for y coord
        double Point ::Y() const{
            return y;
        }

        // setter defn for x
        void Point::X(double X){
            x = X;
        }

        // setter defn for y
        void Point::Y(double Y){
            y = Y;
        }

        // defn of ToString function
        string Point::ToString() const{
            stringstream sstream;
            sstream << "Point(" << x << "," << y << ")";

            return sstream.str();
        }

        // Distance function without param
        double Point ::Distance() const{
            return sqrt(x * x + y * y);
        }
        
        // distance function with 1 param.
        double Point::Distance(const Point &p) const{
            return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
        }

        // Operator overloads
        Point Point::operator-() const{
            return Point(-x, -y);
        }

        Point Point::operator*(double factor) const{
            return Point(x * factor, y * factor);
        }

        Point Point::operator+(const Point &p) const{
            return Point(x + p.x, y + p.y);
        }

        bool Point::operator==(const Point &p) const{
            return (x == p.x) && (y == p.y);
        }

        Point &Point::operator=(const Point &source){
            if (this == &source)
            {
                return *this;
            }
            x = source.x;
            y = source.y;
            return *this;
        }

        Point &Point::operator*=(double factor)
        {
            x *= factor;
            y *= factor;
            return *this;
        }

        ostream &operator<<(ostream &os, const Point &p)
        {
            os << p.ToString();
            return os;
        }
    }
}