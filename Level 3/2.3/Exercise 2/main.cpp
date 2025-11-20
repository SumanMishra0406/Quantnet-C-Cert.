//main.cpp
//Testing PBR on Distance function
#include "Point.hpp"
#include <iostream>

int main(){
    double x, y;
    cout<<"Enter the x coordinate: ";
    cin>>x;
    cout<<"Enter the y coordinate: ";
    cin>>y;

    // Use the parameter constructor with user input
    Point mypoint(x, y);

    //print output using tostring function
    cout << mypoint.ToString() << endl;

    //create a new point
    Point p2; //default constructor
    p2.SetX(5.0);
    p2.SetY(10.0);

    //Distance between p1 and origin
    cout << "Distance between origin (0,0) and " << mypoint.ToString() << " is: " << mypoint.DistanceOrigin() << endl;

    //Distance between p1 and p2
    cout<<"Distance between "<<mypoint.ToString()<< " and "<< p2.ToString()<<" is: "<<mypoint.Distance(p2);

    return 0;
    /*
    Output
    Enter the x coordinate: 10
    Enter the y coordinate: 20
    Parameter constructor
    Point(10,20)
    Default constructor
    Distance between origin (0,0) and Point(10,20) is: 22.3607
    Distance between Point(10,20) and Point(5,10) is: 11.1803
    Destructor
    Destructor


    Output analysis:
    There are 2 destructor calls which are expected and show "pass by reference"
    The number of destructor calls are the same as the number of constructors
    1. Default Constructor: Called for p2
    The 2 destructors proves that there wasn't a copy created 
    */
}