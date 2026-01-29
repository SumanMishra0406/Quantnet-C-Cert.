#include "ShapeVarient.hpp"
#include <iostream>
using namespace std;
namespace suman {
namespace CAD {


ShapeTypeVariant createShape() {
    int choice;
    cout << "Enter shape type (1=Point, 2=Line, 3=Circle): ";
    
    if (!(cin >> choice)) {
        choice = 0; //default
    }

    switch (choice) {
        case 1:
            return Point(10.0, 20.0);
        case 2:
            return Line(Point(1.0, 1.0), Point(5.0, 5.0));
        case 3:
            return Circle(Point(0.0, 0.0), 5.0);
        default:
            cout << "Invalid choice. Creating default Point (0, 0).\n";
            return Point(0.0, 0.0);
    }
}


//MoveVisitor Definitions

MoveVisitor::MoveVisitor(double dx, double dy) : m_dx(dx), m_dy(dy) {}

void MoveVisitor::operator()(Point& p) const {
    std::cout << "Moving Point\n";
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

void MoveVisitor::operator()(Line& l) const {
    std::cout << "Moving Line\n";
    // Get, modify, and set Point 1
    Point start_pt = l.Point1();
    start_pt.X(start_pt.X() + m_dx);
    start_pt.Y(start_pt.Y() + m_dy);
    l.Point1(start_pt);
    
    // Get, modify, and set Point 2
    Point end_pt = l.Point2();
    end_pt.X(end_pt.X() + m_dx);
    end_pt.Y(end_pt.Y() + m_dy);
    l.Point2(end_pt);
}

void MoveVisitor::operator()(Circle& c) const {
    std::cout << "Moving Circle\n";
    // Get, modify, and set center Point
    Point center_pt = c.center_pt();
    center_pt.X(center_pt.X() + m_dx);
    center_pt.Y(center_pt.Y() + m_dy);
    c.center_pt(center_pt);
}


// PrintVisitor Definitions

void PrintVisitor::operator()(const Point& p) const {
    cout << p; 
}

void PrintVisitor::operator()(const Line& l) const {
    cout << l; 
}

void PrintVisitor::operator()(const Circle& c) const {
    cout << c; 
}

}
}