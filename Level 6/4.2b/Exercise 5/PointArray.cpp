#define PointArray_cpp
#include "PointArray.hpp"
#include <iostream>
#include <cmath>

using namespace suman::CAD;
using namespace std;

namespace suman
{
    namespace Containers
    {
        // Default Constructor
        PointArray::PointArray() : Array<Point>()
        {
            // cout << "PointArray default constructor" << endl;
        }

        // Parameterized Constructor
        PointArray::PointArray(int size) : Array<Point>(size)
        {
            // cout << "PointArray parameterized constructor" << endl;
        }

        // Copy Constructor
        PointArray::PointArray(const PointArray &source) : Array<Point>(source)
        {
            // cout << "PointArray copy constructor" << endl;
        }
        
        // Destructor
        PointArray::~PointArray()
        {
            // cout << "PointArray destructor" << endl;
        }

        // Assignment Operator
        PointArray &PointArray::operator=(const PointArray &source)
        {
            Array<Point>::operator=(source); 
            // cout << "PointArray assignment operator" << endl;
            return *this;
        }

        // Length() fn
        double PointArray::Length() const
        {
            double total_l = 0.0;
            int size = this->Size(); // Use inherited Size() method

            // Need at least 2 points
            if (size <= 1) {
                return 0.0;
            }

            for (int i = 0; i < size - 1; ++i) {
                Point p1 = (*this)[i];
                Point p2 = (*this)[i+1];
                
                total_l += p1.Distance(p2);
            }
            
            return total_l;
        }
    }
}