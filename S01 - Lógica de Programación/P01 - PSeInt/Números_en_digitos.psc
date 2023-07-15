Algoritmo Números_en_digitos
	Mostrar "Dame un número"
	Leer num1
	Mientras num1>0 Hacer
		res=num1%10
		Mostrar res
		num1=(num1-res)/10
	Fin Mientras
FinAlgoritmo
