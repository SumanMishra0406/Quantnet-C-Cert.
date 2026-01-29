#define Array_cpp 
#include "Array.hpp" 
#include <iostream>
#include "OutOfBoundsException.hpp" 
using namespace std;

namespace suman
{
    namespace Containers
    {
        template <typename T>
        int Array<T>::m_defaultSize = 10; 
        
        // Default constructor (using static size)
        template <typename T>
        Array<T>::Array() : m_size(m_defaultSize) 
        {
            m_data = new T[m_size]; 
            cout << "Array default constructor" << endl;
        }

        //static getter
        template <typename T>
        int Array<T>::DefaultSize() {
            return m_defaultSize;
        }

        //static setter
        template <typename T>
        void Array<T>::DefaultSize(int size) {
            m_defaultSize = size;
        }


        // Parameterized constructor
        template <typename T>
        Array<T>::Array(int size) : m_size(size)
        {
            m_data = new T[m_size];
            cout << "Array param. constructor with size " << m_size << endl;
        }

        // Copy constructor
        template <typename T>
        Array<T>::Array(const Array<T> &source)
        {
            m_size = source.m_size;
            m_data = new T[m_size];

            for (int i = 0; i < m_size; i++)
            {
                m_data[i] = source.m_data[i];
            }
        }

        // Destructor
        template <typename T>
        Array<T>::~Array() 
        {
            delete[] m_data;
            m_data = nullptr;
            cout << "Array destructor" << endl;
        }

        // Assignment operator
        template <typename T>
        Array<T> &Array<T>::operator=(const Array<T> &source)
        {
            if (this == &source)
            {
                return *this;
            }

            delete[] m_data;

            m_size = source.m_size;
            m_data = new T[m_size];
            for (int i = 0; i < m_size; ++i)
            {
                m_data[i] = source.m_data[i];
            }
            cout << "Array assignment operator" << endl;
            return *this;
        }

        // Size
        template <typename T>
        int Array<T>::Size() const
        {
            return m_size;
        }

        // Setter function
        template <typename T>
        void Array<T>::SetElement(int i, const T &p) 
        {
            if (i >= 0 && i < m_size)
            {
                m_data[i] = p;
            }
            else
            {
                throw OutOfBoundsException(i);
            }
        }

        // Getter fn
        template <typename T>
        T &Array<T>::GetElement(int i) const 
        {
            if (i < 0 || i >= m_size)
            {
                throw OutOfBoundsException(i);
            }
            return m_data[i];
        }

        // Non-const operator[]
        template <typename T>
        T &Array<T>::operator[](int i){
            if (i < 0 || i >= m_size){
                throw OutOfBoundsException(i);
            }
            return m_data[i];
        }
        
        // Const operator[]
        template <typename T>
        const T &Array<T>::operator[](int i) const{
            if (i < 0 || i >= m_size){
                throw OutOfBoundsException(i);
            }
            return m_data[i];
        }
    }
}