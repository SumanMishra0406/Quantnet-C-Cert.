#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

using namespace suman::CAD;

int main() {
    Point p(1.0, 2.0);
    Line l(Point(3.0, 4.0), Point(5.0, 6.0));
    Circle c(Point(0.0, 0.0), 5.0);

    // The output should include the Shape ID for this point obj.
    std::cout << "Printing a Point object:" << std::endl;
    std::cout << p << std::endl;

    // Similarily for line
    std::cout << "\nPrinting a Line object:" << std::endl;
    std::cout << l << std::endl;

    //The output should include the Shape ID for the circle obj
    std::cout << "\nPrinting a Circle object:" << std::endl;
    std::cout << c.ToString() << std::endl;

    // Test polymorphism with the Shape pointer
    Shape* s1 = &p;
    Shape* s2 = &l;
    Shape* s3 = &c;

    std::cout << "\nBase Class Functionality:" << std::endl;
    std::cout << s1->ToString() << std::endl; // Calls Point's ToString()
    std::cout << s2->ToString() << std::endl; // Calls Line's ToString()
    std::cout << s3->ToString() << std::endl; // Calls Circle's ToString()

    return 0;
}