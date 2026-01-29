#ifndef Array_hpp
#define Array_hpp
#include "Point.hpp"

class Array {
private:
    Point* m_data;
    int m_size;

public:
    Array(); // Default constructor
    Array(int size); // Param. constructor
    Array(const Array& source); // Copy constructor
    ~Array(); // Destructor
    Array& operator=(const Array& source); // Assignment operator

    int Size() const; // Returns the size of the array.
    void SetElement(int i, const Point& p); // Setter
    Point& GetElement(int i) const; // Getter

    Point& operator[](int i); // [] operator to get an element from index
    const Point& operator[](int i) const; //return constant ref.
};

#endif
