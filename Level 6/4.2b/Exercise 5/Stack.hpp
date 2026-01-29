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
            int m_current; 

        public:
            // Constructors, Destructor, and Assignment Operator
            Stack();
            Stack(int size); 
            Stack(const Stack<T> &source);
            ~Stack();
            Stack<T> &operator=(const Stack<T> &source);

            // Stack functionality
            void Push(const T& element);
            T Pop();
        };
    }
}

#ifndef Stack_cpp
#include "Stack.cpp" 
#endif


#endif