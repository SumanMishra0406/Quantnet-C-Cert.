#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>

using namespace suman::CAD;

int main() {
    // array of Shape ptrs
    Shape* shapes[10];

    shapes[0] = new Point(1.0, 2.0);
    shapes[1] = new Line(Point(3.0, 4.0), Point(5.0, 6.0));
    shapes[2] = new Circle(Point(0.0, 0.0), 5.0);

    // Loop through the array and call the Draw() function
    for (int i = 0; i < 3; ++i) {
        shapes[i]->Draw();
    }
    
    // delete the objs
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }
    
    return 0;
}