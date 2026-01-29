#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Array.hpp"
#include "Circle.hpp"
using namespace std;
// single class
using suman::CAD::Line;
// complete namespace.
using namespace suman::Containers;
// alias
namespace sm = suman::CAD;

int main() {
    // full namespace path
    suman::CAD::Point p1(1.0, 2.0);
    suman::CAD::Point p2(3.0, 4.0);
    suman::CAD::Point p3(5.0, 6.0);

    // Testing the Line class
    Line line1(p1, p2);
    Line line2 = line1;
    line2 = Line(p1, p3);
    cout << "Line1: " << line1 << ", Length: " << line1.Length() <<endl;
    cout << "Line2: " << line2 << ", Length: " << line2.Length() <<endl;

    cout << "-----" <<endl;

    // Testing array class using "using namespace"
    Array arr1;
    arr1.SetElement(0, p1);
    arr1.SetElement(1, p2);
    Array arr2(2);
    arr2 = arr1;
    cout << "Array size: " << arr2.Size() <<endl;
    cout << "Array[0]: " << arr2[0] <<endl;
    cout << "Array[1]: " << arr2[1] <<endl;

    cout << "-----" <<endl;

    // Testing the Circle class using the namespace alias
    sm::Circle circle1(p1, 5.0);
    sm::Circle circle2;
    circle2 = circle1;
    cout << "Circle1: " << circle1 <<endl;
    cout << "Circle2: " << circle2 <<endl;

    return 0;
}