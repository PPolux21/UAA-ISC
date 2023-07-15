/*
Ejercicio 13
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Escribir un programa que lea las edades de un grupo de personas hasta que se introduce un número negativo y
calcule:
	• La edad media.
	• La edad máxima.
	• La edad mínima.
	• El número de personas que están jubiladas.
	• Cuántos son menores de edad.
*/

#include <stdio.h>
#include <limits.h>//no me funcionaba el programa y quería agregar valores muy grandes y pequeños

int main()
{
	int valorUsuario,edadMedia=0,edadMax=INT_MIN,edadMin=INT_MAX,jubilados=0,menoresEdad=0,sumEdad=0,personas=0;
	
	do
	{
		printf("Introduce la edad: ");
		scanf("%d",&valorUsuario);
		
		if(valorUsuario>=0)
		{
			
			sumEdad+=valorUsuario;
			personas++;
			
			if(valorUsuario>edadMax)
			{
				edadMax=valorUsuario;
			}
		
			if(valorUsuario<edadMin)
			{
				edadMin=valorUsuario;
			}
			
			if(valorUsuario>=65)
			{
				jubilados++;
			}
			
			if(valorUsuario<18)
			{
				menoresEdad++;
			}
			
		}
	}while(valorUsuario>=0);
	
	edadMedia=sumEdad/personas;
	
	printf("Edad media: %d \nEdad maxima: %d \nEdad minima: %d \nPersonas jubiladas: %d \nMenores de edad: %d",edadMedia,edadMax,edadMin,jubilados,menoresEdad);
}