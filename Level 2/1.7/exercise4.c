/* need to print the day of the week using an array of pointers */
#include <stdio.h>

/*
This function prints the name of the week in the array given an integer
dayname is an array of pointers to characters

*/
void Day_Name(int input, char* dayname[]){
    printf("The day you have chosen is: %s\n",dayname[input]);

}
int main(){
    //the 0th index is for invalid input
    char* dayname[] = {"Enter a valid number ","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int i;
    printf("Enter a number from 1 to 7, 1 corresponds to Sunday ");
    scanf("%d",&i);
    // Check if the input is within the valid range
    if (i >= 1 && i <= 7) {
        Day_Name(i, dayname);
    } else {
        //if invalid
        Day_Name(0, dayname);
    }
    return 0;
}
