#include "Point.hpp"
#include <iostream>
using namespace std;

int main() {
    Point p(1.0, 1.0); //param constructor
    
    // Testing the equality operator
    cout << "Testing implicit conversion with if (p == 1.0)"<<endl;
    if (p == 1.0){
        cout << "The points are equal because of implicit conversion." <<endl;
    }else{
        cout << "The points are not equal." <<endl;
    }
    cout <<endl;
    
    /*
    // This is the other way to do the same thing:
    // which would be required if the constructor was declared 'explicit'.
    cout << "Testing explicit conversion if (p == Point(1.0))";
    if (p == Point(1.0)) {
        cout << "The points are equal because of explicit conversion." <<endl;
    }else{
        cout << "The points are not equal." <<endl;
    }
    */

    return 0;
}
