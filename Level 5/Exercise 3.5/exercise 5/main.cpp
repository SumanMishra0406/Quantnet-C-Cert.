#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

using namespace suman::CAD;

int main() {
    Point p(1.0, 2.0);
    Line l(Point(3.0, 4.0), Point(5.0, 6.0));
    Circle c(Point(0.0, 0.0), 5.0);

    //Print() function for Point and Line.
    std::cout << "Print() on Point object:" << std::endl;
    p.Print();
    
    std::cout << "Print() on a Line object:" << std::endl;
    l.Print();

    std::cout << "Print() on a Circle object:" << std::endl;
    c.Print();

    return 0;
}