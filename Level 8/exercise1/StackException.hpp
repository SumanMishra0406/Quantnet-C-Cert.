#ifndef StackException_hpp
#define StackException_hpp

#include <string>
#include <iostream>
#include "ArrayException.hpp"

// Base class
class StackException : public ArrayException {
public:
    virtual ~StackException() override {}
    // GetMessage() is inherited as pure virtual
};

class StackFullException : public StackException {
public:
    std::string GetMessage() const override {
        return "Stack operation failed: The stack is full.";
    }
};

class StackEmptyException : public StackException {
public:
    std::string GetMessage() const override {
        return "Stack operation failed: The stack is empty.";
    }
};

#endif