Algoritmo Treinta_Cuadrados
	Para i=1 Hasta 30 Con Paso i+1 Hacer
		Mostrar "Introduce un número"
		Leer num
		Si num>=0 Entonces
			cuad=num*num
			Mostrar cuad
			sum=sum+cuad
		SiNo
			Mostrar "El número no es positivo, intenta otra vez con uno positivo"
			i=i-1
		Fin Si
	Fin Para
	Mostrar "La suma de los cuadrados es: ", sum
FinAlgoritmo
