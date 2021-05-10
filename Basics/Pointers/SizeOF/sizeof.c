/*

	C provides the binary operator to determine the size in bytes of an array or any other type of data

sizeof(array); returns: 80 ---> the size of the entire array.
sizeof(ptr);   returns: 8  ---> the size of the pointer or pointer.
sizeof(*ptr);  returns: 4  --->the size of the first object in the array (the "pointers" point only to one object in the array, which by default is the first).

*/


#include <stdio.h>
size_t getsize(float *ptr); //prototype function
int main() {
	
	float array[20]; //array float
	printf("The number of bytes in the array is:%lu \n", sizeof(array)); //Long unsigned it will allow us to be able to print the value in bytes and as a parameter we pass it the float array, as using float stores 4 bytes and multiplies by the size of the array
	printf("The number of bytes in the array is: %lu\n", getsize(array)); // We print the value of our array, sending to call the getsize function and pass it the same arrangement

	return 0;
}
size_t getsize(float *ptr) { //Function of type size that receives our float type array by making it our pointer, size_t is a type defined by the standard of C as an integer type and the value we must return must not have a sign
	
	return sizeof(ptr);// We return the sizeof of our pointer.

}




























