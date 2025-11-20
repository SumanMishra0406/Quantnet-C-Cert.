#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
using namespace std;

int main() {
    // parameter constructor
    Point start_pt(1.0, 2.0);
    Point end_pt(4.0, 6.0);
    
    Line line1(start_pt, end_pt); //create an object line1
    /*
    When Line line1(start_pt, end_pt) is executed, 
    the Line's parameterized constructor is called. 
    This constructor copies start_pt and end_pt into line1's member variables
    which causes the Point copy constructor twice (once for each point).
    */

    cout << "Line 1: " << line1.ToString() << endl;
    cout << "Length of line 1: " << line1.Length() << endl;
    cout << "Start of line 1: " << line1.Point1().ToString() << endl;
    cout << "End of line 1: " << line1.Point2().ToString() << endl;

    // Test the default constructor and setters
    // The code below calls the Line default constructor, and the 
    // default line constructor uses a parametrized point constructor
    // so parameter constructor will be called twice
    // then it will call line default constructor
    Line line2; // Calls default constructor
    cout << "\nLine 2 using default constructor: " << line2.ToString() << endl;

    Point new_start(10.0, 10.0);
    Point new_end(20.0, 20.0);
    
    line2.Point1(new_start); // Use the setter
    line2.Point2(new_end);   // Use the setter

    cout << "Line 2 updated: " << line2.ToString() << endl;
    cout << "Length of line 2: " << line2.Length() << endl;
    
    // Test the copy constructor
    Line line3 = line1; // Calls copy constructor
    cout << "\nLine 3 created as a copy of line 1: " << line3.ToString() << endl;

    return 0;
}