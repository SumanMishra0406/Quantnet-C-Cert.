#define Stack_cpp 
#include "Stack.hpp"
#include "StackException.hpp"
#include <iostream>

using namespace std;

namespace suman
{
    namespace Containers
    {
        // Default Constructor
        template <typename T, int size> // included int
        Stack<T, size>::Stack() : m_array(size), m_current(0) // initialize Array with 'size'
        {
            // cout << "Stack default constructor" << endl;
        }
        
        //removed param. constructor
        
        // Copy Constructor: need to use Stack<T, size>
        template <typename T, int size>
        Stack<T, size>::Stack(const Stack<T, size> &source)
            : m_array(source.m_array), m_current(source.m_current)
        {
            // cout << "Stack copy constructor" << endl;
        }

        // Destructor - need to change signature
        template <typename T, int size>
        Stack<T, size>::~Stack()
        {
            // cout << "Stack destructor" << endl;
        }

        // Assignment Operator
        template <typename T, int size>
        Stack<T, size> &Stack<T, size>::operator=(const Stack<T, size> &source)
        {
            if (this == &source) {
                return *this;
            }
            // The size must be the same due to the template argument 
            // This is automatically done
            m_array = source.m_array; 
            m_current = source.m_current;
            return *this;
        }

        // Push
        template <typename T, int size>
        void Stack<T, size>::Push(const T& element)
        {
            try {
                m_array[m_current] = element; 
                m_current++; 
            }
            catch (const ArrayException& e) { 
                throw StackFullException(); 
            }
        }

        // Pop
        template <typename T, int size>
        T Stack<T, size>::Pop()
        {
            if (m_current == 0) {
                throw StackEmptyException(); 
            }

            m_current--; 

            try {
                return m_array[m_current];
            }
            catch (const ArrayException& e) {
                m_current = 0;
                throw StackEmptyException(); 
            }
        }
    }
}