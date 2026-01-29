#include "Array.hpp"
#include "Point.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>

using namespace std;
using namespace suman::Containers;
using namespace suman::CAD;

int main() {
    cout << "Testing Array<Point>: " << endl;
    int size = 3;
    
    // creating an array of Point objects
    Array<Point> points(size); 
    //set pts
    points[0] = Point(1.0, 2.0);
    points[1] = Point(3.0, 4.0);
    
    // using set element
    Point p(5.0, 6.0);
    points.SetElement(2, p);

    cout << "Element at index 1: " << points[1].ToString() << endl;
    cout << "Array size: " << points.Size() << endl;

    //array of doubles
    cout << "\nTesting Array<double>:" << endl;
    Array<double> doubles(5);
    doubles[0] = 3.14;
    doubles[4] = 1.1;
    
    cout << "Double array element at index 4: " << doubles[4] << endl;

    // test exception handling
    cout << "\n Testing Exception Handling: "<< endl;
    try {
       //out of bounds
        double value = doubles[5]; 
        cout << "Value (shouldn't work): " << value << endl;
    } 
    catch (const OutOfBoundsException& e) {
        cout << "Caught exception: " << e.GetMessage() << endl;
    }
    catch (const ArrayException& e) {
        cout << "Caught generic array exception: " << e.GetMessage() << endl;
    }
    catch (...) {
        cout << "Caught unknown exception." << endl;
    }

    return 0;
}