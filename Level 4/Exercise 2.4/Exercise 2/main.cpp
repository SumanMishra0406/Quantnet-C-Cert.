/*
Using the ostream operator to directly print
*/
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main() {
    // Testing operators on the Point class
    cout << "Testing Point Class Operators" << endl;
    Point p1(5.0, 10.0);
    Point p2(20.0, 30.0);
    
    cout << "Initial values: "<<endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    // Testing the negation operator
    Point p_neg = -p1;
    cout << "Test negation (-p1): " << p_neg << endl;

    // Testing the scaling operator
    Point p_scale = p1 * 5;
    cout << "Test scaling (p1 * 5): " << p_scale << endl;

    // Test the addition operator
    Point p_sum = p1 + p2;
    cout << "Test addition (p1 + p2): " << p_sum << endl;

    // Test the equality operator
    cout << "Test equality (p1 == p2): ";
    if (p1 == p2) {
        cout << "p1 and p2 are equal." << endl;
    } else {
        cout << "p1 and p2 are not equal." << endl;
    }

    // Test the assignment operator
    Point p_assign;
    p_assign = p1;
    cout << "Test assignment (p_assign = p1): " << p_assign << endl;

    // Test the scale and assign operator
    p1 *= 3.0;
    cout << "Test scale and assignment (p1 *= 3.0): " << p1 << endl;

    // Testing the assignment operator for Line and Circle
    cout << "\n Testing Assignment Operators for Line and Circle "<<endl;
    
    // Test for the Line class
    Point p3(10.0, 10.0);
    Point p4(15.0, 15.0);
    Line l1(p3, p4);
    Line l2;
    l2 = l1;
    cout << "Test assignment for Line: "<<endl;
    cout << "Initial line (l1): " << l1 << endl;
    cout << "l2 = l1: " << l2 << endl;

    // Test for the Circle class
    Point center(5.0, 5.0);
    double radius = 5.0;
    Circle c1(center, radius);
    Circle c2;
    c2 = c1;
    cout << "Test assignment for Circle: "<<endl;
    cout << "Circle c1: " << c1 << endl;
    cout << "Assigned circle (c2 = c1): " << c2 << endl;

    return 0;
}