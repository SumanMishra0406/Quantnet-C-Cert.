#include <stdio.h>
/*
the purpose of the function is to swap two variables 
without having to create a copy (call by value)
We do this by using pointers as function parameters (pass by ref.)
*/
void swap(int* i, int* j){
    int temp = *i; //need a temp variable to hold the first integer to give to second later
    *i=*j; //need to dereference to assign the actual values
    *j= temp; 
}

int main(){
    int i,j;
    printf("input value for i: ");
    scanf("%d",&i); //using & to give the address
    printf("input value for j: ");
    scanf("%d",&j);

    swap(&i,&j); //passing by reference
    printf("The value of i is now: %d\n",i);
    printf("The value of j is now: %d\n",j);
}