#include "Array.hpp"
#include <iostream>

using namespace suman::Containers; 
using namespace std;

int main() {
    try {
        Array<int> intArray1;
        Array<int> intArray2;
        Array<double> doubleArray;

        cout << "Initial Default Sizes (should be 10)" << endl;
        cout << "intArray1 DefaultSize: " << intArray1.DefaultSize() << endl; 
        cout << "intArray2 DefaultSize: " << intArray2.DefaultSize() << endl;
        cout << "doubleArray DefaultSize: " << doubleArray.DefaultSize() << endl;

        //Change the static default size
        intArray1.DefaultSize(15); 

        cout << "\nSizes After Change (int should be 15, double stays 10)" << endl;
        cout << "intArray1 DefaultSize: " << intArray1.DefaultSize() << endl; 
        // intArray2 is also Array<int>, so it shares the new static value (15)
        cout << "intArray2 DefaultSize: " << intArray2.DefaultSize() << endl; 
        // doubleArray is Array<double>, so it has a separate static value (10)
        cout << "doubleArray DefaultSize: " << doubleArray.DefaultSize() << endl; 

    } catch (const ArrayException& e) {
        cout << "Caught an Array Exception: " << e.GetMessage() << endl;
    }

    return 0;
}