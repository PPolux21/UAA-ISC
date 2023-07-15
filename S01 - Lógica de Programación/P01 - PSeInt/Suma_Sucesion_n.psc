Algoritmo Suma_Sucesion_n
	Mostrar "Introduce en qué número de la sucesión parar"
	Leer lim
	Para i<-1 Hasta lim Con Paso i+1 Hacer
		Si i%2==0 Entonces
			sum=sum-(1/i)
		SiNo
			sum=sum+(1/i)			
		Fin Si
	Fin Para
	Mostrar "Suma de la sucesión: ", sum
FinAlgoritmo
