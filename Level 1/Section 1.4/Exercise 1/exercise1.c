/*
Write a C-program that asks for text input from the keyboard. The output of this
program should be the amount of characters, the amount of words and the amount of
newlines that have been typed. Multiple consecutive spaces shouldnot be counted as
multiple words.
*/
#include <stdio.h>
/*
1. Keyboard input
2. # char
3. # words
4. # new lines
5. multiple spaces is not new words, need to account for everytime I reach a character vs space

*/

int main(){
    int num_char = 0; //includes spaces, letters, special characters (! etc.)
    int num_words = 0; //seperate by space but need to check if prev was space or word
    int num_nline = 0; //count \n
    int text = 0; //int bc getchar returns int (returns negative for EOF)
    int new_word = 0; //flag to check if I'm on a word

    printf("Enter your text input. Press Ctrl+D to exit.\n");
    while((text = getchar()) != EOF && text != 4 /*ascii for ctrl + d*/){
        num_char++;
        if(text=='\n'){
            num_nline++;
        }
        if(text == '\n' || text == '\t' || text == ' '){
            new_word = 0;
            //we aren't in a word if the character is space, newline, or tab
        }else if(new_word==0){
            //this else if will run IFF:
            // 1. The current character is NOT a space/newline/tab.
            // 2. The previous character WAS a space/newline/tab (because flag var. word is 0).
            // This means we have just entered a new word.
            new_word = 1; // Set the flag to indicate we are now in a word.
            num_words++;    // Increment the word count only at this point.
        }
    }
    printf("\nCharacters: %d\n", num_char);
    printf("Words: %d\n", num_words);
    printf("Newlines: %d\n", num_nline);
    return 0;
    
}