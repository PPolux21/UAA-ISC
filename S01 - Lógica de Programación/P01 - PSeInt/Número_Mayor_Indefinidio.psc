Algoritmo N�mero_Mayor_Indefinidio
	i='s'
	Mostrar "Introduce un n�mero"
	Leer num
	Mientras i=='s' Hacer
		Mostrar "Introduce un n�mero"
		Leer comp
		Si num<comp Entonces
			num=comp
		Fin Si
		Mostrar "�Introducir otro n�mero?"
		Leer i
	Fin Mientras
	Mostrar num
FinAlgoritmo
