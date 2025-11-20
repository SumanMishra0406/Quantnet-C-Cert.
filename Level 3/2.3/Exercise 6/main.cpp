#include "Point.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;

int main() {
    cout<< "-Point Class-"<<endl;
    // default point (0,0)
    Point p1; //default constructor called
    cout << "Default point p1: " << p1.ToString() << endl;
    cout << "p1 x coordinate: " << p1.X() << endl;
    cout << "p1 y coordinate: " << p1.Y() << endl;
    cout << "Distance from origin: " << p1.Distance() << endl;
    cout << endl;

    // point with specific coords
    Point p2(3.0, 4.0); //paramter constructor called
    cout << "Point p2: " << p2.ToString() << endl;
    cout << "Distance from origin: " << p2.Distance() << endl;
    cout << "Distance between p1 and p2: " << p1.Distance(p2) << endl;
    cout << endl;

    // Set new coordinates for p1
    p1.X(1.0);
    p1.Y(2.0);
    cout << "Updated p1: " << p1.ToString() << endl;
    cout << endl;

    // Test the Circle class
    cout << "-Circle class-" << endl;

    // Create a default circle
    Circle c1; //first center is initialized --> point default constructor called, then circle default constructor called
    cout << "Default circle c1: " << c1.ToString() << endl;
    cout << "Radius: " << c1.Radius() << endl;
    cout << "Diameter: " << c1.Diameter() << endl;
    cout << "Area: " << c1.Area() << endl;
    cout << "Circumference: " << c1.Circumference() << endl;
    cout << endl;

    // Create a circle with a specified center and radius
    Circle c2(p2, 5.0); //first point copy constructor is called, then circle parameter constructor called
    cout << "Circle c2: " << c2.ToString() << endl;
    cout << "Radius: " << c2.Radius() << endl;
    cout << "Diameter: " << c2.Diameter() << endl;
    cout << "Area: " << c2.Area() << endl;
    cout << "Circumference: " << c2.Circumference() << endl;
    return 0;
    //objects destroyed in reverse order as we return 0 since we delete by the order of the object in the stack
    //Total 6 constructors --> 6 destructors
}