Algoritmo Comparación
	Escribir 'Dame un número'
	Leer num1
	Escribir 'Dame un número'
	Leer num2
	Escribir 'Dame un número'
	Leer num3
	Si num1=num2 Entonces
		Si num1=num3 Entonces
			Escribir 'Los 3 son iguales'
		SiNo
			Escribir num1,' y ',num2,' son iguales'
		FinSi
	SiNo
		Si num1>num2 Entonces
			Si num1>num3 Entonces
				Escribir num1,' es mayor'
			SiNo
				Si num1=num3 Entonces
					Escribir num1,' y ',num3,' son iguales'
				FinSi
			FinSi
		SiNo
			Si num3<>num2 Entonces
				Si num3>num2 Entonces
					Escribir num3,' es mayor'
				SiNo
					Escribir num2,' es mayor'
				FinSi
			SiNo
				Escribir num2,' y ',num3,' son iguales'
			FinSi
		FinSi
	FinSi
FinAlgoritmo
