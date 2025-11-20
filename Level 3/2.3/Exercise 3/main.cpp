//main.cpp
//Testing function overloading
#include "Point.hpp"
#include <iostream>

int main(){
    double x, y;
    cout<<"Enter the x coordinate: ";
    cin>>x;
    cout<<"Enter the y coordinate: ";
    cin>>y;

    // Use the param constructor with user input
    Point mypoint(x, y);

    //print output using tostring function
    cout << mypoint.ToString() << endl;

    //create a new point
    Point p2;
    p2.X(5.0);
    p2.Y(10.0);

    //Distance between p1 and origin
    cout << "Distance between origin (0,0) and " << mypoint.ToString() << " is: " << mypoint.Distance() << endl;

    //Distance between p1 and p2
    cout<<"Distance between "<<mypoint.ToString()<< " and "<< p2.ToString()<<" is: "<<mypoint.Distance(p2);

    return 0;
}