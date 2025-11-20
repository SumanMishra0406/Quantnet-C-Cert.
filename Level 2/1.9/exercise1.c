/*
This exercise is to show how to read characters from the keyboard one by one
until Ctrl+ A is inputted. It also shows how stdin is buffered.
 */
#include <stdio.h>

int main(){
    int ch; //integer because get char and putchar reads int one at a time
    printf("Please input your characters: ");

    //The getchar() function reads the next character from the buffer
    while((ch=getchar())!=1){ //1 for ctrl+A ascii, loop continues as long as user doesnt enter ctrl+A
        // The putchar() function writes the character stored in ch to the stdout
        putchar(ch);
    }
    if(ch == 1){
        printf("CTRL + A is a correct ending.");
    }

    return 0;
}