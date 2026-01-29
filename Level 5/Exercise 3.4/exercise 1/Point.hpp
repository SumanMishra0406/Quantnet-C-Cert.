//Point.hpp
/* Point Class Header file
The point class contains coordinates (x,y)
Includes Functions that create points, accessing and modifying the coordinates
and calculate the distance between the point and origin or between two points

Included operators
*/
#ifndef Point_hpp
#define Point_hpp
#include <string>
#include <iostream>

namespace suman {
    namespace CAD {

        class Point{
        private:
            double x,y;

        public:
            Point();
            Point(double x_val, double y_val); // param constructor
            Point(const Point& p); //copy constructor
            ~Point();

            double X() const;
            double Y() const;

            void X(double X);
            void Y(double Y);

            std::string ToString() const;

            double Distance() const;
            double Distance(const Point& p) const; // pass by reference

            //Operator Overloading
            Point operator - () const; // Negate the coordinates.
            Point operator * (double factor) const; // Scale the coordinates.
            Point operator + (const Point& p) const; // Add coordinates.
            bool operator == (const Point& p) const; // Equally compare operator.
            Point& operator = (const Point& source); // Assignment operator.
            Point& operator *= (double factor); // Scale the coordinates & assign.
            
            friend std::ostream& operator << (std::ostream& os, const Point& p);

        };
    } 
}

#endif