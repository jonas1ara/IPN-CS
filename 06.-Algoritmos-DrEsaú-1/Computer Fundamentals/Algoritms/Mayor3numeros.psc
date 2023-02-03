Algoritmo MayorTresNumeros
	Escribir "Este programa dice cual es el mayor de 3 números"
	Escribir "Dame el primer número: "
	Leer n1
	Escribir "Dame el segundo número: "
	Leer n2
	Escribir "Dame el tercer número: "
	Leer n3
	Si n1>n2 Entonces
		Si n1>n3 Entonces
			Escribir "El mayor es el primer número: ",n1
		SiNo
			Si n3>n1 Entonces
				Escribir "El mayor es el tercer número: ", n3
			SiNo
				Escribir "El primer y tercer número son mayores: ",n1
			FinSi
		FinSi
	SiNo
		Si n2>n1 Entonces
			Si n2>n3 Entonces
				Escribir "El mayor es el segundo número: ",n2
			SiNo
				Si n3>n2 Entonces
					Escribir "El mayor es el tercer número: ",n3
				SiNo
					Escribir "El segundo y el tercer número son mayores: ",n2
				FinSi
			FinSi
		SiNo
			Si n1>n3 Entonces
				Escribir "El primer y segundo número son mayores: ",n1
			SiNo
				Si n3>n1 Entonces
					Escribir "El mayor es el tercer número: ",n3
				SiNo
					Escribir "Todos los números son iguales"
				FinSi
			FinSi
		FinSi
	FinSi
FinAlgoritmo
