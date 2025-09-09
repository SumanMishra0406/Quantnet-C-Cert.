/* 
Write a program that calculates the surface of a triangle with one 90 degree angle. The
formula is half the height multiplied by the base. The program should take an input from
the user (base & height), and output the result.
*/

#include <stdio.h>

int main(){
    float height, base;
    printf("Enter the base of the triangle: ");
    scanf("%f", &base); //scanf syntax: scanf("format string", &variable1, &variable2, ...);
    printf("Eenter the height of the triangle: ");
    scanf("%f", &height);

    printf("The surface area of the triangle is %f\n", base*height/2); //will give float since numerator is float
    
    return 0;
}