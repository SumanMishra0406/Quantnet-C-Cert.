#ifndef Shape_hpp
#define Shape_hpp

#include <string>
#include <iostream>

namespace suman {
    namespace CAD {
        class Shape
        {
        private:
            int m_id;

        public:
            Shape();
            Shape(const Shape& source);
            virtual ~Shape();
            Shape& operator = (const Shape& source);

            int ID() const;
            virtual std::string ToString() const;
            virtual void Draw() = 0;

            
            void Print() const;
        };
    }
}
#endif