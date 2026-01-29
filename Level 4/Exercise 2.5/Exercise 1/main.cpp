/*
main.cpp
This file is used to practice 
dynamic memory allocation for single Point objects and arrays of Points.
using new, delete, and delete[].

Author: Suman Mishra
*/
#include "Point.hpp"
#include <iostream>
using namespace std;

int main() {
    // single Point object on the heap.
    Point* pt = new Point; // Using default constructor
    if (pt == nullptr) {
        cout<< "Null Pointer, memory can't be allocated" <<endl;
    } else {
        cout<< "Default constructor point: " << *pt <<endl; //dereference
    }

    //new -> heap memory
    Point* pt1 = new Point(10.0, 12.0);  // Using param constructor 
    if (pt1 == nullptr) {
        cout<< "Memory can't be allocated" <<endl;
    } else {
        cout<< "Parameter constructor point: " << *pt1 <<endl; //deref
    }

    Point* pt3 = new Point(*pt1);  // Using copy constructor 
    if (pt3 == nullptr) {
        cout<< "Memory can't be allocated" <<endl;
    } else {
        cout<< "Copy constructor point: " << *pt3 <<endl;
    }

    // Calculating and printing distances.
    cout<< "Distances: "<<endl;
    cout<< "Distance between pt_1 and pt: " << (*pt1).Distance(*pt) <<endl;

    // Deleting single Point objects
    cout << "Deleting single Point objects: "<<endl;
    delete pt;
    delete pt1;
    delete pt3;

    //Array of Point obj on the heap.
    int size = 0;
    cout << "Enter size of array: ";
    cin >> size;

    // Point* pp[size_array];' would cause a compiler error because
    // arrays on the stack must have their size set at compile time.
    
    Point* p_arr = new Point[size]; // Creating an array of points on the heap
    
    if (p_arr == nullptr) {
        cout << "Memory can't be allocated" <<endl;
    } else {
        cout<< "Printing the array:"<<endl;
        for (int i = 0; i < size; i++) {
            cout<< "p_arr[" << i << "]: " << p_arr[i] <<endl;
        }
		
		cout << "Deleting the array."<<endl;
        delete[] p_arr; //need square brackets
    }

    return 0;
}
