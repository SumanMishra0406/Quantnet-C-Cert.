#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace suman {
    namespace CAD {
        // default constructor
        Line::Line() : start(Point(0.0, 0.0)), end(Point(0.0, 0.0)) {
            std::cout << "Line default constructor" << std::endl;
        }

        // Parameterized constructor
        Line::Line(const Point& start_pt, const Point& end_pt) : start(start_pt), end(end_pt){
            cout << "Line parameter constructor" << endl;
        }

        // Copy constructor
        Line::Line(const Line& line) : start(line.start), end(line.end){
            cout << "Line copy constructor" << endl;
        }

        // Destructor
        Line::~Line(){
            cout << "Line destructor" << endl;
        }

        // Assignment operator
        Line& Line::operator = (const Line& source)
        {
            if (this == &source){
                return *this; //in order to not assign to itself
            }
            start = source.start;
            end = source.end;
            return *this;
        }

        // getter start
        const Point& Line::Point1() const{
            return start;
        }

        // getter end
        const Point& Line::Point2() const{
            return end;
        }

        // setter start
        void Line::Point1(const Point& start_pt){
            start = start_pt;
        }

        // setter end
        void Line::Point2(const Point& end_pt){
            end = end_pt;
        }

        std::string Line::ToString() const{
            stringstream sstream;
            sstream << "Line(" << start.ToString() << ", " << end.ToString() << ")";
            return sstream.str();
        }

        //length by delegating to the Point's Distance function
        double Line::Length() const{
            return start.Distance(end);
        }

        ostream& operator << (ostream& os, const Line& l){
            os << l.ToString();
            return os;
        }
    }
}