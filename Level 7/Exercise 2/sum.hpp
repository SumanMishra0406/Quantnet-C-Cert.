#ifndef SUM_HPP
#define SUM_HPP

#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <list>
#include <string>
using namespace std;


// Primary Template: Sum of the complete container (works for list<double>, vector<double>)
template <typename T>
double Sum(const T& container) {
    double total_sum = 0.0;

    // Get the constant iterator for the end of the container
    typename T::const_iterator end_it = container.end();

    // Iterate the container and + values
    for (typename T::const_iterator it = container.begin(); it != end_it; ++it) {
        total_sum += *it;
    }

    return total_sum;
}

// Template Specialization
// overrides the primary template for std::map<string, double>
template <>
double Sum(const map<string, double>& map_container) {
    double total_sum = 0.0;
    
    map<string, double>::const_iterator end_it = map_container.end();

    // Iterate through the map
    for (map<string, double>::const_iterator it = map_container.begin(); it != end_it; ++it) {
        // Access the mapped value 
        // aka the second element of the pair
        total_sum += it->second; 
    }
    return total_sum;
}



// Primary Template: Sum between two iterators (works for list/vector iterators)
// The template argument T is the Iterator type.
template <typename Iterator>
double Sum(Iterator start_it, Iterator end_it) {
    double total_sum = 0.0;
    
    for (Iterator it = start_it; it != end_it; ++it) {
        total_sum += *it;
    }

    return total_sum;
}

// Template Specialization: Overrides the primary template for std::map iterators
template <>
double Sum(map<string, double>::iterator start_it, map<string, double>::iterator end_it) {
    double total_sum = 0.0;
    
    map<string, double>::iterator it;
    
    for (it = start_it; it != end_it; ++it) {
        total_sum += it->second; 
    }

    return total_sum;
}

template <>
double Sum(map<string, double>::const_iterator start_it, map<string, double>::const_iterator end_it) {
    double total_sum = 0.0;
    
    map<string, double>::const_iterator it; //const iterator
    
    for (it = start_it; it != end_it; ++it) {
        total_sum += it->second; 
    }

    return total_sum;
}

#endif