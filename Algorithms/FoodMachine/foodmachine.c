/*
	Prog0ram Name: Food Machine
	Date: 09/05/21
	Author: Adrián Jonás Lara Carvente
	Description: Este programa te muestra 3 productos con sus respectivos precios y las monedas que puedes usar para pagar
*/

#include <stdio.h>

int main(){
	
	char d; //Declaro mi variable char para las opciones A, B y C en el switch
	int a, b, c, c1 = 0, m1, m2, s1, precio; //variables enteras
			
	printf("Este programa te muestra 3 productos con sus respectivos precios y las monedas que puedes usar para pagar.\n");
	printf("\nProductos disponibles: \n");	//Muestro los productos disponibles
	printf("\nA = $27		|		");
	printf("B = $34 	|		");
	printf("C = $39 \n");
	printf("\nLas únicas monedas que acepto son: $10, $5 y $1\n"); //Le digo que monedas acepta la máquina
	printf("\nPor favor, elige una opción entre los productos A, B y C: "); //Le pido que elija que quiere comer xD
	scanf("%c", &d); //Asigno el valor ingresado por el usuario a la variable d de tipo char
	
	switch(d) { //Switch con variable d
	

		case 'A': //Asigno el caracter A en máyuscula para mi producto A
		case 'a': //Asigno el valor a en minúscula, ya sabes el usuario :v 
		precio = 27; //El precio del producto A

		printf("\nIngrese el dinero: \n"); 
		scanf("%d",&a);	//Una vez el usuario ingresa la primera moneda la asigno a la variable de tipo entero.
		if (a==1||a==5||a==10){ //Condiciono con uso de la compuerta lógica OR para que este case solo acepte los valores 1, 5 y 10; las monedas.
		b=a; //asigno el valor de a a la variable b para poder usarlo en while y poder seguir usando la variable a.
		while(b<27){ //Mientra b sea menor que 27(El precio del producto A)
				printf("Ingrese el dinero: \n");
				scanf("%d", &a); //El usuario continua ingresando dinero y lo continuo asignando a la variable a
				if (a==1||a==5||a==10){ //Condiciono con uso de la compuerta lógica OR para que en este ciclo solo acepte los valores 1, 5 y 10; las monedas.
				b = b+a; //Le asigno a b el valor de a, aumentando el nuevo valor a ingresado por el usuario.
				} else {
					printf("Lo siento no acepto esa moneda, por favor introduce una moneda de $10, $5 o $1\n"); //Le indico al usuario que hacer
				}
			} printf("\nEl dinero ingresado son: $%d\n",b); //Muestro la cantidad total ingresada
			if (b>27) {//Condiciono si b es mayor a 27(el precio del producto A)
				c = b - 27;	//La variable c(cambio) es igual al valor que tenga b - 27(el precio del producto a)
				printf("El cambio total son: $%d\n", c); //Imprimo el cambio total
					
				m1=c/5; //Divido el valor de c(cambio) entre 5 para sacar enteros y lo asigno a la variable m1.
	           		
				s1=c%5; //Residuo de la división de c(cambio) entre 5 y lo asigno a la variable s1.
           
           		m2=s1/2; //Divido el residuo s1 entre 2 para sacar enteros y lo asigno a la variable m2.

				/*Con esto se logra cumplir la condición de dar el cambio en las monedas de $5 y $2*/

    			if (m2==1||s1==1) { //Condiciono usando la compuerta lógica OR para el valor de m2(moneda 2) es igual a 1 o si s1(sobrante 1) es igual a 1
		   		printf("\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 1 moneda(s) de $1\n",m1,m2); //Si esto es cierto utilizo 1 moneda de $1
		  		}	else{ 
				printf("\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 0 moneda(s) de $1\n",m1,m2); //Si esto es falso no utilizo moneda de $1
	      			} 
				} else {
					printf("Pago aceptado\n");
					} //Si nada de lo anteior es cierto y el usuario ingreso correctamente el dinero, entonces el pago se acepta.
		} else {
			printf("Por favor entiende que las únicas monedas que acepto son $10, $5 y $1\n");
		} //Si al inicio el usuario introdujo un valor distinto a las monedas $10, $5 y $1, pues lo regaño :v 
		break;


		/*No tiene caso comentar el case B porque es practicamente igual a excepción que cambian los valores del precio para el producto B, por 34*/
		case 'B':
		case 'b':	
				
		precio = 34;

		printf("\nIngrese el dinero: \n");
		scanf("%d",&a);	
		if (a==1||a==5||a==10){
		b=a;
		while(b<34){
				printf("Ingrese el dinero: \n");
				scanf("%d", &a);	
				if (a==1||a==5||a==10){
				b = b+a;	 
				} else {
					printf("Lo siento no acepto esa moneda, por favor introduce una moneda de $10, $5 o $1\n");
				}
			} printf("\nEl dinero ingresado son: $%d\n",b);
			if (b>34) {
				c = b - 34;	
				printf("El cambio total son: $%d\n", c);
					
				m1=c/5;
	            
				s1=c%5;
           		
			    m2=s1/2;

    			if (m2==1||s1==1) {
		   		printf("\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 1 moneda(s) de $1\n",m1,m2);
		  		}	else{ 
				printf("\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 0 moneda(s) de $1\n",m1,m2);
	      			} 
				} else {
					printf("Pago aceptado\n");
					}
		} else {
			printf("Por favor entiende que las únicas monedas que acepto son $10, $5 y $1\n");
		}
		break;


		/*No tiene caso comentar el case C porque es practicamente igual a excepción que cambian los valores del precio para el producto C, por 39*/
		case 'C':
		case 'c':	
			
		precio = 39;

		printf("\nIngrese el dinero: \n");
		scanf("%d",&a);	
		if (a==1||a==5||a==10){
		b=a;
		while(b<39){
				printf("Ingrese el dinero: \n");
				scanf("%d", &a); 
				if (a==1||a==5||a==10){
				b = b+a;	 
				} else {
					printf("Lo siento no acepto esa moneda, por favor introduce una moneda de $10, $5 o $1\n");
				}
			} printf("\nEl dinero ingresado son: $%d\n",b);
			if (b>39) {
				c = b - 39;	
				printf("El cambio total son: $%d\n", c);
					
				m1=c/5;

	            s1=c%5;
           
           		m2=s1/2;

    			if (m2==1||s1==1) {
		   		printf("\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 1 moneda(s) de $1\n",m1,m2);
		  		}	else{ 
				printf("\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 0 moneda(s) de $1\n",m1,m2);
	      			} 
				} else {
					printf("Pago aceptado\n");
					}	
		} else {
			printf("Por favor entiende que las únicas monedas que acepto son $10, $5 y $1\n");
		}
		break;

		default: //Ni un case del Switch se cumplio
			printf("Por favor, introduce un CARÁCTER entre los productos A, B y C\n"); //Si al inicio el usuario introdujo un valor que no es un caracter o un carácter inválido le pido que por favor razone su desición.

		break; //
	}
	
	return 0;

}
