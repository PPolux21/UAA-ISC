/*
Ejercicio 12
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Los pacientes con síntomas de una cierta enfermedad son ingresados en el hospital si tienen un valor superior a 0.6
en la medición de un determinado índice, y son operados si el valor es superior a 0.9. Escribir un programa en C que
lea desde teclado el número de pacientes seguido de la edad y el índice de cada paciente, y calcule la edad media de
los pacientes analizados, así como la edad media de los ingresados y la edad media de los operados
*/

#include <stdio.h>

int main()
{
	int pacientes,edad,promPaciente=0,ingresados=0,promIngresados=0,operados=0,promOperados=0;
	float indice;
	
	printf("Dame el numero de pacientes: ");
	scanf("%d",&pacientes);
	
	for(int i=1;i<=pacientes;i++)
	{
		printf("Dame tu edad: ");
		scanf("%d",&edad);
		printf("Dame tu indice: ");
		scanf("%f",&indice);
		
		promPaciente+=edad;
		
		if(indice>0.9)
		{
			promOperados+=edad;
			operados++;
		}
		else
		{
			if(indice>0.6)
			{
				promIngresados+=edad;
				ingresados++;
			}
		}
	}
	promIngresados/=ingresados;
	promOperados/=operados;
	promPaciente/=pacientes;
	
	printf("Promedio de edad de:\n \tTodos los pacientes: %d \n \tPacientes Ingresados: %d \n \tPacientes Operados: %d",promPaciente,promIngresados,promOperados);
}