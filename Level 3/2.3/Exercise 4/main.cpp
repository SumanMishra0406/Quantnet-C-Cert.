/*
This exercise demonstrates using const
to prevent accidental data modification
*/
//main.cpp

#include "Point.hpp"
#include <iostream>

int main(){
    const Point cp(1.5,3.9);   // Create a const point

    // This will work because tostring is a const function
    // The getter X() and Y() will also work because we aren't modifying the values
    // when we add const after function signature (defined in point.cpp)
    //Otherwise, if we don't add const, X() and Y() will not work.
    //and the functions are also const
    cout << "Const Point is at: " << cp.ToString() << endl;

    // cp.X(0.3); will cause compiler error

  /*
  
  The cp object is declared as const Point, which means the compiler guarantees 
  that x and y will not be changed after initialization.
  The SetX function is used to modify x
  The compiler sees this as a violation of const and prevents the code from compiling.
  To make the code compile, we can:
  1.  Remove  const from the cp object: Point cp(1.5, 3.9)
  2.  Or remove // cp.SetX(0.3)
  */
    return 0;
}