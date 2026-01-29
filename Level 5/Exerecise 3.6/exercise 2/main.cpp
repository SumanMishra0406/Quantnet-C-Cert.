#include "Array.hpp"
#include "Point.hpp"
#include "ArrayException.hpp"
#include <iostream>

using namespace suman::CAD;
using namespace suman::Containers;

int main() {
    Array my_array(5);

    try {
        // access an element at an invalid index.
        std::cout << "Access element at index 10 (error)" << std::endl;
        Point p = my_array.GetElement(10);
        std::cout << "Element at index 10 is: " << p << std::endl;
    }
    catch (const ArrayException& e) {
        // Catch the base class exception
        std::cout << "Caught exception: " << e.GetMessage() << std::endl;
    }
    
    // with [] operator
    try {
        std::cout << "[] operator on an invalid index" << std::endl;
        my_array[10] = Point(10.0, 10.0);
    }
    catch (const ArrayException& e) {
        // Catch the base class exception
        std::cout << "Caught an exception: " << e.GetMessage() << std::endl;
    }
    
    // This should work (no error)
    try {
        std::cout << "[] operator access (no error)" << std::endl;
        my_array[0] = Point(1.0, 1.0);
        std::cout << "Element at index 0 is now: " << my_array[0] << std::endl;
    }
    catch (const ArrayException& e) {
        std::cout << "Caught an exception: " << e.GetMessage() << std::endl; //this won't happen
    }
    
    return 0;
}