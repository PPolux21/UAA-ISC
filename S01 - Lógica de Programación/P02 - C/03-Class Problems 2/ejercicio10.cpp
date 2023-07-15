/*
Ejercicio 10
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Calcula la media de las notas de un conjunto de alumnos. 
La introducción de datos finaliza cuando el valor de la nota es –1.
*/

#include <stdio.h>

int main()
{
	int valorUsuario,sumNotas=0,promNotas=0,alumnos=0;
	
	do{
		printf("Introduce la nota del alumno: ");
		scanf("%d",&valorUsuario);
		if(valorUsuario>=0)
		{
			sumNotas+=valorUsuario;
			alumnos++;
		}
		
	}while(valorUsuario!=-1);
	
	promNotas=sumNotas/alumnos;
	
	printf("Promedio de %d alumnos es de: %d",alumnos,promNotas);
}