#include "Line.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

namespace suman {
    namespace CAD {
        // Default constructor
        Line::Line() : start(0.0, 0.0), end(0.0, 0.0){
            cout << "Line default constructor called." << endl;
        }

        // Parameterized constructor
        Line::Line(const Point& start_pt, const Point& end_pt) : start(start_pt), end(end_pt){
            cout << "Line parameterized constructor called." << endl;
        }

        // Copy constructor
        Line::Line(const Line& line) : start(line.start), end(line.end){
            cout << "Line copy constructor called." << endl;
        }

        // Destructor
        Line::~Line(){
            cout << "Line destructor called." << endl;
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


        // Getter for the start point
        const Point& Line::Point1() const{
            return start;
        }

        // Getter for the end point
        const Point& Line::Point2() const{
            return end;
        }

        // Setter for the start point (no const, void return)
        void Line::Point1(const Point& start_pt){
            start = start_pt;
        }

        // Setter for the end point (no const, void return)
        void Line::Point2(const Point& end_pt){
            end = end_pt;
        }

        // Returns a string representation of the line
        std::string Line::ToString() const{
            stringstream sstream;
            sstream << "Line(" << start.ToString() << ", " << end.ToString() << ")";
            return sstream.str();
        }

        // Calculates the length by delegating to the Point's Distance function
        double Line::Length() const{
            return start.Distance(end);
        }

        ostream& operator << (ostream& os, const Line& l){
            os << l.ToString();
            return os;
        }
    }
}