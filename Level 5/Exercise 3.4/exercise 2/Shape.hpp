#ifndef Shape_hpp
#define Shape_hpp

#include <string>
using namespace std;

class Shape
{
private:
    int m_id;
    
public:
    Shape(); //deafult
    Shape(const Shape& source);
    ~Shape(); //destructor
    Shape& operator = (const Shape& source); // Assignment operator
    
    int ID() const;
    string ToString() const;
};

#endif