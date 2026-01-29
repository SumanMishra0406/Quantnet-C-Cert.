#ifndef Array_hpp
#define Array_hpp

namespace suman {
    namespace Containers {
        template <typename T>
        class Array {
        private:
            T *m_data;
            int m_size;

        public:
            Array(); // Default constructor
            Array(int size); // Param. constructor
            // used Array<T> for copy constructor param
            Array(const Array<T> &source);         // Copy constructor
            ~Array();                              // Destructor
            //used Array<T> for assignment operator param. and return type
            Array<T> &operator=(const Array<T> &source); // Assignment operator

            int Size() const; //size of array
            
            void SetElement(int i, const T &p); // Setter
            T &GetElement(int i) const;         // Getter
            T &operator[](int i);               // [] operator
            const T &operator[](int i) const;   // const [] operator
        };

    }
}
#endif

// Tip: Include the source file for template linkage.
// Ans: This allows the compiler to see the template implementation
#ifndef Array_cpp 
#include "Array.cpp" 
#endif