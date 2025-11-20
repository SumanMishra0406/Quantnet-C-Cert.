/*
Testing the point class by 
getting x and y coords. from user. Then we use the getter and setter functions
to assign and retrieve these values. Tostring function outputs the point in string form

*/
#include "Point.hpp" // Includes the header file for the Point class
#include <iostream>  // For standard input and output (cin, cout)
using namespace std; // avoid the std::

int main(){
    double x, y;
    cout<<"Enter the x coordinate: ";
    cin>>x;
    cout<<"\nEnter the y coordinate: ";
    cin>>y;

    //creating an object of the point class
    Point p1; //default constructor sets point at origin (0,0)
    p1.SetX(x); //change point using setter function
    p1.SetY(y);

    //print output using tostring function
    cout << p1.ToString() << endl;
    
    //using getter fn
    cout << "Point(" << p1.GetX() << "," << p1.GetY() << ")" << endl;

    return 0;

    /*
    Output:
    g++ Point.cpp main.cpp -o testing
    ./testing

    Enter the x coordinate: 20
    Enter the y coordinate: 10
    Point(20,10)
    Point(20,10)
    Bye my point...    
    */
}