/*
Testing the point class by 
getting x and y coords. from user. Then we use the getter and setter functions
to assign and retrieve these values. Tostring function outputs the point in string form
Now using distance function
*/
#include "Point.hpp"
#include <iostream>
using namespace std;

int main(){
    double x, y;
    cout<<"Enter the x coordinate: ";
    cin>>x;
    cout<<"\nEnter the y coordinate: ";
    cin>>y;

    //creating an object of the point class
    Point mypoint;
    mypoint.SetX(x);
    mypoint.SetY(y);

    //print output using tostring function
    cout << mypoint.ToString() << endl;
    
    //using getter fn
    cout << "Point(" << mypoint.GetX() << "," << mypoint.GetY() << ")" << endl;

    //create a new point
    Point p2;
    p2.SetX(5.0);
    p2.SetY(10.0);

    //Distance between p1 and origin
    cout << "Distance between origin (0,0) and " << mypoint.ToString() << " is: " << mypoint.DistanceOrigin() << endl;

    //Distance between p1 and p2
    cout<<"Distance between "<<mypoint.ToString()<< " and "<< p2.ToString()<<" is: "<<mypoint.Distance(p2);

    return 0;

}