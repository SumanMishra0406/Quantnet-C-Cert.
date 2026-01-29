#ifndef Line_hpp
#define Line_hpp
#include "Point.hpp"
#include <string>
#include <iostream>

namespace suman {
    namespace CAD {
        class Line {
        private:
            suman::CAD::Point start; //  this is aggregation (has-a relationship)
            suman::CAD::Point end;

        public:
            // Default constructor
            Line();
            // Start and end point constructor
            Line(const suman::CAD::Point& start_pt, const suman::CAD::Point& end_pt);
            // Copy constructor
            Line(const Line& line);
            // Destructor
            ~Line();
            //assignment operator
            Line& operator = (const Line& source);

            // Getter
            const suman::CAD::Point& Point1() const; //start
            const suman::CAD::Point& Point2() const; //end

            // Setter functions
            void Point1(const suman::CAD::Point& start_pt);
            void Point2(const suman::CAD::Point& end_pt);

            std::string ToString() const;
            double Length() const;
        };

        std::ostream& operator << (std::ostream& os, const Line& l);
    }
}
#endif