#include "OutOfBoundsException.hpp"
#include <string>

OutOfBoundsException::OutOfBoundsException(int index) : m_index(index) {}

std::string OutOfBoundsException::GetMessage() const {
    return "Index " + std::to_string(m_index) + " is out of bounds.";
}