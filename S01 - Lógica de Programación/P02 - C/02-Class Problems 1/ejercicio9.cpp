/*
Ejercicio 9
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Un alumno de la materia de lógica de programación desea conocer su 
calificación final del curso, la cual se obtiene de la siguiente forma:
	1er parcial 25%
	2º parcial 25%
	Final 30%
	Proyecto 20%
*/

#include <stdio.h>

int main(){
	
	int parcialPrimero=0,parcialSegundo=0,final=0,proy=0,calif=0;
	
	printf("Introducir la calificacion del primer parcial (0-100): ");
	scanf("%d",&parcialPrimero);
	printf("Introducir la calificacion del segundo parcial (0-100): ");
	scanf("%d",&parcialSegundo);
	printf("Introducir la calificacion del final (0-100): ");
	scanf("%d",&final);
	printf("Introducir la calificacion del proyecto (0-100): ");
	scanf("%d",&proy);
	
	if(parcialPrimero>=0 && parcialPrimero<=100 && parcialSegundo>=0 && parcialSegundo<=100 && final>=0 && final<=100 && proy>=0 && proy<=100){
	
		calif=parcialPrimero*0.25+parcialSegundo*0.25+final*0.30+proy*0.20;
	
		printf("Calificacion final de la materia: %d",calif);
			
	}else{
		
		printf("Valores de califiacion no validos");
		
	}
}