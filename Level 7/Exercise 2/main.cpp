#include "sum.hpp"
#include <list>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    list<double> price_list = {1.1, 2.2, 3.3, 4.4};
    vector<double> scores = {10.0, 20.0, 30.0, 40.0};
    
    // Maps store pairs, so Sum will correctly call the template specialization 
    // to add the second part of the pair
    map<string, double> price_map = {
        {"apple", 1.00},
        {"banana", 2.00},
        {"cherry", 5.00}
    };

    cout << "Sum(container): " <<endl;
    
    // Call Sum() for the different containers (Full Container Sum)
    // List and Vector use the generic template. Map uses the specialization.
    double list_sum = Sum(price_list);
    cout << "Sum of list: " << list_sum << endl;

    double vector_sum = Sum(scores);
    cout << "Sum of vector: " << vector_sum << endl;

    double map_sum = Sum(price_map);
    cout << "Sum of map (values only): " << map_sum << endl; 

    cout << "2: Partial Sum between iterators: Sum(start_it, end_it)" << endl;
    
    // List: Sum of first two elements (1.1, 2.2)
    list<double>::iterator list_end_it = price_list.begin();

    ++list_end_it; // Points to 2.2 
    ++list_end_it; // Points to 3.3
    
    double partial_list_sum = Sum(price_list.begin(), list_end_it);
    cout << "Partial sum of list (1.1 + 2.2): " << partial_list_sum << endl;
    
    //Vector: Sum of elements from index 1 (20.0) up to index 3 (40.0, exclusive)
    vector<double>::iterator vec_start = scores.begin() + 1; // Iterator to 20.0, index 1
    vector<double>::iterator vec_end = scores.begin() + 3;   // Iterator to 40.0, index 3, exclusive
    double partial_vec_sum = Sum(vec_start, vec_end);
    cout << "Partial sum of vector (20.0 + 30.0): " << partial_vec_sum << endl; 
    
    // Map: Sum of first two elements (apple + banana)
    map<string, double>::iterator map_end_it = price_map.begin();
    
    ++map_end_it; // Points to "banana", 2.00
    ++map_end_it; // Points to "cherry", 5.00 ('end' iterator, exclusive)
    
    double partial_map_sum = Sum(price_map.begin(), map_end_it);
    cout << "Partial sum of map (apple + banana): " << partial_map_sum << endl;
    

    return 0;
}