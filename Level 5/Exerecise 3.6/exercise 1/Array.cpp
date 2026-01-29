#include "Array.hpp"
#include <iostream>
using namespace std;
using namespace suman::CAD;

namespace suman
{
    namespace Containers
    {
        // Default constructor creating an array with 10 elements.
        Array::Array() : m_size(10)
        {
            m_data = new Point[m_size];
            cout << "Array default constructor" << endl;
        }

        // Parameterized constructor for an array with a spec. size.
        Array::Array(int size) : m_size(size)
        {
            m_data = new Point[m_size];
            cout << "Array paramter constructor with size " << m_size << endl;
        }

        // Copy constructor to get a deep copy of the source array
        Array::Array(const Array &source)
        {
            m_size = source.m_size;
            m_data = new Point[m_size];

            for (int i = 0; i < m_size; i++)
            {
                m_data[i] = source.m_data[i]; // copy all the points
            }
        }

        Array::~Array()
        {
            delete[] m_data;
            m_data = nullptr;
            cout << "Array destructor" << endl;
        }

        // Assignment operator
        Array &Array::operator=(const Array &source)
        {
            // Check to prevent assignment to itself.
            if (this == &source)
            {
                return *this;
            }

            delete[] m_data; // delete old stuff

            // Allocate new memory and copy the elements source
            m_size = source.m_size;
            m_data = new Point[m_size];
            for (int i = 0; i < m_size; ++i)
            {
                m_data[i] = source.m_data[i];
            }
            cout << "Array assignment operator" << endl;
            return *this;
        }

        // Return the size
        int Array::Size() const
        {
            return m_size;
        }

        // Setter function
        void Array::SetElement(int i, const Point &p)
        {
            if (i >= 0 && i < m_size)
            {
                m_data[i] = p;
            }
            else
            {
                throw -1; // Throws an integer exception for out-of-bounds access
            }
        }

        // Getter fn
        Point &Array::GetElement(int i) const
        {
            if (i < 0 || i >= m_size)
            {
                throw -1; // Throws an integer exception for out-of-bounds access
            }
            return m_data[i];
        }

        Point &Array::operator[](int i){
            if (i < 0 || i >= m_size){
                throw -1; // Throws an integer exception for out-of-bounds access
            }
            return m_data[i];
        }
        const Point &Array::operator[](int i) const{
            if (i < 0 || i >= m_size){
                throw -1; // Throws an integer exception for out-of-bounds access
            }
            return m_data[i];
        }
    }
}