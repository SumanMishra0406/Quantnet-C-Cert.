/*
Create a C-program that counts how many times each of the numbers 0-4 have been
typed. Use a switch-case construction. 
*/
#include <stdio.h>

int main(){
    int num0 = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int other = 0;

    int inpt;
    printf("Enter your numbers. Press Ctrl+D or Ctrl+Z to stop.\n"); //ctrl+d worked on my system
        while ((inpt = getchar()) != EOF && inpt != 4 && inpt != 26) {
        switch (inpt) {
            case '0':
                num0++;
                break;
            case '1':
                num1++;
                break;
            case '2':
                num2++;
                break;
            case '3':
                num3++;
                break;
            case '4':
                num4++;
                break;
            default:
                other++;
                break;
        }
    }
    printf("0 has been typed %d times\n", num0);
    printf("1 has been typed %d times\n", num1);
    printf("2 has been typed %d times\n", num2);
    printf("3 has been typed %d times\n", num3);
    printf("4 has been typed %d times\n", num4);
    printf("Other characters have been printed %d times\n", other);


    return 0;


}