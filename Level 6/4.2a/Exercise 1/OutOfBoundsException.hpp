#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp

#include "ArrayException.hpp"

class OutOfBoundsException : public ArrayException {
private:
    int m_index;

public:
    OutOfBoundsException(int index);
    std::string GetMessage() const override;
};

#endif