#ifndef PointArray_hpp
#define PointArray_hpp

#include "Array.hpp"
#include "Point.hpp"

namespace suman {
    namespace Containers {
        
        // Concrete inheritance: derives from a fully specialized template
        class PointArray : public Array<CAD::Point> {
        public:
            // Constructors, Destructor, and Assignment Operator
            PointArray();
            PointArray(int size);
            PointArray(const PointArray &source);
            ~PointArray() override;
            PointArray &operator=(const PointArray &source);

            // New specific functionality
            double Length() const;
        };
    }
}

#endif