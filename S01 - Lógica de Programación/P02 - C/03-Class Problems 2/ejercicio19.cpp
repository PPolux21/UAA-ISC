/*
Ejercicio 19
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Escribir un programa que lea las notas de 100 alumnos. Para cada uno se leen las calificaciones correspondientes a 7
asignaturas (numeradas del 1 al 7). Escribir la nota media del curso de cada alumno y de todos los alumnos.
*/

#include <stdio.h>
#define ALUMNOS 100
#define ASIGNATURAS 7

int main()
{
	int calif,sumCalif=0,promAlum=0,promTotal=0;
	
	for(int i=1;i<=ALUMNOS;i++)
	{
		sumCalif=0;
		for(int j=1;j<=ASIGNATURAS;j++)
		{
			printf("Dame la calificaion de la asignatura %d: ",j);
			scanf("%d",&calif);
			sumCalif+=calif;
		}
		promAlum=sumCalif/ASIGNATURAS;
		printf("Promedio del alumno %d: %d\n\n",i,promAlum);
		promTotal+=promAlum;
	}
	promTotal/=ALUMNOS;
	printf("Promedio general: %d",promTotal);
}