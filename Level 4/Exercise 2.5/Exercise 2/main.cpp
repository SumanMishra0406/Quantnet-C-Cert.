#include "Point.hpp"
#include <iostream>
using namespace std;

//creating an array of Point pointers
//3 elements on the stack
// each element has a point on the heap
//pointer is on the stack, the object with its data and access are on the heap
int main(){
#include "Point.hpp"
#include <iostream>

const int size = 3;
Point** points = new Point*[size];

if(points == nullptr){
    cout<< "memory can't be allocated"<<endl;
}else{
    points[0] = new Point(); //default
    points[1] = new Point(5.0, 10.0); //param
    points[2] = new Point(*points[1]); //copy
    
    for (int i = 0; i < size; ++i){
    cout << *points[i] << endl;
    }
    
    for (int i = 0; i < size; ++i){
    delete points[i];
    }
    
    delete[] points;

}

return 0;

}


    