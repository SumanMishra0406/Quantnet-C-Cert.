/*
Write a C-program that prints the factorials of a number.
*/
#include <stdio.h>

int factorial(int x){
    if(x==0){
        return 1;
    }
    if(x<0){
        return -1;
    }
    return x * factorial(x-1);
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int result = factorial(num);
    
    if (result == -1) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %d.\n", num, result);
    }
    return 0;
}