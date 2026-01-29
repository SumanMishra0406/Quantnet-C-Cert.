#ifndef Circle_hpp
#define Circle_hpp
#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>

namespace suman {
    namespace CAD {
        class Circle : public Shape {
        private:
            Point center;
            double radius;

        public:
            Circle();
            Circle(const Point& new_center, double new_radius);
            Circle(const Circle& c);
            ~Circle();
            Circle& operator = (const Circle& source);

            Point center_pt() const;
            double Radius() const;

            void center_pt(const Point& update_center);
            void Radius(double update_radius);

            double Diameter() const;
            double Area() const;
            double Circumference() const;
            std::string ToString() const override;
            //Draw() function.
            void Draw() override;
        };
        std::ostream& operator << (std::ostream& os, const Circle& c);
    }
}
#endif