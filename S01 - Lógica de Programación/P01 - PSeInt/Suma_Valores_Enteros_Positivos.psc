Algoritmo Suma_Valores_Enteros_Positivos
	i <- 's'
	Mientras i=='s' Hacer
		Escribir 'Introduce un número'
		Leer num
		Si (num MOD 1)==0 Entonces
			Si num>=0 Entonces
				sum <- sum+num
			FinSi
		SiNo
			Escribir 'Valor inválido'
		FinSi
		Escribir '¿Agregar otro número?'
		Leer i
	FinMientras
	Escribir 'La suma de los valores enteros positivos es: ',sum
FinAlgoritmo
