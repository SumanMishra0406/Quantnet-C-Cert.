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
        template <typename T>
        Stack<T>::Stack() : m_array(), m_current(0)
        {
            // cout << "Stack default constructor" << endl;
        }
        
        // Parameterized Constructor
        template <typename T>
        Stack<T>::Stack(int size) : m_array(size), m_current(0)
        {
            // cout << "Stack parameterized constructor" << endl;
        }

        // Copy Constructor
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

        // Assignment Operator
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


        // Push
        template <typename T>
        void Stack<T>::Push(const T& element)
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
        template <typename T>
        T Stack<T>::Pop()
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