/*
Write a C-program that efficiently multiplies a number by a factor 2 to the power n. The
number to multiply and n are variables, which get a value at the start of the program.
*/
#include <stdio.h>

int main() {
    int number,n;
    printf("Enter the number to be multiplied: ");
    scanf("%d", &number);

    printf("Enter the value of n for the factor of 2^n: ");
    scanf("%d", &n);

    int result = number << n;
    //a left shift by n is the same as multiplying that number by 2^n
    //similarly a right shift by n is the same as dividing that number by 2^n
    printf("Result of %d * (2^%d) is: %d\n", number, n, result); // e.g. 5 * 2^3 = 5 * 8 = 40
    return 0;
}
