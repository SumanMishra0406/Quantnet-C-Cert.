#define _USE_MATH_DEFINES
#include "Circle.hpp"
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

namespace suman {
    namespace CAD {
        Circle::Circle() : Shape(), center(), radius(1.0) {
            cout << "Default Constructor\n";
        }

        Circle::Circle(const Point& new_center, double new_radius) : Shape(), center(new_center), radius(new_radius) {
            cout << "Parameter Constructor\n";
        }

        Circle::Circle(const Circle& c) : Shape(c), center(c.center), radius(c.radius) {
            cout << "Copy Constructor\n";
        }

        Circle::~Circle() {
            cout << "Destructor\n";
        }

        Circle& Circle::operator = (const Circle& source) {
            if (this == &source) {
                return *this;
            }
            Shape::operator=(source);
            center = source.center;
            radius = source.radius;
            return *this;
        }

        Point Circle::center_pt() const {
            return center;
        }

        double Circle::Radius() const {
            return radius;
        }

        void Circle::center_pt(const Point& update_center) {
            center = update_center;
        }

        void Circle::Radius(double update_radius) {
            radius = update_radius;
        }

        double Circle::Diameter() const {
            return 2.0 * radius;
        }

        double Circle::Area() const {
            return M_PI * pow(radius, 2);
        }

        double Circle::Circumference() const {
            return 2.0 * M_PI * radius;
        }

        string Circle::ToString() const {
            stringstream sstream;
            sstream << Shape::ToString() << ", Center: " << center.ToString() << ", Radius: " << radius;
            return sstream.str();
        }

        void Circle::Draw() {
            cout << "Drawing a Circle with center at " << center.ToString() << " and radius " << radius << "." << endl;
        }

        ostream& operator << (ostream& os, const Circle& c) {
            os << c.ToString();
            return os;
        }
    }
}