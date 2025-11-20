#ifndef Defs_h // #ifndef checks if Defs_h has not been defined yet.
// if not defined yet then it continues to define it
#define Defs_h
#include <stdio.h>

/*
PRINT1 is a function-like macro that takes in "a" and prints it
PRINT2 is another function-like macro that takes in "a" and "b" and prints them
*/
#define PRINT1(a) printf("%d\n",a)
#define PRINT2(a,b) printf("%d, %d\n", a, b)

#endif