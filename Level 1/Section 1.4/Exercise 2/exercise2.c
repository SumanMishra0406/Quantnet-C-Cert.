/*
Rewrite the C-program that was written for exercise 1, but use do while instead of while.
*/

#include <stdio.h>
int main(){
    int num_char = 0; //includes spaces, letters, special characters (! etc.)
    int num_words = 0; //seperate by space but need to check if prev was space or word
    int num_nline = 0; //count \n
    int text = 0; //int bc getchar returns int (returns negative for EOF)
    int new_word = 0; //flag to check if I'm on a word

    printf("Enter your text input. Press Ctrl+D to exit.\n");
    do{
        //want to get the character first, so had to remove it from previous while condition
        //and add it inside the "do" part
        text = getchar();
        if(text == EOF || text == 4){
            break;
        }

        num_char++; //if not eof or ctrl + d, then is char

        if(text=='\n'){
            num_nline++;
        }
        if(text == '\n' || text == '\t' || text == ' '){
            new_word = 0;
        }else if(new_word==0){
            new_word = 1; // Set the flag to indicate we are now in a word.
            num_words++;    // Increment the word count only at this point.
        }
    }while(1); //infinite loop

    printf("\nCharacters: %d\n", num_char);
    printf("Words: %d\n", num_words);
    printf("Newlines: %d\n", num_nline);
    return 0;
    
}