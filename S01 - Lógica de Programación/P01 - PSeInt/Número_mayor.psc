Algoritmo N�mero_mayor
	Mostrar "Introduce la cantidad de n�meros que desea comparar"
	Leer j
	num2<-0
	Para i<-1 Hasta j Con Paso i+1 Hacer
		Mostrar "Introduce un valor para comparar"
		Leer num1
		Si num1>=num2 Entonces
			num2=num1
		Fin Si
	Fin Para
	Mostrar "El n�mero mayor fue: " num2
FinAlgoritmo
