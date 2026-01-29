#ifndef Line_hpp
#define Line_hpp
#include "Point.hpp"
#include "Shape.hpp"
#include <string>
#include <iostream>

namespace suman {
    namespace CAD {
        class Line : public Shape {
        private:
            suman::CAD::Point start;
            suman::CAD::Point end;

        public:
            Line();
            Line(const suman::CAD::Point& start_pt, const suman::CAD::Point& end_pt);
            Line(const Line& line);
            ~Line();
            Line& operator = (const Line& source);

            const suman::CAD::Point& Point1() const;
            const suman::CAD::Point& Point2() const;

            void Point1(const suman::CAD::Point& start_pt);
            void Point2(const suman::CAD::Point& end_pt);

            std::string ToString() const;
            double Length() const;
        };

        std::ostream& operator << (std::ostream& os, const Line& l);
    }
}
#endif