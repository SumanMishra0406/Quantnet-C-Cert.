#ifndef Circle_hpp
#define Circle_hpp
#include "Point.hpp"
#include <iostream>

namespace suman {
    namespace CAD {
        class Circle {
        private:
            Point center;
            double radius;

        public:
            Circle(); //default constructor
            Circle(const Point& new_center, double new_radius); // parameter constructor
            Circle(const Circle& c); // copy constructor
            ~Circle(); //destructor
            Circle& operator = (const Circle& source); // assignment operator

            //Member functions
            Point center_pt() const; //getter function to get center
            double Radius() const; //getter function to get radius

            void center_pt(const Point& update_center); //setter to set the center
            void Radius(double update_radius);

            double Diameter() const;
            double Area() const;
            double Circumference() const;
            std::string ToString() const;
        };
        std::ostream& operator << (std::ostream& os, const Circle& c);
    }
}
#endif