#include <iostream>
#include "Line.hpp"
using namespace suman::CAD;
using namespace std;

int main()
{
    Shape s;                           // Create shape.
    Point p(10, 20);                   // Create point.
    Line l(Point(1,2), Point(3, 4));   // Create line.
    
    cout<<s.ToString()<<endl;          // Print shape by calling member function.
    cout<<p.ToString()<<endl;          // Print point by calling member function.
    cout<<l.ToString()<<endl;          // Print line by calling member function.
    
    cout<<"Shape ID: "<<s.ID()<<endl;  // ID of the shape.
    cout<<"Point ID: "<<p.ID()<<endl;  // ID of the point. Does this work?
    // Ans: Yes, it works because Point is derived from the Shape Class and it inherits its public members.

    cout<<"Line ID: "<<l.ID()<<endl;   // ID of the line. Does this work?
    // Ans: Yes, it works for the same reason as the Point object.

    Shape* sp;                         // Create pointer to a shape variable.
    sp = &p;                           // Point in a shape variable. Possible?
    //Ans: Yes, this is polymorphism. A base class pointer can point to a derived class object.

    cout<<sp->ToString()<<endl;        // What is printed? 
    //Ans: ID of the Point p
    delete sp;       

    
    // Create and copy Point p to new point.
    Point p2;
    p2 = p;
    cout<<p2<<", "<<p2.ID()<<endl;     // Is the ID copied if you do not call the base class assignment
                                       // in point? 
    //Ans: The ID will not be copied unless the base class assignment operator is explicitly called 
    //with the Point's assignment operator. 
    //The compiler only generates code to copy the members of the derived class.

    return 0;
}