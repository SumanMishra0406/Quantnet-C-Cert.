#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace suman {
    namespace CAD {
        Line::Line() : Shape(), start(), end() {
            std::cout << "Line default constructor called." << std::endl;
        }

        Line::Line(const Point& start_pt, const Point& end_pt) : Shape(), start(start_pt), end(end_pt) {
            cout << "Line parameterized constructor called." << endl;
        }

        Line::Line(const Line& line) : Shape(line), start(line.start), end(line.end) {
            cout << "Line copy constructor called." << endl;
        }

        Line::~Line() {
            cout << "Line destructor called." << endl;
        }

        Line& Line::operator=(const Line& source) {
            if (this == &source) {
                return *this;
            }
            Shape::operator=(source);
            start = source.start;
            end = source.end;
            return *this;
        }

        const Point& Line::Point1() const {
            return start;
        }

        const Point& Line::Point2() const {
            return end;
        }

        void Line::Point1(const Point& start_pt) {
            start = start_pt;
        }

        void Line::Point2(const Point& end_pt) {
            end = end_pt;
        }

        // Call base class ToString() and append to the line's string.
        std::string Line::ToString() const {
            stringstream sstream;
            sstream << Shape::ToString() << ", Line(" << start.ToString() << ", " << end.ToString() << ")";
            return sstream.str();
        }

        double Line::Length() const {
            return start.Distance(end);
        }

        ostream& operator<<(ostream& os, const Line& l) {
            os << l.ToString();
            return os;
        }
    }
}