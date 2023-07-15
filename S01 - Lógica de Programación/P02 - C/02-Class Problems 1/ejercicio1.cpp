/*
Ejercicio 1
Espinoza Sánchez José Luis-280676-1°C
06/oct/2022
Obtener el factorial de un numero indicado por el usuario.
*/

#include <stdio.h>
 
int main(){
	
	int final=0, factorial=1;
	
	printf("Introduzca el numero para obtener su factorial: ");
	scanf("%d",&final);
 	
 	if(final>=0){
		for(int i=1;i<=final;i++){
 		
 			factorial=i*factorial;
 			
		}//for
		
		printf("El factorial de %d es %d",final, factorial);
		
	}else{
		
		printf("Numero no valido");
		
	}//if
}//main