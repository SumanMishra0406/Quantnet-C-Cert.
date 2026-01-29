#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <string>

class ArrayException {
public:
    virtual ~ArrayException() {}
    virtual std::string GetMessage() const = 0;
};

#endif