/*
Predict what the following program prints on screen (provide a code file with comments
stating the output for each line).
Conditional expressions
*/
#include <stdio.h>
int main(){
int x=1;
int y=1;
int z=1;

x+=y+=x;
// x += y += x;
// right-to-left precedence for assignment operators
// 1) y += x is evaluated -> y = y + x: y = 1 + 1 = 2. y is 2
// 2) This result is then added to x: x += 2, which is the same as x = x + 2
// 3) x = 1 + 2 = 3.x is now 3
// Final Ans: x=3, y=2, z=1

printf("%d\n\n", (x<y)?y:x);
// The conditional expression is (x < y).
// 3 < 2 is FALSE.
// The false expression is chosen, which is x.
// Prints 3 and then two new lines

printf("%d\n", (x<y)?x++:y++);
// The conditional expression is (x < y).
// 3 < 2 is FALSE.
// The false expression is chosen, which is y++, y=y+1 (post increment).
// Prints 2 (not 3) since y is incremented after printf

printf("%d\n", x); // Number 3
// value of x didn't change (since we didn't increment it in the last q)
// Prints 3


printf("%d\n", y); // Number 4
// value of y changed due to post increment earlier
// Prints 3 (y = y+1 => y = 2+1 = 3 from prev question)

return 0;

}