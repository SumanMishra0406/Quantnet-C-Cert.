#include "Shape.hpp"
#include <sstream>
#include <iostream>
#include <stdlib.h>

namespace suman {
    namespace CAD {
        Shape::Shape() : m_id(rand()) {
            std::cout << "Shape default constructor" << std::endl;
        }

        Shape::Shape(const Shape& source) {
            m_id = source.m_id;
            std::cout << "Shape copy constructor" << std::endl;
        }

        Shape::~Shape(){
            std::cout << "Shape Destructor" << std::endl;
        }

        std::string Shape::ToString() const {
            std::stringstream ss;
            ss << "ID: " << m_id;
            return ss.str();
        }

        int Shape::ID() const {
            return m_id;
        }

        Shape& Shape::operator = (const Shape& source){
            if (this == &source){
                return *this;
            }
            m_id = source.m_id;
            return *this;
        }
    }
}