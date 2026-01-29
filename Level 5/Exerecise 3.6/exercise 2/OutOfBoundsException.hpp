#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp

#include "ArrayException.hpp"

// Derived class for out-of-bounds exceptions.
class OutOfBoundsException : public ArrayException {
private:
    int m_index;

public:
    OutOfBoundsException(int index);
    std::string GetMessage() const override;
};

#endif