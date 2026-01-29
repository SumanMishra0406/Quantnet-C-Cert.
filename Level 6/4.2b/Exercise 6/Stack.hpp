#ifndef Stack_hpp
#define Stack_hpp

#include "Array.hpp"
#include "ArrayException.hpp"

namespace suman {
    namespace Containers {
        
        template <typename T, int size>
        class Stack {
        private:
            Array<T> m_array; 
            int m_current; 

        public:
            Stack(); // don't need Stack(int size);
            
            Stack(const Stack<T, size> &source); // need to use Stack<T, size> for copy constructor
            ~Stack();
            
            Stack<T, size> &operator=(const Stack<T, size> &source); //same here

            void Push(const T& element);
            T Pop();
        };
    }
}

#ifndef Stack_cpp
#include "Stack.cpp" 
#endif

#endif