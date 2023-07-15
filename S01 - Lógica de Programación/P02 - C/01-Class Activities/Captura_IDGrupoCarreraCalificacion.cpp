/*
20/09/2022
Capturar datos entreros, caracter, real, y de tipo cadena
y mostrar esos datos en pantalla
*/
#include <stdio.h>
 
int main(){
 	int id;
 	char grupo;
 	float calif;
 	char carrera[15];
 	printf("Dame tu ID ");
	scanf("%d",&id);
	
	printf("Dame tu carrera ");
	scanf("%s",carrera);
	
	printf("Dame tu calificacion ");
	scanf("%f",&calif);
	
	fflush(stdin);
	printf("Dame tu grupo ");
	scanf("%c",&grupo);
	
	printf("Los datos capturados son \n");
	printf("El alumno con ID: %d que cursa la carrera: %s en el grupo: %c con el promedio de: %f",id,carrera,grupo,calif);
 }