/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a)) // Print decimal
#define NL printf("\n");         // Print new line
// Create and initialse array
int a[] = {0, 1, 2, 3, 4};
int main()
{
    int i;
    int *p;
    /*
    1:
    a[i] from i = 0 to i=4 and then prints decimal using PRD
    */
    for (i = 0; i <= 4; i++) //1: 0 1 2 3 4
        PRD(a[i]);
    NL; //new line

    /*
    2:
    uses dereference to get value stored at pointed location
    since p is a pointer, need to store address locatio, therefore start at p = &a[0]
    p gets the address from 0 to 4 and then dereference to get value
    use PRD to print decimal
    */
    for (p = &a[0]; p <= &a[4]; p++) //2: 01234
        PRD(*p);
    NL; //newline
    NL;

    /*
    3:
    since array is stored with contegious location 
    p gets address at index 0 and then we increment the address location to get the 
    consecutive locations of each element
    */
    for (p = &a[0], i = 0; i <= 4; i++) //3: 01234
        PRD(p[i]);
    NL;

    /*
    4:

    1st iteration
    p gets a[0]
    p + i <= a + 4 is true (a[0] + 0 <= a[4]) for first iteration
    dereference of *(p + i) is equivalent to  *(a + 0)=a[0]. then a[0] printed
    both p and i incremented, p points to a[1] and i is 1

    2nd iteration
    in second iter: p is a[1] and i is 1
    so the condition is a[1] + 1 <= a[4]. This is equivalent to a[2] <= a[4], which is true.
    The code prints *(p + i), which is *(a[1] + 1) = a[2]. 2 is printed.
    p and i are incremented. p points to a[2], and i is 2.

    3rd iteration
    in third iter: p is a[2] and i is 2
    so the condition is a[2] + 2 <= a[4]. This is equivalent to a[4] <= a[4], which is true.
    The code prints *(p + i), which is *(a[2] + 2) = a[4]. 4 is printed.
    p and i are incremented. p points to a[3], and i is 3.

    4th iteration
    in fourth iter: p is a[3] and i is 3
    so the condition is a[3] + 3 <= a[4]. This is equivalent to a[6] <= a[4], which is false.
    condition fails, loop ends.
    */

    for (p = a, i = 0; p + i <= a + 4; p++, i++) //4: 024
        PRD(*(p + i));
    NL;
    NL;

    /*
    5:
    1st iteration
    p = a+4 is the same as p points to address of a[4];
    p>=a is the same as (address of a[4]) >= (address a[0]) which is true
    then dereference p and get the value at a[4], which is 4
    then p--.

    final iteration
    this continue until we have p pointing to address of a[0] after decrementing
    then (address of a[0]) >= (address of a[0]) is true
    dereference and print a[0]
    after p--, p now points to an address before a[0], conditional fails and loop stops
    */
    for (p = a + 4; p >= a; p--) //5: 43210
        PRD(*p);
    NL;

    /*
    6:
    1st iteration
    p = a+4 is the same as p points to address of a[4], i = 0
    i=0<4 is true and the condition runs from i = 0 to i=4
    p[-i] is the same as *(p - i)
    for i = 0, p[4-0] will print a[4]
    i = 1, p[-1] is the same as *(p-1) = a[3]
    i = 2, p[-2] is the same as *(p-2) = a[2]
    and so on.
    */
    for (p = a + 4, i = 0; i <= 4; i++) //6: 43210
        PRD(p[-i]);
    NL;


    /*
    7:
    1st iteration
    p = a+4 is the same as p points to address of a[4]
    p>=a is the same as (address of a[4]) >= (address a[0]) which is true
    for p = a+4, p-a is (a + 4) - a = 4
    so it will print a[4]
    then p is decremented
    p = a+3, p-a is (a+3)-a = 3
    a[3] printed..
    and so on
    */
    for (p = a + 4; p >= a; p--) //7: 43210
        PRD(a[p - a]);
    NL;

    return 0;
}