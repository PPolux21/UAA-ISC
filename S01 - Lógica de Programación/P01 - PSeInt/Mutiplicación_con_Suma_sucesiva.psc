Algoritmo Mutiplicaci�n_con_Suma_sucesiva
	i=1
	mult=0
	Mostrar "Instroduce el n�mero que quieres multiplicar"
	Leer num1
	Mostrar "Introduce la cantidad de veces que quieres multiplicar el n�mero anterior"
	Leer num2
	Mientras i<=num2 Hacer
		mult=mult+num1
		i=i+1
	Fin Mientras
	Mostrar "El resultado de la multiplicaci�n fue: ", mult
FinAlgoritmo
