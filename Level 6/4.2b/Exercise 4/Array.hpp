#ifndef Array_hpp
#define Array_hpp


namespace suman {
    namespace Containers {
        
        template <typename T>
        class Array {
        private:
            static int m_defaultSize; 
            T *m_data;
            int m_size;

        public:
            Array();                               // Default constructor
            Array(int size);                       // Param. constructor
            Array(const Array<T> &source);         // Copy constructor
            virtual ~Array();                              // Destructor
            Array<T> &operator=(const Array<T> &source); // Assignment operator

            int Size() const;                       // Returns the size of the array.
            
            void SetElement(int i, const T &p); // Setter
            T &GetElement(int i) const;         // Getter
            T &operator[](int i);               // [] operator
            const T &operator[](int i) const;   // const [] operator

            static int DefaultSize();
            static void DefaultSize(int size);
        };

    }
}
#endif

#ifndef Array_cpp 
#include "Array.cpp" 
#endif