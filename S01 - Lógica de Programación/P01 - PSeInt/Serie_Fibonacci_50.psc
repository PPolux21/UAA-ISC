Algoritmo Serie_Fibonacci_50
	ant = 1
	sig = 1
	Mostrar sig
	Para i desde 1 hasta 50 
		res = ant + sig
		Mostrar res
		ant = sig
		sig = res
		i=i+1
	Fin Para
FinAlgoritmo
