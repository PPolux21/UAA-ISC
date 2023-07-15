Algoritmo Mutiplicación_con_Suma_sucesiva
	i=1
	mult=0
	Mostrar "Instroduce el número que quieres multiplicar"
	Leer num1
	Mostrar "Introduce la cantidad de veces que quieres multiplicar el número anterior"
	Leer num2
	Mientras i<=num2 Hacer
		mult=mult+num1
		i=i+1
	Fin Mientras
	Mostrar "El resultado de la multiplicación fue: ", mult
FinAlgoritmo
