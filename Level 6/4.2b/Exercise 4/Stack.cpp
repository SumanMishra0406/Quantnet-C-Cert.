#define Stack_cpp 
#include "Stack.hpp"
#include <iostream>

using namespace std;

namespace suman
{
    namespace Containers
    {
        // Default Constructor: Uses Array's default size, starts empty
        template <typename T>
        Stack<T>::Stack() : m_array(), m_current(0)
        {
            // cout << "Stack default constructor" << endl;
        }
        
        // Parameterized Constructor: initialize internal array size
        template <typename T>
        Stack<T>::Stack(int size) : m_array(size), m_current(0)
        {
            // cout << "Stack parameterized constructor" << endl;
        }

        // Copy Constructor: uses Array's copy constructor
        template <typename T>
        Stack<T>::Stack(const Stack<T> &source) 
            : m_array(source.m_array), m_current(source.m_current)
        {
            // cout << "Stack copy constructor" << endl;
        }

        // Destructor
        template <typename T>
        Stack<T>::~Stack()
        {
            // cout << "Stack destructor" << endl;
        }

        // Assignment Operator: uses Array's assignment operator
        template <typename T>
        Stack<T> &Stack<T>::operator=(const Stack<T> &source)
        {
            if (this == &source) {
                return *this;
            }
            m_array = source.m_array;
            m_current = source.m_current;
            return *this;
        }


        // Push: Adds an element to the stack
        template <typename T>
        void Stack<T>::Push(const T& element)
        {
            // Check if m_current is within bounds of the Array (Array::Size())
            // If m_current == Array::Size(), the array is full.
            
            // Delegation: Use Array's SetElement or operator[]
            // Array::operator[] will throw OutOfBoundsException if m_current is too high.
            
            try {
                m_array[m_current] = element; //store the element at m_current
                m_current++; //m_current now points to the next available space
            }
            catch (const ArrayException& e) {
                throw; 
            }
        }

        // Pop: Retrieves and removes the top element
        template <typename T>
        T Stack<T>::Pop()
        {
            if (m_current == 0) { //Check if the stack is empty
                throw OutOfBoundsException(-2); // Use -2 for a special empty stack
            }
            m_current--; 

            //Retrieve the element at the new m_current index
            return m_array[m_current]; // Array::operator[] can still throw error if m_current is < 0, but the if stmt
            //prevents this
        }

    }
}