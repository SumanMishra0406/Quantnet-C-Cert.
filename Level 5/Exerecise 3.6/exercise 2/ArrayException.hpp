#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <string>

// Abstract base class for array exception
class ArrayException {
public:
    virtual ~ArrayException() {} // virtual destructor
    virtual std::string GetMessage() const = 0; // Pure virtual
};

#endif