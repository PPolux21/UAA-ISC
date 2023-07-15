/*
Ejercicio 13
Espinoza Sánchez José Luis-280676-1°C
08/oct/2022
Construya un programa tal que dado como datos la matricula de un alumno, la carrera en la que está inscrito,
su semestre y su promedio; determine si el mismo es apto para pertenecer a alguna de las facultades menores
que tiene la universidad. Si el alumno es aceptado teniendo en cuenta las especificaciones que se listan abajo,
se debe imprimir su matrícula, carrera y la palabra "aceptado"
*/

#include <stdio.h>

int main(){
	
	int matricula=0,carrera=0,semestre=0;
	float promedio=0;
	
	printf("Introduzca la matricula (an~o) en la que esta inscrito: ");
	scanf("%d",&matricula);
	printf("Introduzca la clave de carrera en la que esta inscrito: ");
	scanf("%d",&carrera);
	printf("Introduzca el semestre que actualmete cursa: ");
	scanf("%d",&semestre);
	printf("Introduzca su promedio del semestre: ");
	scanf("%f",&promedio);
	
	switch(carrera){
		case 1:	if(semestre>=6 && promedio>=8.8){
			printf("De la matrucula %d y carrera %d es aceptado");
			break;
		}
		case 2: if(semestre>6 && promedio>8.5){
			printf("De la matrucula %d y carrera %d es aceptado");
			break;
		}
		case 3: if(semestre>5 && promedio>8.5){
			printf("De la matrucula %d y carrera %d es aceptado");
			break;
		}
		case 4:	if(semestre>5 && promedio>8.5){
			printf("De la matrucula %d y carrera %d es aceptado");
			break;
		default:
			printf("Clave de carrera no valida");
			break;
		}
	}
}