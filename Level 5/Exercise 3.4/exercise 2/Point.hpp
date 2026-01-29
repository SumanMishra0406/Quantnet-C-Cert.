#ifndef Point_hpp
#define Point_hpp
#include <string>
#include <iostream>
#include "Shape.hpp" // Inherit from Shape

namespace suman {
    namespace CAD {
        class Point : public Shape {
        private:
            double x, y;

        public:
            Point();
            Point(double x_val, double y_val);
            Point(const Point& p);
            ~Point();

            double X() const;
            double Y() const;

            void X(double X);
            void Y(double Y);

            std::string ToString() const;

            double Distance() const;
            double Distance(const Point& p) const;

            // Operator Overloading
            Point operator - () const;
            Point operator * (double factor) const;
            Point operator + (const Point& p) const;
            bool operator == (const Point& p) const;
            Point& operator = (const Point& source);
            Point& operator *= (double factor);
            
            friend std::ostream& operator << (std::ostream& os, const Point& p);
        };
    }
}
#endif