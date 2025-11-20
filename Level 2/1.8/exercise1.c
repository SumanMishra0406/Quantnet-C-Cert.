/*
Define a struct called Article to group related data.
Struct is like a data type but it is user-defined to hold many types of different variables
*/
#include <stdio.h>
struct Article{
    int Article_number;
    int Quantity;
    char Description[20];

};

/*
1. The print function prints the details of the Article struct
2. The input param. is a pointer to the struct Article
3. It is better to use a pointer to avoid copying the entire struct
The "->" symbol is used to access members of the struct
*/
void Print(struct Article* ptr){
    printf("The article number is: %d\n",ptr->Article_number);
    printf("The article quantity is: %d\n",ptr->Quantity);
    printf("The article description is: %s\n",ptr->Description);
}

int main(){
    //creating an instance of the struct and simultaneously initializing the members
    struct Article my_article = {5,6,"Hello World!"};
    Print(&my_article); //use & to give address
}