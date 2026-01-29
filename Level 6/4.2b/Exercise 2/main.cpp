#include "NumericArray.hpp"
#include <iostream>

using namespace suman::Containers;
using namespace std;

int main() {
    try {
        NumericArray<double> arrA(3);
        NumericArray<double> arrB(3);
        
        arrA[0] = 1.0; arrA[1] = 2.0; arrA[2] = 3.0;
        arrB[0] = 4.0; arrB[1] = 5.0; arrB[2] = 6.0;

        cout << "Array A: [1.0, 2.0, 3.0]" << endl;
        cout << "Array B: [4.0, 5.0, 6.0]" << endl;
        
        cout<<endl;

        // Test DotProduct
        double dot_product = arrA.DotProduct(arrB);
        // Ans: (1*4) + (2*5) + (3*6) = 4 + 10 + 18 = 32
        cout << "1. Dot Product (A * B): " << dot_product << endl; 
        
        // Test Operator +
        NumericArray<double> arrC = arrA + arrB;
        // Ans: [5.0, 7.0, 9.0]
        cout << "2. Array C (A + B): [" << arrC[0] << ", " << arrC[1] << ", " << arrC[2] << "]" << endl;

        // Test Operator*
        NumericArray<double> arrD = arrA * 2.5;
        // Ans: [2.5, 5.0, 7.5]
        cout << "3. Array D (A * 2.5): [" << arrD[0] << ", " << arrD[1] << ", " << arrD[2] << "]" << endl;

        // Test Exception
        cout << "\n4. Testing Size diff. Exception for Addition..." << endl;
        NumericArray<double> arrE(5); // Size 4
        try {
            NumericArray<double> arrF = arrA + arrE; // arrA is size 3
        } catch (const ArrayException& e) {
            cout << "Caught exception: " << e.GetMessage() << endl;
        }

    } catch (const std::exception& e) {
        cout << "Caught exception (standard): " << e.what() << endl;
    } catch (...) {
        cout << "An unknown exception occurred." << endl;
    }

    return 0;
}