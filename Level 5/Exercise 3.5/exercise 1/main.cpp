#include "Point.hpp"
#include "Line.hpp"
#include <iostream>

using namespace suman::CAD;

int main() {
    // Point object.
    Point p(1.0, 2.0);

    // Shape pointer that points to the Point object
    Shape* s = &p;

    // Call ToString() using the Shape pointer.
    // Since ToString() is virtual, the correct version from Point will be called.
    std::cout << "The Shape pointer s is pointing to a Point object and calling ToString():" << std::endl;
    std::cout << s->ToString() << std::endl;

    //Line object.
    Line l(Point(3.0, 4.0), Point(5.0, 6.0));

    // Shape pointer points to the Line object
    Shape* s2 = &l;

    // The correct version from Line will be called.
    std::cout << "\nThe Shape pointer s2 is pointing to a Line object and calling ToString():" << std::endl;
    std::cout << s2->ToString() << std::endl;

    return 0;
}