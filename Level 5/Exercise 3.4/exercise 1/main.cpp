#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

using namespace suman::CAD;

int main() {
    std::cout << "Default constructors: " << std::endl;
    // First default constructor for Line and the default constructor for Point
    Line l1;

    std::cout << "\n Parameterized constructors: " << std::endl;
    // Parameterized constructor for Line and the copy constructor for Point
    Line l2(Point(1.0, 2.5), Point(3.4, 5.2));

    std::cout << "\n Testing copy constructor: " << std::endl;
    // Copy constructor for Line and the copy constructor for Point
    Line l3(l2);

    return 0;
}