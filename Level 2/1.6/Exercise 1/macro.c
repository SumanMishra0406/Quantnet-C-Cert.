/*
this exercise is to practice the use of function macros in seperate header files
*/
#include "Defs.h"

int main() {
    int a, b;
    
    printf("input your value for a: ");
    scanf("%d", &a);
    
    printf("input your value for b: ");
    scanf("%d", &b);

    PRINT1(a);
    PRINT2(a, b);
    
    return 0;
}