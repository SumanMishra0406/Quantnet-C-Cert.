/*Testing the array class functions*/
#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
using namespace std;

int main() {
    Array default_arr;
    cout << "array size: "<<default_arr.Size() << endl;
    
    Array param_arr(5);
    Point p1(10.0, 20.0);
    Point p2(5.0, 6.0);
    param_arr.SetElement(0, p1); // index 0
    Point p3 = param_arr[0]; // [] operator
    cout<<"[] operator point p3: "<< p3 <<endl;
    param_arr[1] = p3; //non const [] operator
    param_arr.SetElement(2, p2); // index 2
    cout << "Parameter constructor array size: " << param_arr.Size() << endl;
    for (int i = 0; i < param_arr.Size(); ++i) {
        cout << "index "<< i << ": " << param_arr.GetElement(i) << endl;
    }
    
    Array copied_arr(param_arr);
    cout << "Copy constructor array size: " << copied_arr.Size() << endl;
    for (int i = 0; i < copied_arr.Size(); ++i) {
        cout << "index "<< i << ": " << copied_arr.GetElement(i) << endl;
    }

    Array assigned_arr; // Using default constructor
    assigned_arr = param_arr; // assignment operator
    cout << "Assignment operator array size: " << assigned_arr.Size() << endl;
    for (int i = 0; i < assigned_arr.Size(); ++i) {
         cout << "index "<< i << ": " << assigned_arr.GetElement(i) << endl;
    }
    return 0;
}