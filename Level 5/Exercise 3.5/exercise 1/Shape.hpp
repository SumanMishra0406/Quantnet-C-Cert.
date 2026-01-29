#ifndef Shape_hpp
#define Shape_hpp

#include <string>
using namespace std;

namespace suman {
    namespace CAD {
        class Shape
        {
        private:
            int m_id;

        public:
            Shape();
            Shape(const Shape& source);
            ~Shape();
            Shape& operator = (const Shape& source);

            int ID() const;
            virtual string ToString() const;
        };
    }
}
#endif