//Create a C-program that clearly shows the difference between --i and i--
#include <stdio.h>

int main(){
    int x = 5;
    int y;

    y = x--; //y=x, x=x-1
    //assign value first, then decrement
    // y = x = 5
    // x = 5-1 = 4
    printf("After post decrement, x and y are:  %d, %d \n", x, y);

    // x is now 4 due to prev. operation
    y = --x; //y=(x=x-1)
    //decrement first, then assign value
    //x = 4-1 = 3
    //y = x = 3
    printf("After pre decrement, x and y are: %d, %d \n", x,y);
    return 0;
}