/*
Write a program that consists of two source-files. The first (Main.c) contains
the main() function and gives the variable ia value. The second source-file (Print.c)
multiplies i by 2 and prints it.
*/

#include <stdio.h>

void print(int i);

int main(){
    int i;
    printf("Give a value for i: ");
    scanf("%d", &i);
    print(i);
}

/*
How I compiled:
1) First compile both into .o
gcc -c main.c
gcc -c print.c

2) Then link together:
gcc -o main main.o print.o



*/