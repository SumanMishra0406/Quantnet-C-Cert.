#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {

    //list of doubles
    list<double> price_list;
    
    // adding some data
    price_list.push_back(10.0);
    price_list.push_back(15.0);
    price_list.push_front(20.0); //puts it at the front (becomes first element)

    // Access the first and last element
    cout << "First element (front()): " << price_list.front() << endl;
    cout << "Last element (back()): " << price_list.back() << endl;
    cout << endl;
    
    //vector of doubles
    vector<double> scores = {100.0, 80.0, 95.0};
   
    // capacity and reservation
    cout << "Initial size: " << scores.size() << endl;
    cout << "Initial capacity: " << scores.capacity() << endl; // Capacity is >= size

    // can reserve space to avoid reallocations
    scores.reserve(10); 
    cout << "Capacity after reserve(10): " << scores.capacity() << endl;

    // using the index operator to access some elements
    cout << "Element at index 0 (scores[0]): " << scores[0] << endl;
    cout << "Element at index 2 (scores[2]): " << scores[2] << endl;

    // adding elements using push_back (making the vector grow)
    scores.push_back(20.0);
    scores.push_back(30.0);
    scores.push_back(40.0);
    
    cout << "Vector size after growth: " << scores.size() << endl;
    cout<<endl;
   
    //map
    map<const char*, double> fruits;

    // Fill the map 
    fruits["apples"] = 1.00;
    fruits["banana"] = 2.00;
    fruits["cherry"] = 2.50;

    // Access elements using the square bracket operator
    cout << "Price of apples: " << fruits["apples"] << endl;
    cout << "Price of cherry: " << fruits["cherry"] << endl;
    
    // Using [] on a key that doesn't exist will insert it with a default value (0.0 for double)
    cout << "Accessing 'kiwis' (creates key): " << fruits["kiwis"] << endl; 
    cout << "Map size after 'kiwis' insertion: " << fruits.size() << endl;
    
    map<const char*, double>::iterator iterator;
    iterator = fruits.find("banana");
    cout << "banana price: " << (*iterator).second << endl;
    return 0;
}