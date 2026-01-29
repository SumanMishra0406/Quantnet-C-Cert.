#ifndef Line_hpp
#define Line_hpp
#include "Point.hpp"
#include "Shape.hpp"
#include <string>

namespace suman {
    namespace CAD {
        class Line : public Shape {
        private:
            Point start;
            Point end;

        public:
            Line();
            Line(const Point& start_pt, const Point& end_pt);
            Line(const Line& line);
            ~Line();

            Line& operator=(const Line& source);

            const Point& Point1() const;
            const Point& Point2() const;

            void Point1(const Point& start_pt);
            void Point2(const Point& end_pt);

            std::string ToString() const;

            double Length() const;

            friend std::ostream& operator<<(std::ostream& os, const Line& l);
        };
    }
}
#endif