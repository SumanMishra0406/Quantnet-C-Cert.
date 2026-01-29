#ifndef PointArray_hpp
#define PointArray_hpp

#include "Array.hpp"
#include "Point.hpp"

namespace suman {
    namespace Containers {
        
        class PointArray : public Array<CAD::Point> {
        public:
            // Constructors, Destructor, and Assignment Operator
            PointArray();
            PointArray(int size);
            PointArray(const PointArray &source);
            ~PointArray() override;
            PointArray &operator=(const PointArray &source);

            double Length() const;
        };
    }
}

#endif