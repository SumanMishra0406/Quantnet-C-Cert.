#include "OutOfBoundsException.hpp"
#include <string>

// Constructor
OutOfBoundsException::OutOfBoundsException(int index) : m_index(index) {}

// Return error message with the index
std::string OutOfBoundsException::GetMessage() const {
    return "Index " + std::to_string(m_index) + " is out of bounds.";
}