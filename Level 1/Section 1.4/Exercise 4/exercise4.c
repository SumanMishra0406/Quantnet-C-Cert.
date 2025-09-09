/*
Create a C-program that prints two columns on the screen with the temperature in
degrees Fahrenheit and the equivalent temperature in degrees Celsius.
The left column shows the temperature in Fahrenheit. The right column shows the
temperature in Celsius. Start at 0, step size 20
*/

#include <stdio.h>

int main(){
    float start = 0.0;
    float end = 300.0;
    float step = 20.0;
    float fahrenheit, celsius;
    
    printf("Fahrenheit    Celsius \n");
    fahrenheit = start;
    while (fahrenheit <= end){
        celsius = (5.0/9.0) * (fahrenheit - 32.0);
        printf("%10.1f %10.1f \n", fahrenheit, celsius);
        fahrenheit+=step;
    }


    return 0;
}