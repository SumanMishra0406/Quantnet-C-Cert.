#include "Point.hpp"
#include <iostream>
using namespace std;

int main(){
    // Test Ostream on Point class
    Point pt(5.0, 10.0);
    cout << pt.ToString() << endl; //using ToString
    cout << pt << endl; //ostream << to print
    
    return 0;
}