Algoritmo Suma_Sucesion_n
	Mostrar "Introduce en qu� n�mero de la sucesi�n parar"
	Leer lim
	Para i<-1 Hasta lim Con Paso i+1 Hacer
		Si i%2==0 Entonces
			sum=sum-(1/i)
		SiNo
			sum=sum+(1/i)			
		Fin Si
	Fin Para
	Mostrar "Suma de la sucesi�n: ", sum
FinAlgoritmo
