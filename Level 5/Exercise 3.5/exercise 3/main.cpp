#include "Point.hpp"
#include "Line.hpp"
#include "Shape.hpp"
#include <iostream>

using namespace suman::CAD;

int main() {
    Shape* shapes[3];

    // different type of object for each pointer
    shapes[0] = new Shape();
    shapes[1] = new Point(1.0, 2.0);
    shapes[2] = new Line(Point(3.0, 4.0), Point(5.0, 6.0));

    // delete the objects
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}