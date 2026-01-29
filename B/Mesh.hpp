// Mesh.hpp
#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

// Generates evenly-spaced values from start to end (inclusive)
// Template allows it to work with any numeric type (double, float, int)
template <typename T>
inline std::vector<T> MeshArray(T start, T end, T interval)
{
    std::vector<T> arr;
    
    if (interval <= T{}) return arr;  // T{} is zero-initialization for any type
    
    if (end < start) { 
        T tmp = start; 
        start = end; 
        end = tmp; 
    }
    
    for (T val = start; val <= end; val = val + interval) {
        arr.push_back(val);
    }
    
    return arr;
}

#endif // MESH_HPP
