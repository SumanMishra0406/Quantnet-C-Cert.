/*
A program to use preprocessor macros to find the maximum of two and three numbers.
*/
#include "Defs.h" 

int main(){
    int x,y,z;
    printf("Input x: ");
    scanf("%d",&x);
    printf("Input y: ");
    scanf("%d",&y);
    printf("Input z: ");
    scanf("%d",&z);
    
    // Use the MAX2 macro to find and print the maximum of x and y
    printf("The max value between %d and %d is %d.\n", x, y, MAX2(x,y));
    // Use the MAX3 macro to find and print the maximum of x, y, and z
    printf("The max value between %d, %d, and %d is %d.\n", x, y, z, MAX3(x,y,z));
}