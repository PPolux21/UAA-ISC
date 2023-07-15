Algoritmo Número_Mayor_Indefinidio
	i='s'
	Mostrar "Introduce un número"
	Leer num
	Mientras i=='s' Hacer
		Mostrar "Introduce un número"
		Leer comp
		Si num<comp Entonces
			num=comp
		Fin Si
		Mostrar "¿Introducir otro número?"
		Leer i
	Fin Mientras
	Mostrar num
FinAlgoritmo
