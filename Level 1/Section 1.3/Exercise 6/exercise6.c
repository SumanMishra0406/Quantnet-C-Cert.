/*
Write a C-program that shifts any number two places to the right. Input should be an
integer. Output should be the shifted result, as well as output an indication of
whether a logical or arithmetic shift is performed (if a 1 or 0 is shifted in at the
left side) for the inputted number.
*/

#include <stdio.h>

int main(){
    int num;
    printf("Input an integer: ");
    scanf("%d", &num);
    // shifting to the left will be the same for logical and arithmetic shifts
    // shifting to the right will add a 1 at the at the MSB for arithmetic shift
    // shifting to the right will add a 0 at the MSB for a logical shift
    int shifted_num = num >> 2;
    printf("num = %d, after shifting to the right by 2 we have: %d\n", num, shifted_num);
    if (num >= 0) //if input is a positive number we don't need to check because we'll get the same result
    {
        printf("logical and arithmetic right shifts are the same, 0 is added at the MSB\n");
    }
    else
    {
        if (shifted_num < 0) //if the shifted number is negative, we have an arithmetic shift
        {
            printf("arithmetic right shift: 1 is added at the MSB\n");
        }
        else
        {
            printf("logical right shift, 0 is added at the MSB\n");
        }
    }
    return 0;
}