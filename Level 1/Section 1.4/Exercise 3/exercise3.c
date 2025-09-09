/* use switch instead of if*/
#include <stdio.h>


int main(){
    int num_char = 0;
    int num_words = 0;
    int num_nline = 0;
    int text = 0;
    int new_word = 0;

    printf("Enter your text input. Press Ctrl+D to exit.\n");
    while((text = getchar()) != EOF && text != 4){
        num_char++;
        
        switch(text){
            case ' ':
            case '\t':
                new_word = 0; break; //not on a new word
            case '\n':
                num_nline++; new_word = 0; break; //on a new line and on a new word therefore need to enforce 0
            default:
                if (new_word == 0) {
                    new_word = 1;
                    num_words++;
                }
                break;
        }
    }
    printf("\nCharacters: %d\n", num_char);
    printf("Words: %d\n", num_words);
    printf("Newlines: %d\n", num_nline);
    return 0;
}