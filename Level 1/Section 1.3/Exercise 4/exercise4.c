/* Use the ?: operator to print if
someone is married or not. Using single printf
*/

#include <stdio.h>

int main(){
    // married is a variable to represent the marital status
    // 0 is interpreted as FALSE (not married), any non-zero value is TRUE (married)
    int married = 1; //1 implies the person is married, similarly can use "0" for not married

    // Use the ternary operator (?:)
    // value = (expr)? expr_true : expr_false
    // The condition 'married' evaluates to true if it's non-zero, and false if it's zero.
    
    printf(married ? "married" : "not married");

    /*
    doing  printf(!married ? "not married" : "married"); would also work
    
    since ! (logical not) flips the boolean value of married
    If the operand is TRUE (non-zero), ! makes it FALSE (which evaluates to 0).
    If the operand is FALSE (0), ! makes it TRUE (which evaluates to 1).

    Case 1: married is 1 (or any non-zero value)
    1) !married becomes !1. Since 1 is TRUE, !1 evaluates to FALSE, which is 0.
    2) The condition for the ternary operator is 0, which is FALSE.
    3) Therefore, the ternary operator returns the expression_if_false value, which is the string "married".
    
    Case 2: married is 0
    1) !married becomes !0. Since 0 is FALSE, !0 evaluates to TRUE, which is 1.
    2) The condition for the ternary operator is 1, which is TRUE.
    3) Therefore, the ternary operator returns the expression_if_true value, which is the string "not married".
    */

    return 0;
}