/* 
Predict what will be printed on screen (provide a code file with comments stating the
output for each line).
*/
#include <stdio.h>
int main()
{
    int x;
    x = -3 + 4 * 5 - 6;
    printf("x=%d\n", x);
    /*
    Operator Precedence (PEMDAS)
    1) Multiplication: 4*5 = 20
    2) Addition and Subtraction left to right: -3+20 = 17 -> 17-6 = 11
    3) Final Ans: 11
    */

    x = 3 + 4 % 5 - 6;
    printf("x=%d\n", x);
    /*
    Operator Precedence (PEMDAS)
    1) Modulo: 4%5 = 4 since 4/5 gives remainder 4
    2) Addition and Subtraction left to right: 3+4 = 7 -> 7-6 = 1
    3) Final Ans: 1
    */

    x = -3 * 4 % -6 / 5;
    printf("x=%d\n", x);
    /*
    Operator Precedence (PEMDAS), 
    Multiplication, Modulus, and Division have the same precedence, so left to right):
    1) Multiplication: -3*4 = -12
    2) Modulo: -12 % -6 = 0 (since -12 is a multiple of -6)
    3) Division: 0/5 = 0
    4) Final Ans: 0
    */

    x = (7 + 6) % 5 / 2;
    printf("x=%d\n", x);
    return 0;
    /*
    Operator Precedence (PEMDAS), 
    Multiplication, Modulus, and Division have the same precedence, so left to right):
    1) Parantheses: 7+6=13
    2) Modulo: 13 % 5 = 3
    3) Division: 3/2 = 1 (since integer division and we truncate the fraction part)
    4) Final Ans: 1
    */
}