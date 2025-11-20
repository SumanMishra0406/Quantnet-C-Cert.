/*
This exercise reads characters from the keyboard and writes them to a user-input file instead of the screen.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp;
    int ch; //integer because get char and putchar reads int one at a time
    char filename[100]; //buffer to store file name
    //get the name of the file from the user
    printf("Please enter the name of the file to write to: ");
    scanf("%s", filename);
    getchar(); //get rid of the new line that scanf reads in the buffer when I press enter after input

    // go from stdout to inputted the file
    // "w" mode opens the file for writing. If the file exists, its deleted first.
    // If it doesn't exist, a new one is created.
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("ERROR");
        exit(1);
    }

    // writing to the file instead of the screen:
    printf("Please input your characters: ");

    // loop stays the same, but putchar() now writes to the file.
    while((ch = getchar()) != 1){
        fputc(ch, fp);
    }
    
    //also on the file
    if(ch == 1){
        fprintf(fp, "CTRL + A is a correct ending.");
    }

    fclose (fp); //close the file

    return 0;
}