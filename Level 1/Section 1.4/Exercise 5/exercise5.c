/*
Create a C-program that prints two columns on the screen with the temperature in
degrees Celsius in the left column and degrees Fahrenheit in the right column.
*/
#include <stdio.h>

int main(){
    float fahrenheit, celsius;
    printf("Celsius    Fahrenheit \n");
    for(float celsius=0.0 /*start*/; celsius<20.0/*end*/; ++celsius /*since step size = 1*/){ //preinc for efficiency
        fahrenheit = (9.0/5.0) * (celsius)+ 32.0;
        printf("%10.1f %10.1f \n", celsius, fahrenheit);
    }

}