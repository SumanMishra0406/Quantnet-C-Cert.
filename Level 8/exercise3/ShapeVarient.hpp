#ifndef SHAPEVARIENT_HPP
#define SHAPEVARIENT_HPP

#include "Point.hpp" 
#include "Line.hpp"  
#include "Circle.hpp"
#include <boost/variant.hpp>
#include <iostream>

namespace suman {
namespace CAD {

typedef boost::variant<Point, Line, Circle> ShapeTypeVariant;

ShapeTypeVariant createShape();


class MoveVisitor : public boost::static_visitor<void> {
private:
    const double m_dx;
    const double m_dy;

public:
    MoveVisitor(double dx, double dy);
    
    // Non-const references because they modify the shape
    void operator()(Point& p) const;
    void operator()(Line& l) const;
    void operator()(Circle& c) const;
};

class PrintVisitor : public boost::static_visitor<void> {
public:
    // Const references because they only print the shape
    void operator()(const Point& p) const;
    void operator()(const Line& l) const;
    void operator()(const Circle& c) const;
};

}
}

#endif