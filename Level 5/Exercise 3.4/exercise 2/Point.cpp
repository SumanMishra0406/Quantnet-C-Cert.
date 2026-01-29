#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace suman
{
    namespace CAD
    {
        Point::Point() : Shape(), x(0.0), y(0.0) {
            cout << "Default constructor" << endl;
        }

        Point::Point(double x_val, double y_val) : Shape(), x(x_val), y(y_val) {
            cout << "parameter constructor" << endl;
        }

        Point::Point(const Point& p) : Shape(p), x(p.x), y(p.y) {
            cout << "Copy constructor" << endl;
        }

        Point::~Point() {
            cout << "Destructor" << endl;
        }

        double Point::X() const {
            return x;
        }

        double Point::Y() const {
            return y;
        }

        void Point::X(double X) {
            x = X;
        }

        void Point::Y(double Y) {
            y = Y;
        }

        string Point::ToString() const{
            stringstream sstream;
            sstream << "Point(" << x << "," << y << ")";

            return sstream.str();
        }

        double Point::Distance() const {
            return sqrt(x * x + y * y);
        }

        double Point::Distance(const Point& p) const {
            return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
        }

        Point Point::operator-() const {
            return Point(-x, -y);
        }

        Point Point::operator*(double factor) const {
            return Point(x * factor, y * factor);
        }

        Point Point::operator+(const Point& p) const {
            return Point(x + p.x, y + p.y);
        }

        bool Point::operator==(const Point& p) const {
            return (x == p.x) && (y == p.y);
        }

       Point &Point::operator=(const Point &source){
            if (this == &source)
            {
                return *this;
            }
            Shape::operator=(source);
            
            x = source.x;
            y = source.y;
            return *this;
        }

        Point& Point::operator*=(double factor) {
            x *= factor;
            y *= factor;
            return *this;
        }

        ostream& operator<<(ostream& os, const Point& p) {
            os << p.ToString();
            return os;
        }
    }
}