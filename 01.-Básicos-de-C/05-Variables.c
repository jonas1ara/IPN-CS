#include <stdio.h>

int main() {

	char C = 'Y'; //1 byte 0...255
	int a = 20; //2 bytes -32768...32768
	short e = -1; //2 bytes -128...127 "Cero es tomado en cuenta"
	unsigned int u = 25; //2 bytes 0...65535
	long l = 5932; //4 bytes -2147483648...2147483647
	float f = 72.538; //4 bytes
	double d = 12323.32321; //8 bytes

	printf("Esta es una variable de tipo Char: %c\n", C);
		
	printf("Esta es una variable de tipo Int: %i\n", a);

	printf("Esta es una variable de tipo Short: %i\n", e);

	printf("Esta es una variable de tipo Unsigned: %i\n", u); //No contiene valores con símbolos menos y podemos combinar unsigned con otros tipos de datos.

	printf("Esta es una variable de tipo Long: %li\n", l);

	printf("Esta es una variable de tipo Float: %f\n", f);

	printf("Esta es una variable de tipo Double: %.2lf\n", d);

	return 0;

}
