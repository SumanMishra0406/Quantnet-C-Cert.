/* Extend the program of exercise 6 in such a way that the frequency of number 3 is shown in words*/
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
    printf("\n0 has been typed %d time(s)\n", num0);
    printf("1 has been typed %d time(s)\n", num1);
    printf("2 has been typed %d time(s)\n", num2);
    
    //special case for num3
    switch (num3){
        case 0:
            printf("Number three appeared zero times\n"); break;
        case 1:
            printf("Number three appeared one time\n"); break;
        case 2:
            printf("Number three appeared two times\n"); break;
        default:
            printf("The number three appears more than two times.\n");
        }

    printf("4 has been typed %d time(s)\n", num4);
    printf("Other characters have been printed %d times\n", other);

    return 0;
}