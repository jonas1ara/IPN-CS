Algoritmo Interpolacion
	Escribir 'Este programa calcula una interpolacion"
	Escribir 'Dime el año inicial: '
	Leer año1
	Escribir 'Dime la poblacion en ese año: '
	Leer poblacion1
	Escribir "Dime el año final: "
	Leer año2
	Escribir "Dime la poblacion en ese año: "
	Leer poblacion2
	Escribir "De que año quieres saber la poblacion"
	Leer año3
	razon = (poblacion2 - poblacion1) / (año2 - año1)
	poblacion3 = (razon*(año3-año1)) + poblacion1
	Escribir 'La poblacion en el año3 es: ',poblacion3
FinAlgoritmo
