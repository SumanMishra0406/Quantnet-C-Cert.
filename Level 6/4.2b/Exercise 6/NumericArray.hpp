#ifndef NumericArray_hpp
#define NumericArray_hpp

#include "Array.hpp"
#include "OutOfBoundsException.hpp"

namespace suman {
    namespace Containers {
        
        template <typename T>
        class NumericArray : public Array<T> {
        public:
            // Constructors, Destructor, and Assignment Operator
            NumericArray();
            NumericArray(int size);
            NumericArray(const NumericArray<T> &source);
            ~NumericArray() override;
            NumericArray<T> &operator=(const NumericArray<T> &source);

            // Numeric fn
            NumericArray<T> operator*(const T factor) const;        // Scaling
            NumericArray<T> operator+(const NumericArray<T>& arr2) const; // Addition
            T DotProduct(const NumericArray<T>& arr2) const;          // Dot Product
        };
    }
}

#ifndef NumericArray_cpp 
#include "NumericArray.cpp" 
#endif

#endif