#include <iostream>
#include <vector>
#include <algorithm>
#include "smaller_than_n.hpp"
using namespace std;

int main() {
    // Container of doubles to test
    vector<double> data = {10.0, 20.0, 15.5, 80.0, 5.0, 45.0};
    cout << "Data Vector: ";
    for (double v : data) {
        cout << v << " ";
    }
    cout<<endl;

    //Using the Global Function with count_if
    
    cout << "Using Global Function (IsSmallerThanThirty)" << endl;
    // The global function checks with 30 (hardcoded)
    int count_global = count_if(data.begin(), data.end(), IsSmallerThanThirty);
    cout << "Count of elements smaller than 30.0: " << count_global << endl;
    cout<<endl;

    // Using the Functor (Function Object) with count_if
    cout << "Using Functor (IsSmallerThanN)" << endl;

    // <50
    IsSmallerThanN smaller_than_fifty(50.0);
    // Pass the functor instance to count_if
    int count_functor = count_if(data.begin(), data.end(), smaller_than_fifty);
    cout << "Count of elements smaller than 50.0: " << count_functor <<endl;

    //<20
    IsSmallerThanN smaller_than_twenty(20.0);
    // Use the second functor.
    int count_functor_2 = count_if(data.begin(), data.end(), smaller_than_twenty);
    cout << "Count of elements smaller than 20.0: " << count_functor_2 << endl;

    return 0;
}