#include <stdio.h>

int main() {


	char C = 'Y'; //1 byte 0...255
	int a = 20; //2 bytes -32768...32768
	short e = -1; //2 bytes -128...127 "Zero is counted"
	unsigned int u = 25; //2 bytes 0...65535
	long l = 5932; //4 bytes -2147483648...2147483647
	float f = 72.538; //4 bytes
	double d = 12323.32321; //8 bytes

	printf("This is a variable of type character: %c\n", C);
		
	printf("This is an integer type variable: %i\n", a);

	printf("This is a short type variable: %i\n", e);

	printf("This is a variable of type unsigned: %i\n", u); //Does not contain values with minus symbols and we can combine unsigned with other data types.

	printf("This is a long type variable: %li\n", l);

	printf("This is a float type variable: %f\n", f);

	printf("This is a double type variabe: %.2lf\n", d);

	return 0;

}
