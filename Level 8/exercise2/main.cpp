#include <iostream>
#include <string>
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp" 
using namespace std;

// Typedef for a Person tuple: name (string), age (int), length (double)
typedef boost::tuples::tuple<std::string, int, double> Person;


// fn to print the Person tuple
void print_person(const Person& p) {
    cout << "Person Data:"<<endl;
    cout << "Name: " << boost::tuples::get<0>(p)<<endl;
    cout << "Age: " << boost::tuples::get<1>(p)<<endl;
    cout << "Height: " << boost::tuples::get<2>(p) << " meters"<<endl;
    
    cout << endl;
}


int main() {
    
    Person person1 = boost::make_tuple(string("Suman Mishra"), 21, 1.72);
    Person person2("John Doe", 50, 1.85);
    Person person3("BlaBla Boy", 10, 1.30);
    
    print_person(person1); print_person(person2); print_person(person3);

    
    cout << "Incrementing Suman's age (Age is at Index 1)"<<endl;
    
    // Use get<1>(p) which returns a reference (lvalue) to the age element.
    // Index 1 corresponds to 'int age'.
    boost::tuples::get<1>(person1)++; 
    cout << "Suman's Tuple After increment:"<<endl;
    print_person(person1);

    return 0;
}