/*
Write a recursive function printnumber() which gets the number to be printed. This
number is an integer. The function should print the number digit by digit by using
the putchar() function. Don’t use printf().
*/
#include <stdio.h>

void printnumber(int n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    if (n < 0) {
        putchar('-'); //handle negative, suppose I start with -123
        n = -n; //change to positive to continue the original process, we have - and then 123 seperate
    }
    
    if (n / 10 != 0) { // helps "remove" the last digit of each number, like 123/10 -> 12 and 123 paused on callstack
        printnumber(n / 10);
    }
    
    // Print the last digit in reverse order of the calls
    putchar( (n % 10) + '0'); //'0' converts it back to ascii

}

int main() {
    int num1;
    printf("Enter an integer for printing: ");
    scanf("%d", &num1);
    
    printf("Printed output without printf: ");
    printnumber(num1);
    printf("\n");
    
    return 0;
}