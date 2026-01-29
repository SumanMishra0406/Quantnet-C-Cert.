#ifndef Stack_hpp
#define Stack_hpp

#include "Array.hpp"
#include "ArrayException.hpp"

namespace suman {
    namespace Containers {
        
        template <typename T>
        class Stack {
        private:
            Array<T> m_array; 
            // Current index points to the next available space (or is = size if full)
            int m_current; 

        public:
            // Constructors, Destructor, and Assignment Operator
            // Stack size is determined by Array's default size or constructor size
            Stack();
            Stack(int size); 
            Stack(const Stack<T> &source);
            ~Stack();
            Stack<T> &operator=(const Stack<T> &source);

            // Stack fns
            void Push(const T& element);
            T Pop();
        };
    }
}

#ifndef Stack_cpp
#include "Stack.cpp" 
#endif


#endif