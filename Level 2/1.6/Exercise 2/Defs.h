#ifndef Defs.h
#define Defs.h
#include <stdio.h>

#define MAX2(x, y) (((x) > (y)) ? (x) : (y))

// Macro to find the maximum of three values by reusing MAX2.
// max of 3 numbers would be the max between (x and y) and z
#define MAX3(x, y, z) MAX2(MAX2(x, y), z)
#endif