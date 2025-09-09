/*
The following program uses assignment-operators. Predict what will be printed on
screen (provide a code file with comments stating the output for each line). The
operators + and = = have a higher priority than the assignment-operators.
Assignment operators 
*/
#include <stdio.h>
int main(){
int x=2;
int y;
int z;

x*=3+2;
printf("x=%d\n", x);
// x *= 3 + 2;
// Operator precedence (+ and == have higher priority):
// 1) Addition: 3 + 2 = 5
// 2) Then we have x *= 5, which is x = x * 5
// 3) x = 2 * 5 = 10
// Final Ans: x =10.

x*=y=z=4;
printf("x=%d\n", x);
// x *= y=z=4;
// Operator precedence (+ and == have higher priority than assignment):
// 1) Right to left assignment first => z=4
// 2) Next assignment y=z=4 => y=4
// 3) Multiplication: x = x*4 = 10*4 (10 from last q)
// Final Ans: x = 40


x=y==z;
printf("x=%d\n", x);
// x=y==z;
// Operator precedence (+ and == have higher priority than assignment):
// 1) y==z first, Since y and z are both 4 (from previous q), the equality operator returns True
// 2) Next is assignment, x= (y==z). Since True is equivalent to 1 in integer form, 1 is assigned to x
// Final Ans: x = 1

return 0;
}