/*
    // Pointers are variables whose values are memory addresses.
    When we define a variable we assign it a value. For example, an entire variable called "a". This is how we inform the
    compiler two things; the name and type of data, so when you find the reserved word int, it reserves 4 bytes of memory 
    to store the integer value and we when assigning it a value we specify a memory space.
*/

#include <stdio.h>

int main() {

    int a = 4;
    int *apt = &a;          /* Pointer variable is assigned with * and we point to our variable to refer to the 
                            value that is hosted in this variable */
    printf("%p\n", apt);    /* Printing the memory address with %p gives us the memory address as a hexadecimal integer cd */

    return 0;
 
}