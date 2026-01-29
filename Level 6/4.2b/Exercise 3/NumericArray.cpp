#define NumericArray_cpp 
#include "NumericArray.hpp"
#include <iostream>
#include "OutOfBoundsException.hpp" 
using namespace std;

namespace suman
{
    namespace Containers
    {
        // Default Constructor -> Call base class default constructor
        template <typename T>
        NumericArray<T>::NumericArray() : Array<T>()
        {
            // cout << "NumericArray default constructor" << endl;
        }

        // Parameterized Constructor -> Call base class parameterized constructor
        template <typename T>
        NumericArray<T>::NumericArray(int size) : Array<T>(size)
        {
            // cout << "NumericArray parameterized constructor" << endl;
        }

        // Copy Constructor -> Call base class copy constructor
        template <typename T>
        NumericArray<T>::NumericArray(const NumericArray<T> &source) : Array<T>(source)
        {
            // cout << "NumericArray copy constructor" << endl;
        }
        
        // Destructor
        template <typename T>
        NumericArray<T>::~NumericArray()
        {
            // cout << "NumericArray destructor" << endl;
        }

        // Assignment Operator -> Use base class assignment operator
        template <typename T>
        NumericArray<T> &NumericArray<T>::operator=(const NumericArray<T> &source)
        {
            // Use the base class assignment operator for deep copy and size handling
            Array<T>::operator=(source); 
            // cout << "NumericArray assignment operator" << endl;
            return *this;
        }


        // Operator* (Scaling)
        template <typename T>
        NumericArray<T> NumericArray<T>::operator*(const T factor) const
        {
            NumericArray<T> result(this->Size()); 
            
            for (int i = 0; i < this->Size(); ++i) {
                // Use the base class's operator[] for easy access
                result[i] = (*this)[i] * factor; 
            }
            return result;
        }

        // Operator+
        template <typename T>
        NumericArray<T> NumericArray<T>::operator+(const NumericArray<T>& arr2) const
        {
            int size1 = this->Size();
            int size2 = arr2.Size();

            if (size1 != size2) {
                throw OutOfBoundsException(-1);
            }

            NumericArray<T> result(size1);

            for (int i = 0; i < size1; ++i) {
                result[i] = (*this)[i] + arr2[i];
            }
            return result;
        }

        // DotProduct
        template <typename T>
        T NumericArray<T>::DotProduct(const NumericArray<T>& arr2) const
        {
            int size1 = this->Size();
            int size2 = arr2.Size();

            if (size1 != size2) {
                throw OutOfBoundsException(-1);
            }

            T sum = 0;
            for (int i = 0; i < size1; ++i) {
                sum = sum + ((*this)[i] * arr2[i]);
            }

            return sum;
        }

    }
}