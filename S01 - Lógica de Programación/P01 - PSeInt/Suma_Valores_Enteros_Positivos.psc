Algoritmo Suma_Valores_Enteros_Positivos
	i <- 's'
	Mientras i=='s' Hacer
		Escribir 'Introduce un n�mero'
		Leer num
		Si (num MOD 1)==0 Entonces
			Si num>=0 Entonces
				sum <- sum+num
			FinSi
		SiNo
			Escribir 'Valor inv�lido'
		FinSi
		Escribir '�Agregar otro n�mero?'
		Leer i
	FinMientras
	Escribir 'La suma de los valores enteros positivos es: ',sum
FinAlgoritmo
