/*
Write a C-program that calls a function minus(). This function receives two arguments
and returns the difference (regular subtraction, not absolute). This difference should be
printed on screen.
*/
#include <stdio.h>

int minus(int x, int y){
    return x-y;
}

int main(){
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("%d - %d = %d\n",num1,num2,minus(num1,num2));
    
    return 0;
}