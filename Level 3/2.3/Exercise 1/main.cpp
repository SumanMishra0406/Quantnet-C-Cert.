//main.cpp
/*
Testing the point class by 
getting x and y coords. from user. Then we use the getter and setter functions
to assign and retrieve these values. Tostring function outputs the point in string form
Included 2 distance functions, one for distance from origin and the other for distance
between a point
*/
#include "Point.hpp"
#include <iostream>
using namespace std;

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
    Point p2 (10.0,20.0);
    //Distance between p1 and origin
    cout << "Distance between origin (0,0) and " << mypoint.ToString() << " is: " << mypoint.DistanceOrigin() << endl;

    //Distance between p1 and p2
    cout<<"Distance between "<<mypoint.ToString()<< " and "<< p2.ToString()<<" is: "<<mypoint.Distance(p2);

    return 0;
    /*
    Using parameter constructor:

    Enter the x coordinate: 6
    Enter the y coordinate: 3
    Parameter constructor
    Point(6,3)
    Parameter constructor
    Distance between origin (0,0) and Point(6,3) is: 6.7082
    Distance between Point(6,3) and Point(10,20) is: 
    Copy constructor //<-- copy from  mypoint.Distance(p2) (PBV)
    17.4642
    Destructor
    Destructor
    Destructor

    Parameter constructor count: 2
    Destructor count: 3
    Copy Constructor count: 1

    Output analysis:
    I got an extra copy constructor when calling the distance function
    this occurs because p was passed by value and not by reference. 
    pass by reference would avoid making the copy
    */
}