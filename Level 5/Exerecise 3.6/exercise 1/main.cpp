#include "Array.hpp"
#include "Point.hpp"
#include <iostream>

using namespace suman::CAD;
using namespace suman::Containers;

int main() {
    Array arr(5);

    try {
        // access an element at an invalid index
        std::cout << "Try to access element at index 10" << std::endl;
        Point p = arr.GetElement(10);
    }
    catch (int error) {
        if (error == -1) {
            std::cout << "Out of bounds error" << std::endl;
        }
    }
    
    // with the [] operator
    try {
        std::cout << "[] operator on invalid index" << std::endl;
        arr[10] = Point(30.0, 40.0);
    }
    catch (int error) {
        if (error == -1) {
            std::cout << "Out of bounds error" << std::endl;
        }
    }
    
    //to check in case of no error
    try {
        std::cout << "[] operator access (correct version - should not throw error)" << std::endl;
        arr[0] = Point(1.0, 1.0);
        std::cout << "Element at index 0 is: " << arr[0] << std::endl;
    }
    catch (int error) {
        // This catch block will not happen
        std::cout << "Caught an exception: " << error << std::endl;
    }
    
    return 0;
}